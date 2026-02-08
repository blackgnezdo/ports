# Upgrading GHC on OpenBSD

This document describes the process for upgrading the GHC port to a new version.
It was written during the upgrade from GHC 9.8.3 to 9.10.3.

## Overview

GHC requires bootstrapping - you need an existing GHC to build a new GHC.
The OpenBSD port uses pre-built bootstrap binaries hosted on openbsd.dead-parrot.de.

The upgrade process has two phases:
1. **Initial build** using the old bootstrap binaries
2. **Generate new bootstrap** artifacts for the new version

## Prerequisites

- OpenBSD -current (or release matching ports tree)
- At least 8GB RAM recommended (5GB minimum with swap)
- At least 10GB free disk space on /usr/obj
- Network access for fetching sources and Hackage packages (during initial bootstrap)

## Step 1: Update Version Numbers in Makefile

Update `GHC_VERSION`:
```make
GHC_VERSION =		9.10.3
```

Keep `BIN_VER` pointing to the OLD version initially (for bootstrapping):
```make
BIN_VER =		9.8.3.20250914
```

## Step 2: Update Library Versions

GHC bundles many libraries. Get the versions from the new GHC source:

```sh
# Download and extract GHC source
cd /tmp
ftp https://downloads.haskell.org/ghc/9.10.3/ghc-9.10.3-src.tar.xz
tar xf ghc-9.10.3-src.tar.xz
cd ghc-9.10.3

# Extract versions from cabal files
for lib in libraries/*/; do
    cabal=$(find "$lib" -maxdepth 1 -name "*.cabal" | head -1)
    [ -f "$cabal" ] && grep -E "^version:" "$cabal" | head -1
done
```

Key libraries that changed from 9.8.3 to 9.10.3:
- BASE: 4.19.2.0 → 4.20.2.0
- BINARY: 0.8.9.1 → 0.8.9.3
- BYTESTRING: 0.12.1.0 → 0.12.2.0
- CABAL: 3.10.3.0 → 3.12.1.0
- CONTAINERS: 0.6.8 → 0.7
- EXCEPTIONS: 0.10.7 → 0.10.9
- FILEPATH: 1.4.200.1 → 1.5.4.0
- GHC: 9.8.3 → 9.10.3
- GHC_PRIM: 0.10.0 → 0.12.0
- HPC: 0.7.0.0 → 0.7.0.2
- PARSEC: 3.1.17.0 → 3.1.18.0
- PROCESS: 1.6.25.0 → 1.6.26.1
- TEMPLATE_HASKELL: 2.21.0.0 → 2.22.0.0
- TERMINFO: 0.4.1.6 → 0.4.1.7
- TEXT: 2.1.1 → 2.1.3
- TRANSFORMERS: 0.6.1.0 → 0.6.1.1
- UNIX: 2.8.4.0 → 2.8.7.0

New libraries added in 9.10:
- GHC_INTERNAL: 9.10.3.0
- OS_STRING: 2.0.7

## Step 3: Update distinfo

Generate SHA256 checksums in base64 format:

```sh
cd /usr/ports/lang/ghc
make makesum
```

## Step 4: Update Patches

Check if existing patches apply to the new version:

```sh
cd /usr/ports/lang/ghc
make patch  # This will show which patches fail
```

### Patches for 9.10.3

1. **patch-compiler_GHC_Unit_State_hs**
   - Workaround for https://gitlab.haskell.org/ghc/ghc/-/issues/20287
   - Uses $topdir/include to find DerivedConstants.h
   - Line numbers may need adjustment (was @670, check new location)

2. **patch-hadrian_bootstrap_bootstrap_py**
   - Disables version check for builtin packages during bootstrap
   - Required because bootstrap GHC has different package versions

3. **patch-hadrian_hadrian_cabal**
   - Removes `-qg` RTS option incompatible with older runtime
   - May not be needed if bootstrap GHC is recent enough

4. **patch-libraries_Cabal_Cabal_src_Distribution_Simple_Program_Strip_hs**
   - Prevents strip --strip-unneeded on OpenBSD (strips too much)
   - Add OpenBSD case alongside existing Solaris/AIX/etc cases

5. **patch-testsuite_driver_testlib_py**
   - Strips OpenBSD linker warnings about strcpy/sprintf
   - Uses `diff -a` flag for binary-safe diff on OpenBSD

6. **patch-testsuite_tests_codeGen_should_run_all_T**
   - Increases stack size for T3677 test (8k → 10k)

## Step 5: Handle Hadrian Bootstrap Changes

GHC 9.10 introduces new packages required by hadrian:
- `ghc-platform` (in libraries/ghc-platform/)
- `ghc-toolchain` (in utils/ghc-toolchain/)

These are LOCAL packages built from the GHC source tree, not from Hackage.
The bootstrap.py script handles this automatically when using the plan file
from the source tree.

For initial bootstrap with old GHC, modify post-patch to use the plan file:

```make
# Build hadrian using plan file (downloads deps, builds local packages)
cd ${WRKSRC} && \
${MODPY_BIN} hadrian/bootstrap/bootstrap.py --no-archive -w ../bin/ghc \
    -d hadrian/bootstrap/plan-bootstrap-9_8_2.json
```

After generating new bootstrap artifacts, switch back to using hadrian-sources tarball:
```make
# Build hadrian from pre-fetched sources (hermetic, no network)
cd ${WRKSRC} && \
${MODPY_BIN} hadrian/bootstrap/bootstrap.py --no-archive -w ../bin/ghc \
    -s ${FULLDISTDIR}/hadrian-sources-${BIN_VER}.tar.gz
```

## Step 6: Build

```sh
cd /usr/ports/lang/ghc
ulimit -d $((10<<20))
MAKE_JOBS=10 make build 2>&1 | tee build.log
```

Build stages:
1. **Extract & Patch** - Unpacks sources, applies patches
2. **Bootstrap Install** - Installs bootstrap GHC to ${WRKDIR}/bootstrap
3. **Hadrian Bootstrap** - Builds hadrian build system
4. **Stage 0** - Builds libraries and compiler with bootstrap GHC (~1500 .o files)
5. **Stage 1** - Builds libraries and compiler with stage0 GHC (~2000+ .o files)
6. **Binary Dist** - Creates distributable binary package

Expect about one hour on a modern machine with `MAKE_JOBS=10`. Parallel builds need more RAM.

## Step 7: Generate Bootstrap Artifacts

After successful build, bootstrap requires the normal build to be cleaned out:

```sh
cd /usr/ports/lang/ghc
make clean
make bootstrap
```

Update `BOOTSTRAP_DATE` in Makefile to the current date.

This generates:
- `ghc-9.10.3.YYYYMMDD-amd64.tar.xz` - Bootstrap compiler
- `ghc-9.10.3.YYYYMMDD-shlibs-amd64.tar.gz` - Required shared libraries
- `hadrian-sources-9.10.3.YYYYMMDD.tar.gz` - Hadrian dependencies

**IMPORTANT**: The hadrian-sources tarball generated by `make bootstrap` uses
`plan-bootstrap-9_8_2.json` which has 9.8.x builtin library expectations. This
tarball will NOT work with the new 9.10.x bootstrap because the builtin library
versions don't match. You must generate a new plan file - see Step 7a below.

Use the last lines of the output of `make bootstrap` to update `distinfo`.

## Step 7a: Generate Plan File for New GHC Version

The hadrian bootstrap plan file specifies which builtin packages (from GHC) and
which Hackage packages are needed. When upgrading to a new major GHC version,
you need a plan file that matches the new GHC's builtin library versions.

The GHC source includes plan files in `hadrian/bootstrap/` but only for older
versions. Without Nix, generate a new plan manually:

### Prerequisites
Install the new GHC version first (from the successful build in Step 6):
```sh
cd /usr/ports/lang/ghc
make install  # or make fake && make package && pkg_add
```

### Generate Compatible Package Versions
```sh
# Set up a work directory with the required structure
cd /tmp
mkdir -p ghc-plan/libraries ghc-plan/utils
cp -r /usr/ports/pobj/ghc-9.10.3/ghc-9.10.3/hadrian ghc-plan/
cp -r /usr/ports/pobj/ghc-9.10.3/ghc-9.10.3/libraries/ghc-platform ghc-plan/libraries/
cp -r /usr/ports/pobj/ghc-9.10.3/ghc-9.10.3/utils/ghc-toolchain ghc-plan/utils/

# Create cabal.project
cd /tmp/ghc-plan
cat > cabal.project << 'EOF'
packages: hadrian/
          utils/ghc-toolchain/
          libraries/ghc-platform/
index-state: 2025-02-03T15:14:19Z
allow-newer: unordered-containers:template-haskell
EOF

# Get the package versions cabal would use
cabal build --dry-run hadrian --flags=-selftest -w /usr/local/bin/ghc
```

### Create the Plan File
Start with an existing plan file and update it:

1. Get GHC's builtin package versions:
```sh
ghc-pkg list --global
```

2. Update the "builtin" section in the plan to match these versions

3. Update the "dependencies" section with compatible Hackage package versions
   from the cabal dry-run output. Key packages that often need updating:
   - extra, hashable, heaps, primitive, splitmix, random, unordered-containers, shake

4. For each updated Hackage package, fetch the SHA256 hashes:
```sh
# Source tarball hash
ftp -o - https://hackage.haskell.org/package/PKG-VER/PKG-VER.tar.gz | sha256
# Cabal revision hash (check revision number at hackage.haskell.org)
ftp -o - https://hackage.haskell.org/package/PKG-VER/revision/N.cabal | sha256
```

### Test and Create Tarball
```sh
cd /tmp/ghc-plan

# Fetch sources with new plan
python3 hadrian/bootstrap/bootstrap.py -w /usr/local/bin/ghc \
    -d /usr/ports/lang/ghc/files/plan-openbsd.json fetch \
	-o /tmp/hadrian-sources-9.10.3

# Test building hadrian (should complete without errors)
rm -rf _build
python3 hadrian/bootstrap/bootstrap.py -w /usr/local/bin/ghc \
    -s /tmp/hadrian-sources-9.10.3.tar.gz

# If successful, copy to distfiles
doas cp /tmp/hadrian-sources-9.10.3.tar.gz \
    /usr/ports/distfiles/ghc/hadrian-sources-9.10.3.YYYYMMDD.tar.gz
```

NB: we record the working plan-openbsd.json in the source for
regenerating the hadrian bootstrap. While this may not be absolutely
necessary, it's good to get all the artifacts in one go when
re-bootstrapping. The alternative is to keep the one and only hadrian
archive for the duration of using the given release. It should also
work.

## Step 8: Update for Hermetic Build

1. Copy bootstrap artifacts from `lang/ghc` to $DISTDIR/ghc to skip
   the roundtrip through external distfiles mirror.

2. Update Makefile to the `BOOTSTRAP_DATE` used above.
   ```make
   BIN_VER =		9.10.3.20260203
   ```

3. Confirm distinfo is fine with new checksums recorded above:
   ```sh
   make checksum
   ```

4. Switch hadrian bootstrap back to tarball:
   ```make
   ${MODPY_BIN} hadrian/bootstrap/bootstrap.py --no-archive -w ../bin/ghc \
       -s ${FULLDISTDIR}/hadrian-sources-${BIN_VER}.tar.gz
   ```

## Step 9: Test

Again, gotta `make clean` as we just built a bootstrap.

```sh
cd /usr/ports/lang/ghc
make clean
make test
```

## Step 10: Update PLIST

If successful, regenerate the package list:

```sh
make update-plist
```

## Troubleshooting

### Out of Memory
- Reduce MAKE_JOBS to 1
- Add swap space
- Use release+no_profiled_libs flavour for bootstrap

### Out of Disk Space
- Need ~10GB on /usr/ports/pobj
- Can remove stage0 after stage1 compiler is built
- Clean distfiles after extraction

### Patch Failures
- Check line numbers in source files
- Use `make update-patches` after manual fixes

### Hadrian Bootstrap Fails
- Check that plan file matches bootstrap GHC version
- Ensure network access for Hackage downloads (initial build only)
- ghc-platform/ghc-toolchain are local packages, not from Hackage

### Hadrian Bootstrap Fails with "Using ghc-boot-th-X.Y.Z from GHC" Mismatch
This happens when the hadrian-sources tarball was created with a plan file
for a different GHC version. The plan's "builtin" section must match the
bootstrap GHC's actual library versions. See Step 7a for creating a new plan.

Example error: plan expects `base-4.19.1.0` but bootstrap GHC has `base-4.20.2.0`

## References

- GHC User's Guide: https://downloads.haskell.org/ghc/9.10.3/docs/users_guide/
- GHC GitLab: https://gitlab.haskell.org/ghc/ghc
- Hadrian documentation: https://gitlab.haskell.org/ghc/ghc/-/tree/master/hadrian
- OpenBSD ports guide: https://www.openbsd.org/faq/ports/
