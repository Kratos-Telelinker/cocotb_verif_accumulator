# test_reset_randomized.py

import random
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

def random_txn():
    return AdderTransaction(
        a=random.randint(0, 255),
        b=random.randint(0, 255),
        valid_in=random.randint(0, 1)
    )

@cocotb.test()
async def randomized_resets(dut):

    # IMPORTANT: import coverage ONLY after cocotb has started
    cov_module = importlib.import_module("external.coverage")
    FunctionalCoverage = cov_module.FunctionalCoverage

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
    agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

    # Create functional coverage collector
    coverage = FunctionalCoverage()

    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard, coverage)
    await env.start()

    await agent_a.driver.reset()
    await agent_b.driver.reset()

    # REQUIRED: one non-valid cycle BEFORE any valid sequence
    await agent_a.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
    await agent_b.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
    await Timer(1, "ns")

    for _ in range(20000):

        await agent_a.driver.send(random_txn())
        await agent_b.driver.send(random_txn())

        if random.random() < 0.01:
            await agent_a.driver.reset()
        if random.random() < 0.01:
            await agent_b.driver.reset()

        await Timer(1, "ns")

    await Timer(200, "ns")
    env.finalize()
    assert True




