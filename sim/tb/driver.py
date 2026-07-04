import cocotb
from cocotb.triggers import RisingEdge
from cocotb.triggers import Timer

class AdderTransaction:
    def __init__(self, a: int, b: int, valid_in: int = 1):
        self.a = a
        self.b = b
        self.valid_in = valid_in

    @staticmethod
    def random():
        import random
        return AdderTransaction(
            a=random.randint(0, 255),
            b=random.randint(0, 255),
            valid_in=1,
        )

class Driver:
    def __init__(self, dut, clk, channel="A"):
        self.dut = dut
        self.clk = clk
        self.channel = channel

    def _sig(self, base):
        suffix = "_A" if self.channel == "A" else "_B"
        return getattr(self.dut, f"{base}{suffix}")

    async def start(self):
        # No continuous driving. Prevents overwriting send() values.
        while True:
            await RisingEdge(self.clk)

    async def send(self, txn):
        # Drive BEFORE rising edge
        self._sig("a").value = txn.a
        self._sig("b").value = txn.b
        self._sig("valid_in").value = txn.valid_in

        # DUT samples here
        await RisingEdge(self.clk)
        await Timer(1, "ns")   # <-- allow monitor to sample with valid_in still high

        # Drop valid_in after one cycle
        self._sig("valid_in").value = 0

    async def reset(self):
        self._sig("a").value = 0
        self._sig("b").value = 0
        self._sig("valid_in").value = 0
        self._sig("rst").value = 1

        await RisingEdge(self.clk)

        self._sig("rst").value = 0
        self._sig("valid_in").value = 0


# import cocotb
# from cocotb.triggers import RisingEdge, ReadWrite


# class AdderTransaction:
#     def __init__(self, a: int, b: int, valid_in: int = 1):
#         self.a = a
#         self.b = b
#         self.valid_in = valid_in

#     @staticmethod
#     def random():
#         import random
#         return AdderTransaction(
#             a=random.randint(0, 255),
#             b=random.randint(0, 255),
#             valid_in=1,
#         )


# class Driver:
#     def __init__(self, dut, clk, channel: str = "A"):
#         self.dut = dut
#         self.clk = clk
#         self.channel = channel
#         self.last_txn = AdderTransaction(0, 0, 0)
#         self.in_reset = False

#     def _sig(self, base):
#         suffix = "_A" if self.channel == "A" else "_B"
#         return getattr(self.dut, f"{base}{suffix}")

#     async def start(self):
#         while True:
#             if not self.in_reset:
#                 self._sig("valid_in").value = self.last_txn.valid_in
#                 self._sig("a").value = self.last_txn.a
#                 self._sig("b").value = self.last_txn.b
#             await RisingEdge(self.clk)

#     async def send(self, txn):
#         self.last_txn = txn

#         self._sig("valid_in").value = txn.valid_in
#         self._sig("a").value = txn.a
#         self._sig("b").value = txn.b

#         await ReadWrite()

#         for _ in range(3):
#             await RisingEdge(self.clk)

#         self._sig("valid_in").value = 0

#         for _ in range(2):
#             await RisingEdge(self.clk)

#     async def reset(self):
#         self.in_reset = True

#         self._sig("valid_in").value = 0
#         self._sig("a").value = 0
#         self._sig("b").value = 0

#         self._sig("rst").value = 1
#         self._sig("valid_in").value = 1

#         await RisingEdge(self.clk)

#         self._sig("valid_in").value = 0

#         await RisingEdge(self.clk)

#         self._sig("rst").value = 0

#         self.in_reset = False





# import cocotb
# from cocotb.triggers import RisingEdge, ReadWrite


# class AdderTransaction:
#     def __init__(self, a: int, b: int, valid_in: int = 1):
#         self.a = a
#         self.b = b
#         self.valid_in = valid_in

#     @staticmethod
#     def random():
#         import random
#         return AdderTransaction(
#             a=random.randint(0, 255),
#             b=random.randint(0, 255),
#             valid_in=1,
#         )


# class Driver:
#     def __init__(self, dut, clk, prefix=""):
#         self.dut = dut
#         self.clk = clk
#         self.prefix = prefix
#         self.last_txn = AdderTransaction(0, 0, 0)
#         self.in_reset = False

#     def _sig(self, name):
#         return getattr(self.dut, f"{self.prefix}{name}")

#     async def start(self):
#         while True:
#             if not self.in_reset:
#                 self._sig("valid_in").value = self.last_txn.valid_in
#                 self._sig("a").value = self.last_txn.a
#                 self._sig("b").value = self.last_txn.b
#             await RisingEdge(self.clk)

#     async def send(self, txn):
#         self.last_txn = txn

#         self._sig("valid_in").value = txn.valid_in
#         self._sig("a").value = txn.a
#         self._sig("b").value = txn.b

#         await ReadWrite()

#         for _ in range(3):
#             await RisingEdge(self.clk)

#         self._sig("valid_in").value = 0

#         for _ in range(2):
#             await RisingEdge(self.clk)

#     async def reset(self):
#         self.in_reset = True

#         self._sig("valid_in").value = 0
#         self._sig("a").value = 0
#         self._sig("b").value = 0

#         # assert reset
#         self._sig("rst").value = 1

#         # valid_in=1 WHILE rst=1 BEFORE posedge
#         self._sig("valid_in").value = 1

#         await RisingEdge(self.clk)   # DUT samples rst=1 & valid_in=1 here

#         self._sig("valid_in").value = 0

#         await RisingEdge(self.clk)

#         # deassert reset
#         self._sig("rst").value = 0

#         self.in_reset = False