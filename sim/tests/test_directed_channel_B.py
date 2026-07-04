# test_directed_channel_B.py
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge

@cocotb.test()
async def directed_channel_B(dut):

    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    # Reset both channels
    dut.rst_A.value = 1
    dut.rst_B.value = 1
    dut.valid_in_B.value = 0
    await Timer(20, "ns")

    dut.rst_A.value = 0
    dut.rst_B.value = 0
    await RisingEdge(dut.clk)
    await Timer(10, "ns")

    vectors = [
        (3, 4),
        (1, 7),
        (2, 2),
    ]

    for a, b in vectors:
        dut.a_B.value = a
        dut.b_B.value = b
        dut.valid_in_B.value = 1

        await RisingEdge(dut.clk)
        await Timer(1, "ns")

        sum_async = int(dut.sum_async_B.value)
        expected = a + b

        cocotb.log.info(f"[SIMPLE B] a={a} b={b} sum_async={sum_async} expected={expected}")
        assert sum_async == expected

        dut.valid_in_B.value = 0






# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# from sim.tb.env import Env
# from sim.tb.agent import Agent
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.sequences import AdderTransaction
# from sim.tb.coverage import FunctionalCoverage

# @cocotb.test()
# async def directed_channel_B(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))
#     agent_a = None

#     # Create functional coverage collector
#     coverage = FunctionalCoverage()

#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard, coverage)
#     await env.start()

#     # Reset channel B
#     dut.rst_B.value = 1
#     await Timer(20, "ns")
#     dut.rst_B.value = 0
#     await Timer(20, "ns")

#     # Directed vectors
#     vecs = [
#         AdderTransaction(a=3, b=4, valid_in=1),
#         AdderTransaction(a=1, b=7, valid_in=1),
#         AdderTransaction(a=2, b=2, valid_in=1),
#     ]

#     for txn in vecs:
#         await agent_b.driver.send(txn)
#         await Timer(20, "ns")

#     env.finalize()