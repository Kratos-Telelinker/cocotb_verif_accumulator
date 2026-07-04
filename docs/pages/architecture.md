# Verification Architecture

This page describes the full architecture of the dual‑channel adder verification environment.
The environment is designed using a modular, UVM‑inspired structure implemented entirely in Python
via Cocotb. It supports multi‑agent stimulus, functional coverage, scoreboarding, and regression
automation.

---

# 🧩 Overview

The verification environment consists of:

- **DUT Wrapper**  
- **Two independent agents (Channel A and Channel B)**  
- **Drivers**  
- **Monitors**  
- **Scoreboard**  
- **Functional Coverage Model**  
- **Environment (Env)**  
- **Regression runner**

Each component is isolated, reusable, and designed for clarity and extensibility.

---

# 🏗 DUT Architecture

The DUT exposes two independent channels:


