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
async def randomized_stress(dut):

    # IMPORTANT: import coverage ONLY after cocotb has started
    cov_module = importlib.import_module("external.coverage")
    FunctionalCoverage = cov_module.FunctionalCoverage

    cocotb.start_soon(Clock(dut.clk, 5, "ns").start())  # faster clock

    agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
    agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

    # Create functional coverage collector
    coverage = FunctionalCoverage()

    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard, coverage)
    await env.start()

    # Reset both channels
    dut.rst_A.value = 1
    dut.rst_B.value = 1
    await Timer(20, "ns")
    dut.rst_A.value = 0
    dut.rst_B.value = 0
    
    # Wait one clock so the first transaction doesn’t collide with the 40 ns sample
    await RisingEdge(dut.clk)


    # Stress test with separated cycles (Option 1)
    for _ in range(200):

        # Channel A drives first
        await agent_a.driver.send(AdderTransaction.random())
        #await Timer(5, "ns")   # allow DUT to sample A

        # Channel B drives on the next cycle
        await agent_b.driver.send(AdderTransaction.random())
        await Timer(1, "ns")   # allow DUT to sample B

    env.finalize()





