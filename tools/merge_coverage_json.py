# tools/merge_coverage_json.py

import sys
import json
from collections import defaultdict


def main(dst_json: str, *src_jsons: str) -> None:
    merged = defaultdict(lambda: defaultdict(int))

    for path in src_jsons:
        with open(path) as f:
            data = json.load(f)

        for cp, bins in data.items():
            for b, hits in bins.items():
                merged[cp][b] += hits

    # Convert back to normal dicts
    out = {cp: dict(bins) for cp, bins in merged.items()}

    with open(dst_json, "w") as f:
        json.dump(out, f, indent=2)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: merge_coverage_json.py <dst.json> <src1.json> [src2.json ...]")
        sys.exit(1)
    main(sys.argv[1], *sys.argv[2:])
