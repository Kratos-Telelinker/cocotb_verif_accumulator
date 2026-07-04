# test_directed_channel_A.py

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

from sim.tb.env import Env
from sim.tb.agent import Agent
from sim.tb.driver import Driver
from sim.tb.monitor import Monitor
from sim.tb.scoreboard import Scoreboard
from sim.tb.sequences import AdderTransaction

@cocotb.test()
async def directed_channel_A(dut):

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    agent_a = Agent(
        "A",
        Driver(dut, dut.clk, channel="A"),
        Monitor(dut, dut.clk, channel="A")
    )

    agent_b = None

    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard)
    await env.start()

    # Reset DUT
    dut.rst_A.value = 1
    await RisingEdge(dut.clk)
    dut.rst_A.value = 0
    await RisingEdge(dut.clk)

    # Warm-up
    await agent_a.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
    await RisingEdge(dut.clk)

    directed_vecs = [
        AdderTransaction(a=0, b=1, valid_in=1),
        AdderTransaction(a=5, b=3, valid_in=1),
        AdderTransaction(a=2, b=2, valid_in=1),
        AdderTransaction(a=0, b=7, valid_in=1),
        AdderTransaction(a=9, b=1, valid_in=1),
    ]

    for txn in directed_vecs:
        await agent_a.driver.send(txn)
        await RisingEdge(dut.clk)

    await RisingEdge(dut.clk)

    env.finalize()
    assert True




# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# from sim.tb.env import Env
# from sim.tb.agent import Agent
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.coverage import FunctionalCoverage

# from sim.tb.sequences import AdderTransaction

# @cocotb.test()
# async def directed_channel_A(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

#     agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
#     agent_b = None

#     # Create functional coverage collector
#     coverage = FunctionalCoverage()

#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard, coverage)
#     await env.start()

#     # Proper DUT reset (channel A)
#     dut.rst_A.value = 1
#     await Timer(10, "ns")
#     dut.rst_A.value = 0
#     await Timer(10, "ns")

#     # Warm-up cycle
#     await agent_a.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
#     await Timer(10, "ns")

#     directed_vecs = [
#         AdderTransaction(a=0, b=1, valid_in=1),
#         AdderTransaction(a=5, b=3, valid_in=1),
#         AdderTransaction(a=2, b=2, valid_in=1),
#         AdderTransaction(a=0, b=7, valid_in=1),
#         AdderTransaction(a=9, b=1, valid_in=1),
#     ]

#     for txn in directed_vecs:
#         await agent_a.driver.send(txn)
#         await Timer(20, "ns")

#     await Timer(50, "ns")
#     env.finalize()
#     assert True