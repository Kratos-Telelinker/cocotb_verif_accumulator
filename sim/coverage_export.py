# sim/coverage_export.py

from cocotb_coverage.coverage import coverage_db


def export_coverage(filename: str = "coverage.yaml") -> None:
    """
    Export current functional coverage database to a YAML file.
    """
    coverage_db.export_to_yaml(filename)
