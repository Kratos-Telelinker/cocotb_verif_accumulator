#test_smoke.py

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


@cocotb.test()
async def test_basic(dut):
    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    # Reset sequence
    dut.rst_A.value = 1
    dut.valid_in_A.value = 0
    dut.a_A.value = 0
    dut.b_A.value = 0

    await RisingEdge(dut.clk)
    dut.rst_A.value = 0

    # Drive a simple transaction
    dut.valid_in_A.value = 1
    dut.a_A.value = 10
    dut.b_A.value = 20

    await RisingEdge(dut.clk)
    dut.valid_in_A.value = 0

    # Allow sum_sync to update
    for _ in range(3):
        await RisingEdge(dut.clk)

    # Check sum_async (combinational)
    assert int(dut.sum_async_A.value) == 30



# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# @cocotb.test()
# async def test_basic(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     # Reset both channels
#     dut.adifA.rst.value = 1
#     dut.adifB.rst.value = 1
#     await Timer(20, "ns")
#     dut.adifA.rst.value = 0
#     dut.adifB.rst.value = 0
#     await Timer(20, "ns")

#     # Drive some values
#     dut.adifA.valid_in.value = 0
#     dut.adifA.a.value = 1
#     dut.adifA.b.value = 2
#     await Timer(20, "ns")

#     # Now assert valid_in
#     dut.adifA.valid_in.value = 1
#     await Timer(20, "ns")

#     # No scoreboard here, just basic smoke
#     assert True



   