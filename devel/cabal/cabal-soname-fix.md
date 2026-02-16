# Fix: SONAME collision between locally-built and system GHC libraries

## Problem

Building matterhorn on OpenBSD/aarch64 failed during Template Haskell
evaluation with:

```
ghc-9.10.3:.../scientific-0.3.8.1/build/libHSscientific-0.3.8.1-inplace-ghc9.10.3.so:
  undefined symbol 'binaryzm0zi8zi9zi3zminplace_DataziBinaryziClass_zdfBinaryFixedzugo_closure'
```

## Root cause

The matterhorn port rebuilds `binary-0.8.9.3` from source (to get it
compiled against older pinned dependencies like `bytestring-0.11.5.4`).
The system GHC 9.10.3 ships its own `binary-0.8.9.3`.  Both produced
shared libraries with **the same SONAME**:
`libHSbinary-0.8.9.3-inplace-ghc9.10.3.so`.

The GHC executable itself links against the system copy (it's a
DT_NEEDED dependency loaded at startup into the global scope).  When GHC
later `dlopen()`s the locally-built copy with `RTLD_LOCAL` for TH
evaluation, and then loads `scientific.so`, the dynamic linker resolves
`scientific.so`'s DT_NEEDED for `libHSbinary-0.8.9.3-inplace-ghc9.10.3.so`
using the **already-loaded global copy** (the system one) rather than
the RTLD_LOCAL copy.  The system copy lacks symbols that the locally-built
`scientific.so` expects.

This is standard `ld.so` behavior: a globally-loaded library always takes
precedence over an RTLD_LOCAL one with the same SONAME.  Confirmed with
a minimal C test program on both amd64 and aarch64.

The build happened to succeed on amd64 by luck: GHC's x86_64 code
generator inlines the relevant function, so `scientific.so` never
references the missing symbol on that architecture.

## Why both copies had the same SONAME

`cabal.port.mk` listed all manifest dependencies as `packages:` entries
pointing to extracted source directories in `cabal.project.local`:

```
packages: /path/to/binary-0.8.9.3/binary.cabal
```

Cabal treats directory-based `packages:` entries as "local" packages and
assigns them the unit ID `binary-0.8.9.3-inplace`.  The system GHC's
boot library also uses `binary-0.8.9.3-inplace`.  The unit ID is
embedded in the SONAME, so both copies produce identical SONAMEs.

## Fix

Changed `cabal.port.mk` to reference dependencies as **tarball paths**
instead of extracted directories:

```
packages: /usr/ports/distfiles/hackage/binary-0.8.9.3.tar.gz
```

Cabal treats tarball-based `packages:` entries as store packages,
assigning them a hashed unit ID like
`binary-0.8.9.3-d16e1c9ecbb1b402...`.  This produces a distinct SONAME
(`libHSbinary-0.8.9.3-d16e1c9ecbb1b402...-ghc9.10.3.so`) that cannot
collide with the system copy.

For packages with `.cabal` file revisions, the tarball is repacked with
the revised `.cabal` file before being referenced.

The fix is a small change to the `.for` loop in `cabal.port.mk` and
applies to all Haskell ports built through this module.
