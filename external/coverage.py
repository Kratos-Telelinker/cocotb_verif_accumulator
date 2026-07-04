## pytest: skip-rewrite
print(">>> COVERAGE MODULE LOADED FROM:", __file__)

from cocotb_coverage.coverage import CoverPoint, CoverCross, coverage_db

# Prevent double registration
if "coverage_initialized" not in globals():
    coverage_initialized = False

if not coverage_initialized:


       # Operand bins (discrete values)
    A_BINS = [0, 1, 2, 3, 4, 8, 16, 32, 64, 128, 255]
    B_BINS = [0, 1, 2, 3, 4, 8, 16, 32, 64, 128, 255]

    SUM_SYNC_BINS = [0, 1, 2, 255, 511]
    VALID_BINS    = [0, 1]
    RST_BINS      = [0, 1]
    PATTERN_BINS = [
            (0, 0),
            (0, 255),
            (255, 0),
            (255, 255)
        ]
    # ---------------------------------------------------------
    # Base CoverPoints
    # ---------------------------------------------------------
    @CoverPoint("adder.valid_in", xf=lambda s: s["valid_in"], bins=VALID_BINS)
    @CoverPoint("adder.rst",      xf=lambda s: s["rst"],      bins=RST_BINS)
    @CoverPoint("adder.a",        xf=lambda s: s["a"],        bins=A_BINS)
    @CoverPoint("adder.b",        xf=lambda s: s["b"],        bins=B_BINS)
    @CoverPoint("adder.sum_sync", xf=lambda s: s["sum_sync"], bins=SUM_SYNC_BINS)


        # ---------------------------------------------------------
    # Step 2 — Illegal condition coverpoint
    # ---------------------------------------------------------
    @CoverPoint(
        "adder.valid_rst_illegal",
        xf=lambda s: 1 if (s["valid_in"] == 1 and s["rst"] == 1) else 0,
        bins=[0, 1]
    )


        # ---------------------------------------------------------
    # Step 3 — Per‑channel covergroups
    # ---------------------------------------------------------

    @CoverPoint(
        "adder.A.a",
        xf=lambda s: s["a"] if s.get("channel") == "A" else None,
        bins=A_BINS
    )
    @CoverPoint(
        "adder.A.b",
        xf=lambda s: s["b"] if s.get("channel") == "A" else None,
        bins=B_BINS
    )
    @CoverCross("adder.A.cross_a_b", items=["adder.A.a", "adder.A.b"])

    @CoverPoint(
        "adder.B.a",
        xf=lambda s: s["a"] if s.get("channel") == "B" else None,
        bins=A_BINS
    )
    @CoverPoint(
        "adder.B.b",
        xf=lambda s: s["b"] if s.get("channel") == "B" else None,
        bins=B_BINS
    )
    @CoverCross("adder.B.cross_a_b", items=["adder.B.a", "adder.B.b"])


        # ---------------------------------------------------------
    # Step 4 — Overflow coverpoint + cross
    # ---------------------------------------------------------
    @CoverPoint(
        "adder.overflow",
        xf=lambda s: 1 if s["sum_async"] > 255 else 0,
        bins=[0, 1]
    )
    @CoverCross(
        "adder.cross_overflow_valid",
        items=["adder.overflow", "adder.valid_in"]
    )

    # ---------------------------------------------------------
    # Step 5 — Pattern bins (SAFE VERSION)
    # ---------------------------------------------------------
    

    @CoverPoint(
        "adder.patterns",
        xf=lambda s: (s["a"], s["b"]),
        bins=PATTERN_BINS)

        # ---------------------------------------------------------
    # Step 6 — Illegal cross bins (manual)
    # ---------------------------------------------------------
    @CoverCross(
        "adder.cross_valid_rst",
        items=["adder.valid_in", "adder.rst"]
    )

        # ---------------------------------------------------------
    # Step 7 — Temporal coverage (valid_in rising edge)
    # ---------------------------------------------------------
    @CoverPoint(
        "adder.valid_rise",
        xf=lambda s: s.get("_valid_rise", 0),
        bins=[0, 1]
    )
        # ---------------------------------------------------------
    # Step 8 — Cross coverage: sum_sync × valid_in
    # ---------------------------------------------------------
    @CoverCross(
        "adder.cross_sum_valid",
        items=["adder.sum_sync", "adder.valid_in"]
    )


        # ---------------------------------------------------------
    # Step 9 — Base cross: a × b
    # ---------------------------------------------------------
    @CoverCross(
        "adder.cross_a_b",
        items=["adder.a", "adder.b"]
    )
        # ---------------------------------------------------------
    # Step 10 — Cross coverage: valid_rise × sum_sync
    # ---------------------------------------------------------
    @CoverCross(
        "adder.cross_valid_rise_sum",
        items=["adder.valid_rise", "adder.sum_sync"]
    )

        # ---------------------------------------------------------
    # Step 11 — Cross coverage: patterns × overflow
    # ---------------------------------------------------------
    @CoverCross(
        "adder.cross_pattern_overflow",
        items=["adder.patterns", "adder.overflow"]
    )

        # ---------------------------------------------------------
    # Step 12 — Coverage summary helpers
    # ---------------------------------------------------------
    # def summary(self):
    #     """Print a human-readable summary of coverage."""
    #     print("\n=== FUNCTIONAL COVERAGE SUMMARY ===")
    #     for name, obj in coverage_db.items():
    #         try:
    #             pct = obj.coverage
    #             print(f"{name:35s} : {pct:6.2f}%")
    #         except AttributeError:
    #             # Ignore non-coverage entries
    #             pass
    #     print("===================================\n")

    # def dump(self):
    #     """Dump raw coverage database to console."""
    #     print("\n=== RAW COVERAGE DATABASE ===")
    #     for name, obj in coverage_db.items():
    #         print(f"{name}: {obj}")
    #     print("================================\n")

    # def get_coverage(self, name):
    #     """Return coverage percentage for a specific coverpoint or cross."""
    #     obj = coverage_db.get(name, None)
    #     if obj is None:
    #         print(f"Coverage item '{name}' not found.")
    #         return None
    #     try:
    #         return obj.coverage
    #     except AttributeError:
    #         print(f"Item '{name}' is not a coverage object.")
    #         return None
     

    def sample_coverage(s):
        # Decorators handle sampling
        pass

    coverage_initialized = True


class FunctionalCoverage:

    def __init__(self, test_name="unknown"):
        self.test_name = test_name
        self.prev_valid = 0
        self.illegal_count = 0

    def sample(self, sample):

        # Temporal coverage: rising edge of valid_in
        valid_now = sample["valid_in"]
        sample["_valid_rise"] = 1 if (valid_now == 1 and self.prev_valid == 0) else 0
        self.prev_valid = valid_now

        # Illegal condition detection
        if sample["valid_in"] == 1 and sample["rst"] == 1:
            print("ILLEGAL: valid_in=1 while rst=1")
            self.illegal_count += 1

        

        # Sample all coverpoints/crosses
        sample_coverage(sample)

    def export_yaml(self, filename):
        coverage_db.export_to_yaml(filename)

    def export_xml(self, filename):
        coverage_db.export_to_xml(filename)

    # ---------------------------------------------------------
    # Step 12 — Coverage summary helpers (CORRECT LOCATION)
    # ---------------------------------------------------------
    def summary(self):
        print("\n=== Functional Coverage Summary ===")
        for name, obj in coverage_db.items():
            try:
                pct = obj.coverage
                total = obj.size
                hits = obj.covered
                print(f"{name}: {hits}/{total} bins hit ({pct:.1f}%)")
            except AttributeError:
                pass
        print("===================================\n")

    def dump(self):
        print("\n=== RAW COVERAGE DATABASE ===")
        for name, obj in coverage_db.items():
            print(f"{name}: {obj}")
        print("================================\n")

    def get_coverage(self, name):
        obj = coverage_db.get(name, None)
        if obj is None:
            print(f"Coverage item '{name}' not found.")
            return None
        try:
            return obj.coverage
        except AttributeError:
            print(f"Item '{name}' is not a coverage object.")
            return None
        
    # ---------------------------------------------------------
    # Step 13 — Regression-level coverage aggregation
    # ---------------------------------------------------------
    def reset(self):
        """Reset internal temporal state but keep coverage_db intact."""
        self.prev_valid = 0
        self.illegal_count = 0

    def clear_coverage(self):
        """Clear all coverage bins (full reset)."""
        coverage_db.clear()

    def merge_from(self, other):
        """Merge coverage from another FunctionalCoverage instance."""
        for name, obj in coverage_db.items():
            try:
                # Merge bin hit counts
                for bin_name in obj._bins:
                    obj._bins[bin_name] |= other._get_bin_hits(name, bin_name)
            except Exception:
                pass

    def _get_bin_hits(self, name, bin_name):
        """Internal helper: return bin hit mask for merging."""
        try:
            return coverage_db[name]._bins[bin_name]
        except Exception:
            return 0

    def export_regression(self, filename_yaml, filename_xml):
        """Export merged regression-level coverage."""
        coverage_db.export_to_yaml(filename_yaml)
        coverage_db.export_to_xml(filename_xml)
        # ---------------------------------------------------------
    # Step 14 — Coverage thresholds + automatic pass/fail
    # ---------------------------------------------------------
    def check_thresholds(self, min_pct=75.0):
        """
        Enforce minimum coverage percentage.
        Only checks real coverpoints/crosses (those with bins).
        Skips hierarchical grouping keys like 'adder', 'adder.A', 'adder.B'.
        """
        failures = []

        for name, obj in coverage_db.items():

            # Skip anything that does not have bins (hierarchical nodes)
            if not hasattr(obj, "_bins"):
                continue

            pct = obj.coverage
            if pct < min_pct:
                failures.append((name, pct))

        if failures:
            print("\n*** COVERAGE FAILURE: Threshold not met ***")
            print(f"Required minimum coverage: {min_pct:.1f}%")
            print("Items below threshold:")
            for name, pct in failures:
                print(f"  - {name:35s}: {pct:.1f}%")
            print("************************************************\n")

            raise RuntimeError("Coverage threshold not met.")
        else:
            print(f"\nCoverage threshold {min_pct:.1f}% met for all items.\n")
