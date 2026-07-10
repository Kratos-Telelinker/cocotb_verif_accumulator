import cocotb
import importlib
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge

from sim.tb.env import Env
from sim.tb.agent import Agent
from sim.tb.driver import Driver
from sim.tb.monitor import Monitor
from sim.tb.scoreboard import Scoreboard

from sim.tb.sequences import AdderTransaction


@cocotb.test()
async def dual_agent(dut):

    # IMPORTANT: import coverage ONLY after cocotb has started
    cov_module = importlib.import_module("external.coverage")
    FunctionalCoverage = cov_module.FunctionalCoverage

    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
    agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

    coverage = FunctionalCoverage()
    scoreboard = Scoreboard()
    env = Env(agent_a, agent_b, scoreboard, coverage)

    await env.start()

    # ============================================================
    # RESET FIRST (critical)
    # ============================================================
    dut.rst_A.value = 1
    dut.rst_B.value = 1
    await Timer(20, "ns")

    dut.rst_A.value = 0
    dut.rst_B.value = 0

    # Allow DUT one clean cycle after reset
    await RisingEdge(dut.clk)

    # ============================================================
    # DIRECTED STIMULUS TO HIT MISSING COVERAGE BINS (Step 3)
    # ============================================================

    # --- 1. Hit sum_sync bins 255 and 511 ------------------------
    await agent_a.driver.send(AdderTransaction(a=255, b=0,   valid_in=1))   # sum_sync = 255
    await agent_a.driver.send(AdderTransaction(a=255, b=255, valid_in=1))   # sum_sync = 511

    # --- 2. Hit illegal condition valid_in=1 & rst=1 -------------
    dut.rst_A.value = 1
    await agent_a.driver.send(AdderTransaction(a=0, b=0, valid_in=1))
    await agent_a.driver.send(AdderTransaction(a=1, b=1, valid_in=1))
    dut.rst_A.value = 0

    # --- 3. Hit overflow bins (legal 8-bit values) ---------------
    overflow_vectors = [
        (255, 1),     # 256
        (200, 100),   # 300
        (128, 200),   # 328
        (255, 255),   # 510
    ]

    for a, b in overflow_vectors:
        await agent_a.driver.send(AdderTransaction(a=a, b=b, valid_in=1))

    # --- 4. Hit valid_rise × sum_sync ----------------------------
    # valid_rise happens when valid_in goes 0 → 1

    # First case: sum_sync = 255
    await agent_a.driver.send(AdderTransaction(a=0,   b=0,   valid_in=0))
    await agent_a.driver.send(AdderTransaction(a=255, b=0,   valid_in=1))

    # Second case: sum_sync = 511
    await agent_a.driver.send(AdderTransaction(a=0,   b=0,   valid_in=0))
    await agent_a.driver.send(AdderTransaction(a=255, b=255, valid_in=1))

    # ============================================================
    # END DIRECTED STIMULUS
    # ============================================================
    cocotb.log.info("\nFirst Iterations of Loop Displayed for Debugging\n")
    # Random traffic
    for _ in range(200): # 20000 Set the desired number of cycles for the test
        await agent_a.driver.send(AdderTransaction.random())
        await agent_b.driver.send(AdderTransaction.random())
        await Timer(1, "ns")
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
    env.finalize()











# test_dual_agent.py

# import random
# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# from sim.tb.coverage import FunctionalCoverage
# from sim.tb.env import Env
# from sim.tb.agent import Agent
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.sequences import AdderTransaction


# def random_txn():
#     return AdderTransaction(
#         a=random.randint(0, 255),
#         b=random.randint(0, 255),
#         valid_in=random.randint(0, 1),
#     )


# @cocotb.test()
# async def dual_agent(dut):

#     # Clock
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

#     # Agents
#     agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
#     agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

#     # Coverage + scoreboard + env
#     coverage = FunctionalCoverage()
#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard, coverage)
#     await env.start()

#     # Reset both channels
#     await agent_a.driver.reset()
#     await agent_b.driver.reset()

#     # REQUIRED: one non-valid cycle BEFORE any valid sequence
#     await agent_a.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
#     await agent_b.driver.send(AdderTransaction(a=0, b=0, valid_in=0))
#     await Timer(10, "ns")

#     # Dual-agent randomized traffic
#     for _ in range(200):

#         await agent_a.driver.send(random_txn())
#         await agent_b.driver.send(random_txn())

#         # occasional resets to stress both channels
#         if random.random() < 0.02:
#             await agent_a.driver.reset()
#         if random.random() < 0.02:
#             await agent_b.driver.reset()

#         await Timer(10, "ns")

#     await Timer(200, "ns")
#     env.finalize()
#     assert True

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
# async def dual_agent(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     coverage = FunctionalCoverage()
#     scoreboard = Scoreboard()

#     agent_a = Agent("A", Driver(dut, dut.clk, channel="A"), Monitor(dut, dut.clk, channel="A"))
#     agent_b = Agent("B", Driver(dut, dut.clk, channel="B"), Monitor(dut, dut.clk, channel="B"))

#     env = Env(agent_a, agent_b, scoreboard, coverage)
#     await env.start()

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



# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import Timer

# from sim.tb.env import Env
# from sim.tb.agent import Agent
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.sequences import AdderTransaction

# @cocotb.test()
# async def dual_agent(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     agent_a = Agent("A", Driver(dut.adifA, dut.clk, ""), Monitor(dut.adifA, dut.clk, ""))
#     agent_b = Agent("B", Driver(dut.adifB, dut.clk, ""), Monitor(dut.adifB, dut.clk, ""))

#     scoreboard = Scoreboard()
#     env = Env(agent_a, agent_b, scoreboard)
#     await env.start()

#     # Reset both channels
#     dut.adifA.rst.value = 1
#     dut.adifB.rst.value = 1
#     await Timer(20, "ns")
#     dut.adifA.rst.value = 0
#     dut.adifB.rst.value = 0
#     await Timer(20, "ns")

#     # Drive both channels on separate cycles (Option 1)
#     for i in range(5):

#         # Channel A drives first
#         await agent_a.driver.send(
#         AdderTransaction(a=i, b=i+1, valid_in=1)
#         )
#         await Timer(10, "ns")   # allow DUT to sample A

#         # Channel B drives next
#         await agent_b.driver.send(
#         AdderTransaction(a=i+2, b=i+3, valid_in=1)
#         )
#         await Timer(10, "ns")   # allow DUT to sample B


#     env.finalize()

