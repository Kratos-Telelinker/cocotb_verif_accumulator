# tools/functional_cov_to_html.py

import sys
import json
import os


def main(src_json: str, outdir: str) -> None:
    os.makedirs(outdir, exist_ok=True)

    with open(src_json) as f:
        cov = json.load(f)

    html = []
    html.append("<html><head><meta charset='utf-8'>")
    html.append("<title>Functional Coverage</title>")
    html.append("""
    <style>
    body { font-family: sans-serif; margin: 20px; }
    h1 { margin-bottom: 10px; }
    h2 { margin-top: 25px; }
    table { border-collapse: collapse; margin-top: 5px; }
    th, td { border: 1px solid #ccc; padding: 4px 8px; }
    th { background: #eee; }
    .hit { background: #aaffaa; }
    .miss { background: #ffaaaa; }
    .summary { margin-top: 10px; font-size: 0.9em; color: #555; }
    </style>
    """)
    html.append("</head><body>")
    html.append("<h1>Functional Coverage Report</h1>")

    for cp, bins in cov.items():
        total_bins = len(bins)
        hit_bins = sum(1 for h in bins.values() if h > 0)
        pct = (hit_bins / total_bins * 100.0) if total_bins else 0.0

        html.append(f"<h2>{cp}</h2>")
        html.append(f"<div class='summary'>Bins hit: {hit_bins}/{total_bins} ({pct:.1f}%)</div>")
        html.append("<table>")
        html.append("<tr><th>Bin</th><th>Hits</th></tr>")

        for b, h in sorted(bins.items()):
            cls = "hit" if h > 0 else "miss"
            html.append(f"<tr class='{cls}'><td>{b}</td><td>{h}</td></tr>")

        html.append("</table>")

    html.append("</body></html>")

    out_path = os.path.join(outdir, "index.html")
    with open(out_path, "w") as f:
        f.write("\n".join(html))

    print(f"Functional coverage HTML written to {out_path}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: functional_cov_to_html.py <merged.json> <outdir>")
        sys.exit(1)
    main(sys.argv[1], sys.argv[2])
