# tools/coverage_dashboard.py

import sys
import os
import glob

def main(code_html_dir, func_html_dir, outdir):
    os.makedirs(outdir, exist_ok=True)

    # Find waveforms
    waves = sorted(glob.glob("regression_results/waves_*.*"))

    rows = []
    for w in waves:
        fname = os.path.basename(w)
        test_num = fname.split("_")[1].split(".")[0]
        rows.append(f"<tr><td>{test_num}</td><td><a href='../regression_results/{fname}'>{fname}</a></td></tr>")

    html = f"""
    <html>
    <head>
        <meta charset='utf-8'>
        <title>Verification Dashboard</title>
        <style>
            body {{ font-family: sans-serif; margin: 40px; }}
            h1 {{ margin-bottom: 20px; }}
            a {{ font-size: 1.1em; }}
            table {{ border-collapse: collapse; margin-top: 20px; }}
            th, td {{ border: 1px solid #ccc; padding: 6px 12px; }}
            th {{ background: #eee; }}
        </style>
    </head>
    <body>

        <h1>Verification Dashboard</h1>

        <h2>Reports</h2>
        <ul>
            <li><a href="../coverage_html/index.html">Code Coverage Report</a></li>
            <li><a href="../func_cov_html/index.html">Functional Coverage Report</a></li>
        </ul>

        <h2>Waveforms</h2>
        <table>
            <tr><th>Test #</th><th>Waveform File</th></tr>
            {''.join(rows)}
        </table>

    </body>
    </html>
    """

    with open(os.path.join(outdir, "index.html"), "w") as f:
        f.write(html)

    print(f"Dashboard written to {outdir}/index.html")


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: coverage_dashboard.py <code_html_dir> <func_html_dir> <outdir>")
        sys.exit(1)
    main(sys.argv[1], sys.argv[2], sys.argv[3])
