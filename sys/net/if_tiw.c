/*	$OpenBSD$	*/

/*
 * Copyright (c) 2020 Anton Lindqvist <anton@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/proc.h>
#include <sys/vnode.h>

#include <net/if.h>
#include <net/if_media.h>
#include <net/rtable.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

#include <net80211/ieee80211_var.h>

#define TIW_STAYUP	0x00000001u

struct tiw_softc {
	struct ieee80211com sc_ic;
	int sc_unit;
	int sc_flags;
	dev_t sc_dev;

	TAILQ_ENTRY(tiw_softc) sc_entry;
};

void tiwattach(int);

int tiw_clone_create(struct if_clone *, int);
int tiw_clone_destroy(struct ifnet *);

int tiw_enqueue(struct ifnet *, struct mbuf *);
int tiw_ioctl(struct ifnet *, u_long, caddr_t);
void tiw_start(struct ifnet *);

struct tiw_softc *tiw_lookup(int);

TAILQ_HEAD(, tiw_softc) tiw_list = TAILQ_HEAD_INITIALIZER(tiw_list);

struct if_clone tiw_cloner = IF_CLONE_INITIALIZER(
    "tiw", tiw_clone_create, tiw_clone_destroy);

void
tiwattach(int count)
{
	printf("%s\n", __func__);
	if_clone_attach(&tiw_cloner);
}

int
tiwopen(dev_t dev, int flag, int mode, struct proc *p)
{
	printf("%s\n", __func__);
	char name[IFNAMSIZ];
	struct tiw_softc *sc;
	unsigned int rdomain;
	int error;

	sc = tiw_lookup(minor(dev));
	if (sc != NULL) {
		if (sc->sc_dev != 0)
			return EBUSY;
		sc->sc_dev = dev;
		return 0;
	}

	snprintf(name, sizeof(name), "%s%u", tiw_cloner.ifc_name, minor(dev));
	rdomain = rtable_l2(p->p_p->ps_rtableid);
	error = if_clone_create(name, rdomain);
	if (error)
		return error;

	sc = tiw_lookup(minor(dev));
	KASSERT(sc != NULL);
	if (sc->sc_dev != 0)
		return EBUSY;
	/* Device created by open, it should be destroyed upon close. */
	CLR(sc->sc_flags, TIW_STAYUP);
	return 0;
}

int
tiwclose(dev_t dev, int flag, int mode, struct proc *p)
{
	printf("%s\n", __func__);
	char name[IFNAMSIZ];
	struct ifnet *ifp;
	struct tiw_softc *sc;

	sc = tiw_lookup(minor(dev));
	if (sc == NULL)
		return ENXIO;
	sc->sc_dev = 0;
	if (ISSET(sc->sc_flags, TIW_STAYUP))
		return 0;
	ifp = &sc->sc_ic.ic_if;
	strlcpy(name, ifp->if_xname, sizeof(name));
	return if_clone_destroy(name);
}

int
tiwread(dev_t dev, struct uio *uio, int ioflag)
{
	printf("%s\n", __func__);
	return ENODEV;
}

int
tiwwrite(dev_t dev, struct uio *uio, int ioflag)
{
	printf("%s\n", __func__);
	return ENODEV;
}

int
tiwioctl(dev_t dev, u_long cmd, caddr_t data, int flag, struct proc *p)
{
	printf("%s\n", __func__);
	struct tiw_softc *sc;

	sc = tiw_lookup(minor(dev));
	if (sc == NULL)
		return ENXIO;
	return tiw_ioctl(&sc->sc_ic.ic_if, cmd, data);
}

int
tiw_clone_create(struct if_clone *ifc, int unit)
{
	printf("%s\n", __func__);
	struct ieee80211com *ic;
	struct ifnet *ifp;
	struct tiw_softc *sc;

	sc = malloc(sizeof(*sc), M_DEVBUF, M_WAITOK | M_ZERO);
	if (tiw_lookup(unit) != NULL) {
		free(sc, M_DEVBUF, sizeof(*sc));
		return EEXIST;
	}

	sc->sc_unit = unit;
	sc->sc_flags = TIW_STAYUP;
	TAILQ_INSERT_TAIL(&tiw_list, sc, sc_entry);

	ifp = &sc->sc_ic.ic_if;
	snprintf(ifp->if_xname, sizeof(ifp->if_xname), "%s%d",
	    ifc->ifc_name, unit);
	ifp->if_softc = sc;
	ifp->if_ioctl = tiw_ioctl;
	ifp->if_enqueue = tiw_enqueue;
	ifp->if_start = tiw_start;
	ifp->if_hardmtu = 0;	/* XXX */
	ifp->if_link_state = LINK_STATE_DOWN;

	ic = &sc->sc_ic;
	ic->ic_opmode = IEEE80211_M_STA;

#if 0 /* XXX */
	if_counters_alloc(ifp);
#endif
	if_attach(ifp);
	if_alloc_sadl(ifp);
	ieee80211_ifattach(ifp);

#if 0 /* XXX */
	sc->sc_newstate = ic->ic_newstate;
	ic->ic_newstate = tiw_newstate;
#endif

	ieee80211_media_init(ifp, ieee80211_media_change,
	    ieee80211_media_status);

	return 0;
}

int
tiw_clone_destroy(struct ifnet *ifp)
{
	printf("%s\n", __func__);
	struct tiw_softc *sc = ifp->if_softc;

	if (sc->sc_dev != 0) {
		struct vnode *vp;

		if (vfinddev(sc->sc_dev, VCHR, &vp))
			VOP_REVOKE(vp, REVOKEALL);
		KASSERT(sc->sc_dev == 0);
	}

	CLR(ifp->if_flags, IFF_UP | IFF_RUNNING);
	ifq_purge(&ifp->if_snd);
	if_detach(ifp);
	TAILQ_REMOVE(&tiw_list, sc, sc_entry);
	free(sc, M_DEVBUF, sizeof(*sc));
	return 0;
}

int
tiw_enqueue(struct ifnet *ifp, struct mbuf *m0)
{
	printf("%s\n", __func__);
	return EINVAL;
}

int
tiw_ioctl(struct ifnet *ifp, u_long cmd, caddr_t data)
{
	printf("%s\n", __func__);
	return ieee80211_ioctl(ifp, cmd, data);
}

void
tiw_start(struct ifnet *ifp)
{
	printf("%s\n", __func__);
}

struct tiw_softc *
tiw_lookup(int unit)
{
	struct tiw_softc *sc;

	TAILQ_FOREACH(sc, &tiw_list, sc_entry) {
		if (sc->sc_unit == unit)
			return sc;
	}
	return NULL;
}
