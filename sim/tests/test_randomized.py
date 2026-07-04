# Test_randomized.py

import cocotb
import importlib
from cocotb.clock import Clock
from cocotb.triggers import Timer


from sim.tb.env import Env
from sim.tb.agent import Agent
from sim.tb.driver import Driver
from sim.tb.monitor import Monitor
from sim.tb.scoreboard import Scoreboard
from sim.tb.sequences import AdderTransaction
from cocotb.triggers import RisingEdge

@cocotb.test()
async def randomized(dut):

    # IMPORTANT: import coverage ONLY after cocotb has started
    cov_module = importlib.import_module("external.coverage")
    FunctionalCoverage = cov_module.FunctionalCoverage

    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
    agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

    # Create functional coverage collector
    coverage = FunctionalCoverage()

    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard, coverage)
    await env.start()

    dut.rst_A.value = 1
    dut.rst_B.value = 1
    await Timer(20, "ns")
    dut.rst_A.value = 0
    dut.rst_B.value = 0
    
    # Wait one clock so the first transaction doesn’t collide with the 40 ns sample
    await RisingEdge(dut.clk)

    for _ in range(50):
        await agent_a.driver.send(AdderTransaction.random())
        await agent_b.driver.send(AdderTransaction.random())

        # Critical: allow DUT async sums to update before monitor samples
        await Timer(1, "ns")
    env.finalize()

