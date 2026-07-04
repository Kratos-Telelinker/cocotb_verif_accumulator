import sys
from cocotb_coverage.coverage import coverage_db

def main(out_file, *inputs):
    for f in inputs:
        coverage_db.import_from_json(f)
    coverage_db.export_to_json(out_file)
    coverage_db.export_to_html(out_file.replace(".json", ".html"))

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: merge_coverage.py out.json in1.json in2.json ...")
        sys.exit(1)
    main(sys.argv[1], *sys.argv[2:])
# temp debug 
print("COVERAGE MERGE COMPLETE")  