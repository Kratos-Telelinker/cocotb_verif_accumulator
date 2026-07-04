# test_cross_closure.py

import cocotb
import importlib
from cocotb.clock import Clock
from cocotb.triggers import Timer

from sim.tb.driver import Driver
from sim.tb.monitor import Monitor
from sim.tb.scoreboard import Scoreboard
from sim.tb.agent import Agent
from sim.tb.env import Env
from sim.tb.sequences import coverage_driven_cross_sequence



@cocotb.test()
async def cross_closure(dut):

    # IMPORTANT: import coverage ONLY after cocotb has started
    cov_module = importlib.import_module("external.coverage")
    FunctionalCoverage = cov_module.FunctionalCoverage
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    clk = dut.clk

    agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
    agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

    # Create functional coverage collector
    coverage = FunctionalCoverage()

    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard, coverage)
    await env.start()

    # reset both channels
    dut.rst_A.value = 1
    dut.rst_B.value = 1
    await Timer(10, "ns")
    dut.rst_A.value = 0
    dut.rst_B.value = 0
    await Timer(10, "ns")

    # hammer the cross until high coverage
    await coverage_driven_cross_sequence(agent_a.driver, agent_b.driver, repeat=1)

    await Timer(50, "ns")
    env.finalize()


