# cocotb_modified3
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

---

## 2. Directory Structure

── coverage.dat
├── coverage_html
│   ├── amber.png
│   ├── cmd_line
│   ├── emerald.png
│   ├── gcov.css
│   ├── glass.png
│   ├── index.html
│   ├── index-sort-f.html
│   ├── index-sort-l.html
│   ├── rtl
│   │   └── rtl
│   ├── ruby.png
│   ├── snow.png
│   └── updown.png
├── coverage.info
├── coverage.json
├── dashboard_html
│   └── index.html
├── debug.log
├── docs
│   ├── _config.yml
│   ├── diagrams
│   │   ├── architecture_ascii.txt
│   │   └── architecture.svg
│   ├── pages
│   │   ├── architecture.md
│   │   ├── coverage.md
│   │   ├── index.md
│   │   ├── regression.md
│   │   └── waveforms.md
│   └── pdf
│       ├── verification_guide.pdf
│       └── verification_guide.tex
├── dump.vcd
├── external
│   ├── coverage.py
│   ├── __init__.py
│   └── __pycache__
│       ├── coverage.cpython-311-pytest-9.1.1.pyc
│       └── __init__.cpython-311-pytest-9.1.1.pyc
├── func_cov_html
│   └── index.html
├── func_cov.json
├── func_cov.xml
├── func_cov.yaml
├── log.txt
├── Makefile
├── py311
│   ├── bin
│   │   ├── activate
│   │   ├── activate.csh
│   │   ├── activate.fish
│   │   ├── Activate.ps1
│   │   ├── cocotb-config
│   │   ├── f2py
│   │   ├── find_libpython
│   │   ├── fonttools
│   │   ├── numpy-config
│   │   ├── pip
│   │   ├── pip3
│   │   ├── pip3.11
│   │   ├── pyftmerge
│   │   ├── pyftsubset
│   │   ├── pygmentize
│   │   ├── py.test
│   │   ├── pytest
│   │   ├── python -> python3.11
│   │   ├── python3 -> python3.11
│   │   ├── python3.11 -> /usr/local/bin/python3.11
│   │   ├── python_inventory.sh
│   │   └── ttx
│   ├── include
│   │   └── python3.11
│   ├── lib
│   │   └── python3.11
│   ├── lib64 -> lib
│   ├── pyvenv.cfg
│   └── share
│       └── man
├── pyproject.toml
├── README.md
├── regression_results
│   ├── coverage_10.dat
│   ├── coverage_11.dat
│   ├── coverage_1.dat
│   ├── coverage_2.dat
│   ├── coverage_3.dat
│   ├── coverage_4.dat
│   ├── coverage_5.dat
│   ├── coverage_6.dat
│   ├── coverage_7.dat
│   ├── coverage_8.dat
│   ├── coverage_9.dat
│   ├── functional_coverage.json
│   ├── functional_coverage_regression.xml
│   ├── functional_coverage_regression.yaml
│   ├── functional_coverage.xml
│   ├── functional_coverage.yaml
│   ├── merged_coverage.json
│   ├── results_10.xml
│   ├── results_11.xml
│   ├── results_1.xml
│   ├── results_2.xml
│   ├── results_3.xml
│   ├── results_4.xml
│   ├── results_5.xml
│   ├── results_6.xml
│   ├── results_7.xml
│   ├── results_8.xml
│   ├── results_9.xml
│   ├── waves_10.vcd
│   ├── waves_11.vcd
│   ├── waves_1.vcd
│   ├── waves_2.vcd
│   ├── waves_3.vcd
│   ├── waves_4.vcd
│   ├── waves_5.vcd
│   ├── waves_6.vcd
│   ├── waves_7.vcd
│   ├── waves_8.vcd
│   └── waves_9.vcd
├── requirements.txt
├── results.xml
├── rtl
│   ├── adder_if.sv
│   ├── dut_wrapper.sv
│   └── top_level.sv
├── run_cov.sh
├── runtest
├── sim
│   ├── conftest.py
│   ├── coverage_export.py
│   ├── __init__.py
│   ├── __pycache__
│   │   ├── conftest.cpython-311-pytest-9.1.1.pyc
│   │   └── __init__.cpython-311-pytest-9.1.1.pyc
│   ├── tb
│   │   ├── agent.py
│   │   ├── driver.py
│   │   ├── env.py
│   │   ├── __init__.py
│   │   ├── monitor.py
│   │   ├── __pycache__
│   │   ├── scoreboard.py
│   │   ├── sequences.py
│   │   └── stimulus_log.py
│   └── tests
│       ├── __init__.py
│       ├── __pycache__
│       ├── smoke_channel_B.py
│       ├── test_basic.py
│       ├── test_constrained.py
│       ├── test_cross_closure.py
│       ├── test_direct_drive_A.py
│       ├── test_directed_channel_A.py
│       ├── test_directed_channel_B.py
│       ├── test_dual_agent.py
│       ├── test_dual_constrained.py
│       ├── test_randomized.py
│       ├── test_randomized_stress.py
│       ├── test_reset_randomized.py
│       └── test_smoke.py
├── sim_build
│   ├── verilated_cov.d
│   ├── verilated_cov.o
│   ├── verilated.d
│   ├── verilated_dpi.d
│   ├── verilated_dpi.o
│   ├── verilated.o
│   ├── verilated_threads.d
│   ├── verilated_threads.o
│   ├── verilated_vcd_c.d
│   ├── verilated_vcd_c.o
│   ├── verilated_vpi.d
│   ├── verilated_vpi.o
│   ├── verilator.d
│   ├── verilator.o
│   ├── Vtop
│   ├── Vtop___024root__DepSet_h84412442__0.cpp
│   ├── Vtop___024root__DepSet_h84412442__0__Slow.cpp
│   ├── Vtop___024root__DepSet_heccd7ead__0.cpp
│   ├── Vtop___024root__DepSet_heccd7ead__0__Slow.cpp
│   ├── Vtop___024root.h
│   ├── Vtop___024root__Slow.cpp
│   ├── Vtop___024unit__DepSet_hff17caec__0__Slow.cpp
│   ├── Vtop___024unit.h
│   ├── Vtop___024unit__Slow.cpp
│   ├── Vtop__ALL.a
│   ├── Vtop__ALL.cpp
│   ├── Vtop__ALL.d
│   ├── Vtop__ALL.o
│   ├── Vtop_classes.mk
│   ├── Vtop.cpp
│   ├── Vtop__Dpi.cpp
│   ├── Vtop__Dpi.h
│   ├── Vtop.h
│   ├── Vtop.mk
│   ├── Vtop__pch.h
│   ├── Vtop__Syms.cpp
│   ├── Vtop__Syms.h
│   ├── Vtop__Trace__0.cpp
│   ├── Vtop__Trace__0__Slow.cpp
│   ├── Vtop__TraceDecls__0__Slow.cpp
│   ├── Vtop__ver.d
│   └── Vtop__verFiles.dat
├── stimulus_log.csv
├── tools
│   ├── convert_coverage_yaml_to_json.py
│   ├── coverage_dashboard.py
│   ├── functional_cov_to_html.py
│   ├── merge_coverage_json.py
│   ├── merge_coverage.py
│   ├── print_functional_summary.py
│   ├── print_per_test_summary.py
│   ├── run_regression.sh
│   ├── stimulus_plot.py
│   ├── view_coverage.sh
│   └── view_waves.sh
├── tools.txt
└── verify_env.sh


---

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




