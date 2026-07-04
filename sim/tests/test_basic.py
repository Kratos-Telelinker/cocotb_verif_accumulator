# pytest: skip-rewrite

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


@cocotb.test()
async def test_basic(dut):
    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    # Reset
    dut.rst_A.value = 1
    dut.valid_in_A.value = 0
    dut.a_A.value = 0
    dut.b_A.value = 0

    await RisingEdge(dut.clk)
    dut.rst_A.value = 0

    # Simple transaction: a=10, b=20
    dut.valid_in_A.value = 1
    dut.a_A.value = 10
    dut.b_A.value = 20

    await RisingEdge(dut.clk)
    dut.valid_in_A.value = 0

    # Let sum_sync settle a few cycles
    for _ in range(3):
        await RisingEdge(dut.clk)

    # Check combinational sum_async
    assert int(dut.sum_async_A.value) == 30





# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# from sim.tb.driver import Driver, AdderTransaction
# from sim.tb.monitor import Monitor
# from sim.tb.agent import Agent
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.env import Env

# @cocotb.test()
# async def test_basic(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     clk = dut.clk

#     agent = Agent(
#         "A",
#         Driver(dut.adifA, clk, prefix=""),
#         Monitor(dut.adifA, clk, prefix="")
#     )

#     scoreboard = Scoreboard()
#     env = Env(agent, None, scoreboard)
#     await env.start()

#     # Reset channel A
#     dut.adifA.rst.value = 1
#     await Timer(10, "ns")
#     dut.adifA.rst.value = 0
#     await Timer(10, "ns")

#     # warm-up cycle
#     await agent.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
#     await Timer(10, "ns")

#     # valid cycle
#     await agent.driver.send(AdderTransaction(a=1, b=2, valid_in=1))
#     await Timer(20, "ns")

#     env.finalize()


