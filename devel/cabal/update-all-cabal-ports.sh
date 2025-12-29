#!/bin/sh
#
# Update all cabal ports to latest versions
#
# Usage: update-all-cabal-ports.sh [options]
#
# Options:
#   --dry-run          Show what would be done without making changes
#   --no-makesum       Skip running 'make makesum' for each port
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

# Parse arguments
DRY_RUN=0
RUN_MAKESUM=1
RUN_PACKAGE=0
GIT_COMMIT=0
CONTINUE=0

while [ $# -gt 0 ]; do
	case "$1" in
		--dry-run)
			DRY_RUN=1
			shift
			;;
		--no-makesum)
			RUN_MAKESUM=0
			shift
			;;
		--package)
			RUN_PACKAGE=1
			shift
			;;
		--git-commit)
			GIT_COMMIT=1
			shift
			;;
		--continue)
			CONTINUE=1
			shift
			;;
		--help|-h)
			usage 0
			;;
		*)
			echo "Unknown option: $1" >&2
			usage 1
			;;
	esac
done

PORTS_DIR="."
cd "$PORTS_DIR"

UPDATE_SCRIPT="./devel/cabal/update-cabal-port.sh"

if [ ! -x "$UPDATE_SCRIPT" ]; then
	echo "Error: Update script not found or not executable: $UPDATE_SCRIPT" >&2
	exit 1
fi

# Find all ports using devel/cabal module
echo "==> Finding cabal ports..."
CABAL_PORTS=$(grep -rl '^MODULES.*=.*devel/cabal' */*/Makefile | sed 's|/Makefile$||' | sort)
TOTAL=$(echo "$CABAL_PORTS" | wc -l | tr -d ' ')

echo "Found $TOTAL cabal ports:"
echo "$CABAL_PORTS" | sed 's/^/  /'
echo ""

# Check for progress file if --continue specified
PROGRESS_FILE=".update-progress"
LAST_PORT=""
if [ $CONTINUE -eq 1 ] && [ -f "$PROGRESS_FILE" ]; then
	LAST_PORT=$(cat "$PROGRESS_FILE")
	echo "==> Continuing from last port: $LAST_PORT"
	echo ""
fi

SUCCESS=0
SKIPPED=0
FAILED=0
CURRENT=0

SKIP_UNTIL_FOUND=0
if [ -n "$LAST_PORT" ]; then
	SKIP_UNTIL_FOUND=1
fi

for port in $CABAL_PORTS; do
	CURRENT=$((CURRENT + 1))

	# Skip until we find the last processed port
	if [ $SKIP_UNTIL_FOUND -eq 1 ]; then
		if [ "$port" = "$LAST_PORT" ]; then
			SKIP_UNTIL_FOUND=0
			echo "==> Resuming from: $port"
		else
			SKIPPED=$((SKIPPED + 1))
			continue
		fi
	fi

	echo "===================================================================="
	echo "==> [$CURRENT/$TOTAL] Processing: $port"
	echo "===================================================================="
	echo ""

	# Save progress
	echo "$port" > "$PROGRESS_FILE"

	# Build update command
	UPDATE_CMD="$UPDATE_SCRIPT $port"
	[ $DRY_RUN -eq 1 ] && UPDATE_CMD="$UPDATE_CMD --dry-run"
	[ $RUN_MAKESUM -eq 0 ] && UPDATE_CMD="$UPDATE_CMD --no-makesum"
	[ $RUN_PACKAGE -eq 1 ] && UPDATE_CMD="$UPDATE_CMD --package"

	# Run update
	if $UPDATE_CMD; then
		# Check if there was an actual update
		cd "$port"
		if git diff --quiet Makefile cabal-manifest.inc 2>/dev/null; then
			echo "==> No changes for $port (already up to date)"
			SKIPPED=$((SKIPPED + 1))
		else
			echo "==> Successfully updated $port"
			SUCCESS=$((SUCCESS + 1))

			# Create git commit if requested
			if [ $GIT_COMMIT -eq 1 ] && [ $DRY_RUN -eq 0 ]; then
				NEW_VERSION=$(awk '/^MODCABAL_VERSION[[:space:]]*=/ {print $3}' Makefile)
				PORT_NAME=$(basename "$port")

				echo "==> Creating git commit..."
				git add Makefile cabal-manifest.inc distinfo 2>/dev/null || true

				COMMIT_MSG="Update $port to $NEW_VERSION

Automated update using cabal-bundler."

				if git commit -m "$COMMIT_MSG"; then
					echo "    Committed successfully"
				else
					echo "    Warning: git commit failed or no changes staged"
				fi
			fi
		fi
		cd "$PORTS_DIR"
	else
		echo "==> FAILED to update $port" >&2
		FAILED=$((FAILED + 1))
		cd "$PORTS_DIR"

		# Ask whether to continue
		if [ $DRY_RUN -eq 0 ]; then
			echo ""
			echo "Continue with next port? [Y/n] "
			read -r response
			case "$response" in
				[nN]|[nN][oO])
					echo "Stopping at user request"
					break
					;;
			esac
		fi
	fi

	echo ""
done

# Clean up progress file on completion
rm -f "$PROGRESS_FILE"

echo "========================================================================"
echo "==> Update Summary"
echo "========================================================================"
echo "Total ports:     $TOTAL"
echo "Successfully updated: $SUCCESS"
echo "Skipped (already up to date): $SKIPPED"
echo "Failed:          $FAILED"
echo ""

if [ $FAILED -gt 0 ]; then
	echo "Some ports failed to update. Review the output above for details."
	exit 1
fi

echo "All ports processed successfully!"

if [ $GIT_COMMIT -eq 1 ] && [ $SUCCESS -gt 0 ]; then
	echo ""
	echo "Created $SUCCESS git commits."
	echo "Review with: git log --oneline -$SUCCESS"
fi
