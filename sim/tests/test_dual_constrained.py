# sim/tests/test_dual_constrained.py

import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.clock import Clock
import random


@cocotb.test()
async def test_dual_constrained(dut):

    cocotb.log.info("Starting test_dual_constrained")

    # Start clock
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    # Apply reset (match dut_wrapper: rst_A, rst_B)
    dut.rst_A.value = 1
    dut.rst_B.value = 1
    dut.valid_in_A.value = 0
    dut.valid_in_B.value = 0
    await Timer(25, unit="ns")
    dut.rst_A.value = 0
    dut.rst_B.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Reset complete, beginning constrained stimulus")

    # Constrained random testing loop
    for i in range(20):

        # Constrained stimulus for A
        a_A = random.randint(0, 5)
        b_A = random.randint(250, 255)

        dut.a_A.value = a_A
        dut.b_A.value = b_A
        dut.valid_in_A.value = 1

        # Constrained stimulus for B
        a_B = random.randint(10, 20)
        b_B = random.randint(30, 40)

        dut.a_B.value = a_B
        dut.b_B.value = b_B
        dut.valid_in_B.value = 1

        await RisingEdge(dut.clk)

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

        await Timer(1, unit="ns")

    cocotb.log.info("Completed constrained stimulus loop")



# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer
# from sim.tb.coverage import FunctionalCoverage
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.agent import Agent
# from sim.tb.env import Env
# from sim.tb.sequences import (
#     constrained_random_txn,
#     coverage_driven_cross_sequence,
# )


# @cocotb.test()
# async def test_dual_constrained(dut):
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     clk = dut.clk

    
#     agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
#     agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

#     # Create functional coverage collector
#     coverage = FunctionalCoverage()

#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard, coverage)
#     await env.start()

#     # Reset
#     dut.rst_A.value = 1
#     dut.rst_B.value = 1
#     await Timer(20, "ns")

#     dut.rst_A.value = 0
#     dut.rst_B.value = 0
#     await Timer(20, "ns")
    
#     # First: random exploration
#     for _ in range(2000):
#         await agent_a.driver.send(constrained_random_txn())
#         await agent_b.driver.send(constrained_random_txn())

#     # Second: deterministic cross‑bin closure (Option 3)
#     await coverage_driven_cross_sequence(agent_a.driver, agent_b.driver, repeat=1)

#     await Timer(50, "ns")
#     env.finalize()
#     assert True

#   dut.a_A.value = 10
#     dut.b_A.value = 20
#   # Initial reset
#     dut.rst_A.value = 1
#     dut.valid_in_A.value = 0
#     dut.a_A.value = 0
#     dut.b_A.value = 0
#     await RisingEdge(dut.clk)
#     dut.rst_A.value = 0

#     mid_reset_point = 250

#     for i in range(500):

#         # Mid-test reset
#         if i == mid_reset_point:
#             dut.rst_A.value = 1
#             dut.valid_in_A.value = 1
#             await RisingEdge(dut.clk)
#             dut.valid_in_A.value = 0
#             await RisingEdge(dut.clk)
#             dut.rst_A.value = 0


#  @cocotb.test()
# async def dual_agent(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
#     agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard)
#     await env.start()

#     # Reset both channels
#     dut.rst_A.value = 1
#     dut.rst_B.value = 1
#     await Timer(20, "ns")
#     dut.rst_A.value = 0
#     dut.rst_B.value = 0
#     await Timer(20, "ns")

#     for i in range(5):
#         await agent_a.driver.send(AdderTransaction(a=i,   b=i+1, valid_in=1))
#         await Timer(10, "ns")

#         await agent_b.driver.send(AdderTransaction(a=i+2, b=i+3, valid_in=1))
#         await Timer(10, "ns")

#     env.finalize()


           

