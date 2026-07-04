# tools/print_functional_summary.py

import json
import sys

GREEN = "\033[92m"
YELLOW = "\033[93m"
RED = "\033[91m"
RESET = "\033[0m"

def main(path):
    with open(path) as f:
        cov = json.load(f)

    print("\n=== Functional Coverage Summary ===\n")

    for cp, bins in cov.items():
        total = len(bins)
        hit = sum(1 for h in bins.values() if h > 0)
        pct = (hit / total * 100.0) if total else 0.0

        if pct == 100:
            color = GREEN
        elif pct >= 50:
            color = YELLOW
        else:
            color = RED

        print(f"{color}{cp}: {hit}/{total} bins hit ({pct:.1f}%) {RESET}")

    print("")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: print_functional_summary.py <merged.json>")
        sys.exit(1)
    main(sys.argv[1])
