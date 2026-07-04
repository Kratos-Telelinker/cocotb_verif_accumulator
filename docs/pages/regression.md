# Regression System

The regression system is responsible for executing the full verification suite, collecting
functional coverage, enforcing coverage thresholds, generating waveform dumps, and producing
final pass/fail results. It is implemented using Cocotb, Verilator, and a custom regression
script (`run_regression.sh`).

This page explains how regression works, how tests are organized, how coverage is merged, and how
results are exported.

---

# 🧪 Test Suite Overview

The regression executes all tests located in:


