# scoreboard.py


# sim/tb/scoreboard.py

class Scoreboard:
    def __init__(self):
        self.errors = 0

    def compare(self, sample):
        if sample["rst"] == 1:
            return

        # Only check async sum when valid_in == 1
        if sample["valid_in"] == 0:
            return

        a = sample["a"]
        b = sample["b"]
        expected = a + b
        sum_async = sample["sum_async"]

        if sum_async != expected:
            self.errors += 1
            raise AssertionError(
                f"[{sample['channel']}] Mismatch: a={a} b={b} "
                f"valid_in={sample['valid_in']} rst={sample['rst']} "
                f"sum_async={sum_async} (exp {expected})"
            )

    def finalize(self):
        print(f"Scoreboard complete. Errors = {self.errors}")


# class Scoreboard:
#     def __init__(self):
#         self.errors = 0

#     def compare(self, sample):
#         ch        = sample["channel"]
#         a         = sample["a"]
#         b         = sample["b"]
#         sum_async = sample["sum_async"]
#         valid_in  = sample["valid_in"]
#         rst       = sample["rst"]

#         # Ignore reset cycles
#         if rst == 1:
#             return

#         # Ignore cycles where DUT is sampling inputs
#         if valid_in == 1:
#             return

#         # Expected combinational sum
#         expected = a + b

#         if sum_async != expected:
#             self.errors += 1
#             raise AssertionError(
#                 f"[{ch}] Mismatch: a={a} b={b} valid_in={valid_in} rst={rst} "
#                 f"sum_async={sum_async} (exp {expected})"
#             )

#     def finalize(self):
#         print(f"Scoreboard complete. Errors = {self.errors}")
