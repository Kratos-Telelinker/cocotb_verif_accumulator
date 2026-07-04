#!/usr/bin/env python

import sys
import csv
import matplotlib.pyplot as plt

from collections import defaultdict

def main(filename="stimulus_log.csv"):
    by_channel_a = defaultdict(list)
    by_channel_b = defaultdict(list)

    with open(filename, newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            ch = row["channel"]
            a = int(row["a"])
            b = int(row["b"])
            if ch == "A":
                by_channel_a["a"].append(a)
                by_channel_a["b"].append(b)
            else:
                by_channel_b["a"].append(a)
                by_channel_b["b"].append(b)

    fig, axes = plt.subplots(2, 2, figsize=(10, 8))
    axes[0,0].hist(by_channel_a["a"], bins=32, color="blue", alpha=0.7)
    axes[0,0].set_title("Channel A - a distribution")
    axes[0,1].hist(by_channel_a["b"], bins=32, color="green", alpha=0.7)
    axes[0,1].set_title("Channel A - b distribution")
    axes[1,0].hist(by_channel_b["a"], bins=32, color="red", alpha=0.7)
    axes[1,0].set_title("Channel B - a distribution")
    axes[1,1].hist(by_channel_b["b"], bins=32, color="orange", alpha=0.7)
    axes[1,1].set_title("Channel B - b distribution")

    for ax in axes.flat:
        ax.set_xlabel("Value")
        ax.set_ylabel("Count")

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    fname = sys.argv[1] if len(sys.argv) > 1 else "stimulus_log.csv"
    main(fname)
