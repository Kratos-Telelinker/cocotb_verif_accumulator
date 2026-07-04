import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

@cocotb.test()
async def direct_drive_A(dut):
    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    # Reset
    dut.rst_A.value = 1
    dut.valid_in_A.value = 0
    dut.a_A.value = 0
    dut.b_A.value = 0
    await RisingEdge(dut.clk)

    dut.rst_A.value = 0
    await RisingEdge(dut.clk)

    # Drive a=4, b=64 BEFORE edge
    dut.a_A.value = 4
    dut.b_A.value = 64
    dut.valid_in_A.value = 1

    await RisingEdge(dut.clk)

    assert int(dut.sum_async_A.value) == 68, \
        f"sum_async_A={int(dut.sum_async_A.value)} expected 68"
