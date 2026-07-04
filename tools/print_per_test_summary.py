# tools/print_per_test_summary.py

import json
import sys
import glob

GREEN = "\033[92m"
YELLOW = "\033[93m"
RED = "\033[91m"
RESET = "\033[0m"

def summarize(path):
    with open(path) as f:
        cov = json.load(f)

    total_bins = 0
    hit_bins = 0

    for cp, bins in cov.items():
        total_bins += len(bins)
        hit_bins += sum(1 for h in bins.values() if h > 0)

    pct = (hit_bins / total_bins * 100.0) if total_bins else 0.0

    if pct == 100:
        color = GREEN
    elif pct >= 50:
        color = YELLOW
    else:
        color = RED

    return f"{color}{pct:.1f}%{RESET}"

def main():
    files = sorted(glob.glob("regression_results/coverage_*.json"))

    print("\n=== Per‑Test Functional Coverage ===\n")

    for f in files:
        test_num = f.split("_")[-1].split(".")[0]
        pct = summarize(f)
        print(f"Test {test_num}: {pct}")

    print("")

if __name__ == "__main__":
    main()
