#!/bin/sh
#
# Update all cabal ports to latest versions
#
# Usage: update-all-cabal-ports.sh [options]
#
# Options:
#   --package          Run 'make package' for each port (slow!)
#   --continue         Continue from last port (uses .update-progress file)
#   --git-commit       Create git commit for each successful update
#   --help             Show this help message
#

set -e

usage() {
	sed -n '2,/^$/s/^# \?//p' < "$0"
	exit "${1:-0}"
}

RUN_PACKAGE=0
GIT_COMMIT=0
CONTINUE=0

while [ $# -gt 0 ]; do
	case "$1" in
		--package)     RUN_PACKAGE=1; shift ;;
		--git-commit)  GIT_COMMIT=1; shift ;;
		--continue)    CONTINUE=1; shift ;;
		--help|-h)     usage 0 ;;
		*)             echo "Unknown option: $1" >&2; usage 1 ;;
	esac
done

PORTS_DIR="$(pwd)"
UPDATE_SCRIPT="$PORTS_DIR/devel/cabal/tools/update-cabal-port.pl"

if [ ! -x "$UPDATE_SCRIPT" ]; then
	echo "Error: Update script not found: $UPDATE_SCRIPT" >&2
	exit 1
fi

echo "==> Finding cabal ports..."
CABAL_PORTS=$(grep -rl '^MODULES.*=.*devel/cabal' ./*/*/Makefile | sed 's|/Makefile$||' | sort)
TOTAL=$(echo "$CABAL_PORTS" | wc -l | tr -d ' ')

echo "Found $TOTAL cabal ports:"
echo "$CABAL_PORTS" | sed 's/^/  /'
echo ""

PROGRESS_FILE=".update-progress"
LAST_PORT=""
if [ $CONTINUE -eq 1 ] && [ -f "$PROGRESS_FILE" ]; then
	LAST_PORT=$(cat "$PROGRESS_FILE")
	echo "==> Continuing from: $LAST_PORT"
fi

SUCCESS=0
SKIPPED=0
FAILED=0
CURRENT=0
SKIP_UNTIL_FOUND=0
[ -n "$LAST_PORT" ] && SKIP_UNTIL_FOUND=1

for port in $CABAL_PORTS; do
	CURRENT=$((CURRENT + 1))

	if [ $SKIP_UNTIL_FOUND -eq 1 ]; then
		if [ "$port" = "$LAST_PORT" ]; then
			SKIP_UNTIL_FOUND=0
		else
			SKIPPED=$((SKIPPED + 1))
			continue
		fi
	fi

	echo "===================================================================="
	echo "==> [$CURRENT/$TOTAL] Processing: $port"
	echo "===================================================================="

	echo "$port" > "$PROGRESS_FILE"

	UPDATE_CMD="$UPDATE_SCRIPT $port"
	[ $RUN_PACKAGE -eq 1 ] && UPDATE_CMD="$UPDATE_CMD --package"

	if $UPDATE_CMD; then
		cd "$port"
		if git diff --quiet Makefile cabal.inc 2>/dev/null; then
			echo "==> No changes for $port"
			SKIPPED=$((SKIPPED + 1))
		else
			echo "==> Updated $port"
			SUCCESS=$((SUCCESS + 1))

			if [ $GIT_COMMIT -eq 1 ]; then
				NEW_VERSION=$(awk '/^MODCABAL_VERSION[[:space:]]*=/ {print $3}' Makefile)
				git add Makefile cabal.inc distinfo 2>/dev/null || true
				git commit -m "Update $port to $NEW_VERSION" || true
			fi
		fi
		cd "$PORTS_DIR"
	else
		echo "==> FAILED: $port" >&2
		FAILED=$((FAILED + 1))
		cd "$PORTS_DIR"

		printf "Continue? [Y/n] "
		read -r response
		case "$response" in
			[nN]*) echo "Stopping"; break ;;
		esac
	fi
	echo ""
done

rm -f "$PROGRESS_FILE"

echo "========================================================================"
echo "==> Summary: $SUCCESS updated, $SKIPPED skipped, $FAILED failed"
echo "========================================================================"

[ $FAILED -gt 0 ] && exit 1
exit 0
