# cocotb_verif_accumulator
A structured, extensible cocotb verification environment built for hardware simulation, regression automation, waveform analysis, and toolchain validation. This project provides a clean foundation for building UVM‑style verification flows using Python and cocotb.

---

## 1. Overview

`cocotb_modified3` is a self‑contained verification workspace featuring:

- A dedicated Python 3.11 virtual environment (`py311/`)
- A Makefile‑based tool validation suite
- Optional cocotb simulation directory structure
- Support for Verilator‑based simulation
- Hooks for waveform generation (GTKWave)
- A foundation for advanced verification architecture (scoreboards, monitors, drivers, coverage)

This environment is designed for engineers who want a reproducible, minimal‑friction setup for hardware verification using Python.

To note two documents are extremely import which are both located in the docs/pdf folder
    1.    Tools_confg.pdf
    2.    Running_Simulation Tests.pdf
---

## 2. Directory Structure


<img width="1220" height="805" alt="image" src="https://github.com/user-attachments/assets/546ad838-6bc9-434e-b7b6-2f8d91ef8dda" />


## 3. Toolchain Validation

The root Makefile provides a complete environment sanity check:

make check-all

This validates:

- Python 3.11
- pip
- cocotb installation
- Verilator version
- GTKWave availability
- gcc / g++
- make
- pkg-config

This ensures your simulation environment is ready before running any tests.

---

## 4. Simulation Flow

### 4.1 Running a Simulation

Inside `sim/`:
cd sim
make

This triggers:

1. Verilator compilation of the DUT  
2. Cocotb test execution  
3. Waveform generation (if enabled)  
4. Log output to `sim/logs/`  
5. Waveform dumps to `sim/waves/`

### 4.2 Viewing Waveforms
gtkwave waves/dump.vcd

or `.fst` depending on your Verilator configuration.

---

## 5. Verification Architecture

This project supports a modular verification architecture:

### **Drivers**
Generate stimulus and push transactions into the DUT.

### **Monitors**
Observe DUT outputs and capture transactions.

### **Scoreboards**
Compare expected vs actual behavior.

### **Coverage**
Track functional coverage points and simulation completeness.

### **Logging**
Centralized logging for stimulus, DUT activity, and results.

Example structure:
sim/modules/
│
├── driver.py
├── monitor.py
├── scoreboard.py
└── coverage.py

run_regression

This can run:

- Multiple DUT configurations  
- Multiple testbenches  
- Randomized seeds  
- Coverage collection  
- Summary reports  

---

## 7. Coverage

### **Functional Coverage**
Implemented in Python:

- Coverpoints  
- Cross coverage  
- Bins  
- Sampling hooks  

### **Code Coverage**
Enabled via Verilator:
verilator --coverage

Coverage reports can be collected and analyzed after simulation.

---

## 8. Logging

Recommended logging structure:
sim/logs/
│
├── sim_YYYYMMDD_HHMM.log
├── driver.log
├── monitor.log
└── scoreboard.log

Use Python’s `logging` module for consistent formatting.

---

## 9. Extending the Project

You can expand this project into:

- Full UVM‑style cocotb environments  
- Multi‑DUT verification  
- Bus functional models (BFMs)  
- AXI/APB/AHB protocol verification  
- Randomized stimulus generation  
- Constraint‑based stimulus  
- CI/CD integration (GitHub Actions, GitLab CI)  
- Documentation via GitHub Pages  

---

## 10. Troubleshooting

### **Makefile Errors**
- Ensure recipe lines begin with **TAB**, not spaces  
- Avoid multi‑line heredocs  
- Use Python one‑liners for environment checks  

### **Python Environment Issues**
Recreate the venv:
rm -rf py311
python3.11 -m venv py311
source py311/bin/activate
pip install cocotb

### **Verilator Issues**
Check version:
verilator --version

Ensure `pkg-config` is installed.

---

## 11. License

This project is provided as-is for personal development and experimentation.
-----------------------------------------------------------------------------
Why your sequence caused the issue
Your exact steps:

Copied entire project to Windows

Created a local Git repo on Windows

Pushed everything (including py311 venv) to GitHub

Cloned repo into Linux

Linux received Windows venv with missing execute bits

Regression script tried to run ./py311/bin/python3

Linux said “Permission denied”

You fixed it with chmod -R u+x py311

This is exactly what happens when a Windows venv is cloned into Linux.


The correct long‑term fix
Never commit virtual environments to Git.
Instead:

Add this to .gitignore:

Code
py311/
venv/
.env/
Delete the venv from the repo:

bash
git rm -r --cached py311
git commit -m "Remove venv from repo"
git push
Recreate the venv on Linux:

bash
python3 -m venv py311
source py311/bin/activate
pip install -r requirements.txt
This gives you:

correct Linux permissions

correct Linux binaries

correct cocotb-config

correct Makefile paths

no more execute‑bit problems

⭐ Should you keep using chmod -R u+x py311?
Only as a temporary fix.

Requirements.txt 
# Python packages for cocotb_modified3 (Python 3.11)

cocotb==2.0.1
cocotb-test==0.2.2
cocotb-coverage==1.1.0

pytest==7.4.4
pytest-xdist==3.5.0

find-libpython==0.4.0
setuptools>=68
wheel>=0.42

# Optional but recommended
pyuvm==2.8.0
numpy==1.26.4
rich==13.7.1
packaging==24.0
