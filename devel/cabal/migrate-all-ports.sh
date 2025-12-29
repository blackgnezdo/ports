#!/bin/sh
#
# Migrate all cabal ports to use cabal-manifest.inc
#

set -e

PORTS_DIR="${1:-.}"
cd "$PORTS_DIR"

# Find all ports using devel/cabal module
CABAL_PORTS=$(grep -rl '^MODULES.*=.*devel/cabal' */*/Makefile | sed 's|/Makefile$||' | sort)

echo "Found cabal ports:"
echo "$CABAL_PORTS" | sed 's/^/  /'
echo ""

MIGRATE_SCRIPT="./devel/cabal/migrate-to-inc.sh"

if [ ! -x "$MIGRATE_SCRIPT" ]; then
	echo "Error: Migration script not found or not executable: $MIGRATE_SCRIPT" >&2
	exit 1
fi

SUCCESS=0
SKIPPED=0
FAILED=0

for port in $CABAL_PORTS; do
	echo "==> Migrating $port"
	if [ -f "$port/cabal-manifest.inc" ]; then
		echo "    Already migrated (skipped)"
		SKIPPED=$((SKIPPED + 1))
		continue
	fi

	if "$MIGRATE_SCRIPT" "$port"; then
		SUCCESS=$((SUCCESS + 1))
	else
		echo "    FAILED to migrate $port" >&2
		FAILED=$((FAILED + 1))
	fi
	echo ""
done

echo "==== Migration Summary ===="
echo "Success: $SUCCESS"
echo "Skipped: $SKIPPED"
echo "Failed:  $FAILED"

if [ $FAILED -gt 0 ]; then
	exit 1
fi
