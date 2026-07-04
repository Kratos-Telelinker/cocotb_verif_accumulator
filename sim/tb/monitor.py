import cocotb
from cocotb.triggers import RisingEdge


class Monitor:
    def __init__(self, dut, clk, channel="A"):
        self.dut = dut
        self.clk = clk
        self.channel = channel
        self.callback = None

    def set_callback(self, callback):
        self.callback = callback

    async def start(self):
        while True:
            await RisingEdge(self.clk)

            if self.channel == "A":
                sample = {
                    "channel": "A",
                    "a": int(self.dut.a_A.value),
                    "b": int(self.dut.b_A.value),
                    "valid_in": int(self.dut.valid_in_A.value),
                    "rst": int(self.dut.rst_A.value),
                    "sum_async": int(self.dut.sum_async_A.value),
                    "sum_sync": int(self.dut.sum_sync_A.value),
                }

            else:  # CHANNEL B
                # ⭐ DEBUG MODULE FOR CHANNEL B ⭐
                cocotb.log.debug(
                    f"[MON B DEBUG] DUT READ: "
                    f"a_B={int(self.dut.a_B.value)} "
                    f"b_B={int(self.dut.b_B.value)} "
                    f"valid_in_B={int(self.dut.valid_in_B.value)} "
                    f"rst_B={int(self.dut.rst_B.value)} "
                    f"sum_async_B={int(self.dut.sum_async_B.value)} "
                    f"sum_sync_B={int(self.dut.sum_sync_B.value)}"
                )

                sample = {
                    "channel": "B",
                    "a": int(self.dut.a_B.value),
                    "b": int(self.dut.b_B.value),
                    "valid_in": int(self.dut.valid_in_B.value),
                    "rst": int(self.dut.rst_B.value),
                    "sum_async": int(self.dut.sum_async_B.value),
                    "sum_sync": int(self.dut.sum_sync_B.value),
                }

            if self.callback:
                self.callback(sample)


# import cocotb
# from cocotb.triggers import RisingEdge

# class Monitor:
#     def __init__(self, dut, clk, channel):
#         self.dut = dut
#         self.clk = clk
#         self.channel = channel
#         self.callback = None

#     def _sig(self, base):
#         suffix = "_A" if self.channel == "A" else "_B"
#         return getattr(self.dut, f"{base}{suffix}")

#     async def start(self):
#         while True:
#             await RisingEdge(self.clk)

#             sample = {
#                 "channel": self.channel,
#                 "a": int(self._sig("a").value),
#                 "b": int(self._sig("b").value),
#                 "sum_sync": int(self._sig("sum_sync").value),
#                 "sum_async": int(self._sig("sum_async").value),
#                 "valid_in": int(self._sig("valid_in").value),
#                 "rst": int(self._sig("rst").value),
#             }

#             if self.callback is not None:
#                 self.callback(sample)


# from cocotb.triggers import RisingEdge, ReadOnly
# from sim.tb.coverage import sample_coverage


# class Monitor:
#     def __init__(self, dut, clk, prefix: str = "", callback=None):
#         self.dut = dut
#         self.clk = clk
#         self.prefix = prefix
#         self.callback = callback
#         self.prev_sum_sync = None

#     def _sig(self, name):
#         return getattr(self.dut, f"{self.prefix}{name}")

#     async def start(self):
#         while True:
#             await RisingEdge(self.clk)
#             await ReadOnly()

#             sample = {
#                 "channel": "A" if self.prefix == "" else "B",
#                 "valid_in": int(self._sig("valid_in").value),
#                 "a": int(self._sig("a").value),
#                 "b": int(self._sig("b").value),
#                 "sum_sync": int(self._sig("sum_sync").value),
#                 "sum_async": int(self._sig("sum_async").value),
#                 "rst": int(self._sig("rst").value),
#             }

#             # Sample only when sum_sync has updated (final cycle of transaction)
#             if sample["valid_in"] == 1 and sample["rst"] == 0:
#                 if self.prev_sum_sync is None or sample["sum_sync"] != self.prev_sum_sync:
#                     sample_coverage(sample)

#             self.prev_sum_sync = sample["sum_sync"]

#             if self.callback is not None:
#                 self.callback(sample)


