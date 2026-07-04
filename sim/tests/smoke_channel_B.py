import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

@cocotb.test()
async def smoke_channel_B(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_B.value = 1
    dut.valid_in_B.value = 0
    await Timer(20, unit="ns")
    dut.rst_B.value = 0
    await RisingEdge(dut.clk)

    dut.a_B.value = 3
    dut.b_B.value = 4
    dut.valid_in_B.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")

    cocotb.log.info(
        f"SMOKE B: a_B={int(dut.a_B.value)} "
        f"b_B={int(dut.b_B.value)} "
        f"sum_async_B={int(dut.sum_async_B.value)} "
        f"valid_in_B={int(dut.valid_in_B.value)} "
        f"rst_B={int(dut.rst_B.value)}"
    )
