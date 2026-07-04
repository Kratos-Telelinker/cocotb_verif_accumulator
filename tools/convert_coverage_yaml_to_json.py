# tools/convert_coverage_yaml_to_json.py

# tools/convert_coverage_yaml_to_json.py

import sys
import yaml
import json

def main(src_yaml: str, dst_json: str) -> None:
    with open(src_yaml) as f:
        data = yaml.safe_load(f)

    out = {}

    # Each top-level key in YAML is a coverpoint or cross
    for name, item in data.items():
        bins = item.get("bins:_hits", {})
        out[name] = {}

        for bin_name, hits in bins.items():
            # Convert tuple keys to strings for JSON
            if isinstance(bin_name, tuple):
                bin_name = str(bin_name)
            out[name][bin_name] = hits

    with open(dst_json, "w") as f:
        json.dump(out, f, indent=2)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: convert_coverage_yaml_to_json.py <src.yaml> <dst.json>")
        sys.exit(1)
    main(sys.argv[1], sys.argv[2])

