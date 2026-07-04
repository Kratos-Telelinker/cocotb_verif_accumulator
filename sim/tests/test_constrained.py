import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import random

BIN_RANGES = [
    (0, 15),
    (16, 31),
    (32, 63),
    (64, 127),
    (128, 255)
]

def rand_from_bins(i):
    low, high = BIN_RANGES[i % len(BIN_RANGES)]
    return random.randint(low, high)


@cocotb.test()
async def constrained(dut):

    cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

    # Initial reset
    dut.rst_A.value = 1
    dut.valid_in_A.value = 0
    dut.a_A.value = 0
    dut.b_A.value = 0
    await RisingEdge(dut.clk)
    dut.rst_A.value = 0

    mid_reset_point = 250

    for i in range(500):

        # Mid-test reset
        if i == mid_reset_point:
            dut.rst_A.value = 1
            dut.valid_in_A.value = 1
            await RisingEdge(dut.clk)
            dut.valid_in_A.value = 0
            await RisingEdge(dut.clk)
            dut.rst_A.value = 0

        # Drive constrained stimulus
        dut.valid_in_A.value = 1
        dut.a_A.value = rand_from_bins(i)
        dut.b_A.value = rand_from_bins(i)

        await RisingEdge(dut.clk)
        dut.valid_in_A.value = 0

        # Idle cycles
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)



# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge
# import random

# from sim.tb.env import Env
# from sim.tb.agent import Agent
# from sim.tb.driver import Driver
# from sim.tb.monitor import Monitor
# from sim.tb.scoreboard import Scoreboard
# from sim.tb.sequences import AdderTransaction

# BIN_RANGES = [
#     (0, 15),
#     (16, 31),
#     (32, 63),
#     (64, 127),
#     (128, 255)
# ]

# def rand_from_bins(i):
#     low, high = BIN_RANGES[i % len(BIN_RANGES)]
#     return random.randint(low, high)

# @cocotb.test()
# async def constrained(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     agent_a = Agent("A", Driver(dut.adifA, dut.clk, ""), Monitor(dut.adifA, dut.clk, ""))
#     scoreboard = Scoreboard()
#     env = Env(agent_a, None, scoreboard)
#     await env.start()

#     # Initial reset
#     await agent_a.reset()

#     mid_reset_point = 250


#     for i in range(500):

#         if i == mid_reset_point:
#             await agent_a.reset()

#         txn = AdderTransaction(
#             a=rand_from_bins(i),
#             b=rand_from_bins(i),
#             valid_in=1
#         )

#         await agent_a.send(txn)

#         for _ in range(2):
#             await RisingEdge(dut.clk)

#     env.finalize()





