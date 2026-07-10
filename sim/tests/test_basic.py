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
    cocotb.log.info("\nFirst Iterations of Loop Displayed for Debugging\n")
    # Let sum_sync settle a few cycles
    for _ in range(500): # 50000set the desired number of cycles for the test
        await RisingEdge(dut.clk)
        if _ <= 5 :
            cocotb.log.info(
                f"RAW DUT: "
                f"a_A={int(dut.a_A.value)} "
                f"b_A={int(dut.b_A.value)} "
                f"sum_async_A={int(dut.sum_async_A.value)} "
                f"valid_in_A={int(dut.valid_in_A.value)} | "
                f"a_B={int(dut.a_B.value)} "
                f"b_B={int(dut.b_B.value)} "
                f"sum_async_B={int(dut.sum_async_B.value)} "
                f"valid_in_B={int(dut.valid_in_B.value)}"
            )
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


