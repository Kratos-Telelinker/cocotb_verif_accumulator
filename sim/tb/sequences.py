# sim/tb/sequences.py

import random
from cocotb.triggers import Timer
from cocotb_coverage.coverage import coverage_db

# Correct import – NO circular import
from sim.tb.driver import AdderTransaction

A_BINS = [0, 1, 2, 3, 4, 8, 16, 32, 64, 128, 255]
B_BINS = A_BINS
# ---------------------------------------------------------------------------
# 0) Constrained random transaction (old-style bins)
# ---------------------------------------------------------------------------
def constrained_random_txn():
    """
    Constrained random generator used by test_dual_constrained.
    Produces values from your 11-bin distribution.
    """
    A_BINS = [0, 1, 2, 3, 4, 8, 16, 32, 64, 128, 255]
    B_BINS = A_BINS

    return AdderTransaction(
        a=random.choice(A_BINS),
        b=random.choice(B_BINS),
        valid_in=random.randint(0, 1),
    )


# ---------------------------------------------------------------------------
# 1) Directed sequence
# ---------------------------------------------------------------------------
async def reset_sequence(dut, prefix: str = ""):
    getattr(dut, f"{prefix}rst").value = 1
    getattr(dut, f"{prefix}valid_in").value = 0
    await Timer(10, unit="ns")
    getattr(dut, f"{prefix}rst").value = 0
    await Timer(10, unit="ns")


async def directed_sequence(driver):
    for a in range(4):
        for b in range(4):
            txn = AdderTransaction(a, b, valid_in=1)
            await driver.send(txn)


# ---------------------------------------------------------------------------
# 2) Pure random
# ---------------------------------------------------------------------------
async def random_sequence(driver, count: int = 100):
    for _ in range(count):
        txn = AdderTransaction(
            random.randint(0, 255),
            random.randint(0, 255),
            random.randint(0, 1),
        )
        await driver.send(txn)


# ---------------------------------------------------------------------------
# 3) Constrained (bias b high)
# ---------------------------------------------------------------------------
async def constrained_sequence(driver, count: int = 100):
    for _ in range(count):
        a = random.randint(0, 255)
        b = random.randint(200, 255)
        txn = AdderTransaction(a, b, valid_in=1)
        await driver.send(txn)


# ---------------------------------------------------------------------------
# 4) Corner-case patterns
# ---------------------------------------------------------------------------
async def corner_case_sequence(driver):
    patterns = [
        (0, 0, 1),
        (0, 255, 1),
        (255, 0, 1),
        (255, 255, 1),
        (0, 1, 0),
        (1, 0, 0),
    ]
    for a, b, v in patterns:
        txn = AdderTransaction(a, b, v)
        await driver.send(txn)


# ---------------------------------------------------------------------------
# 5) Coverage-driven top-up (single driver)
# ---------------------------------------------------------------------------
def get_global_coverage() -> float:
    """
    Computes overall functional coverage percentage across all coverpoints.
    Uses public 'coverage' attribute of each coverpoint.
    """
    total = 0.0
    count = 0

    for cp in coverage_db.values():
        total += cp.coverage
        count += 1

    return total / count if count > 0 else 0.0


async def coverage_driven_sequence(
    driver,
    target_coverage: float = 95.0,
    max_iters: int = 10000,
):
    iters = 0
    while get_global_coverage() < target_coverage and iters < max_iters:
        txn = AdderTransaction(
            random.randint(0, 255),
            random.randint(0, 255),
            random.randint(0, 1),
        )
        await driver.send(txn)
        iters += 1


# ---------------------------------------------------------------------------
# 6) Coverage-driven cross targeting (Option 3, dual drivers)
# ---------------------------------------------------------------------------
async def coverage_driven_cross_sequence(driver_a, driver_b, repeat: int = 1):
    """
    Option 3: systematically hit all (a, b) cross bins on both channels.

    repeat: how many times to loop over the full cross space
            (use >1 if you want more samples per bin).
    """
    for _ in range(repeat):
        for a in A_BINS:
            for b in B_BINS:
                txn_a = AdderTransaction(a=a, b=b, valid_in=1)
                txn_b = AdderTransaction(a=a, b=b, valid_in=1)

                await driver_a.send(txn_a)
                await driver_b.send(txn_b)

# ---------------------------------------------------------------------------
# Generator classes
# ---------------------------------------------------------------------------
class OverflowSequence:
    """Generate transactions that force overflow (a + b > 255)."""

    def __init__(self, count=100):
        self.count = count

    def generate(self):
        for _ in range(self.count):
            a = random.randint(128, 255)
            b = random.randint(128, 255)
            yield AdderTransaction(a=a, b=b, valid_in=1)


class ZeroSequence:
    """Generate transactions where both operands are zero."""

    def __init__(self, count=100):
        self.count = count

    def generate(self):
        for _ in range(self.count):
            yield AdderTransaction(a=0, b=0, valid_in=1)


class AlternatingValidSequence:
    """Generate transactions with alternating valid_in (1,0,1,0...)."""

    def __init__(self, count=100):
        self.count = count

    def generate(self):
        valid = 1
        for _ in range(self.count):
            a = random.randint(0, 255)
            b = random.randint(0, 255)
            yield AdderTransaction(a=a, b=b, valid_in=valid)
            valid ^= 1
