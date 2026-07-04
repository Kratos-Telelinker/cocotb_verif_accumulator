# Makefile for cocotb_modified3
PYTHON := ./py311/bin/python3
export PYTHON
ifndef VIRTUAL_ENV
$(error Please activate the py311 virtual environment: source py311/bin/activate)
endif


SIM ?= verilator
TOPLEVEL_LANG = verilog
TOPLEVEL = dut_wrapper


VERILOG_SOURCES = rtl/dut_wrapper.sv rtl/top_level.sv

.PHONY: results.xml
# Enable tracing (FST is smaller; VCD also works)
EXTRA_ARGS += --trace
EXTRA_ARGS += -Irtl
EXTRA_ARGS += --coverage
export VERILATOR_COVERAGE=1


COVERAGE_JSON = coverage.json
COVERAGE_HTML = coverage.html


COCOTB_MAKEFILES := $(shell ./py311/bin/python3 -m cocotb_tools.config --makefiles)
include $(COCOTB_MAKEFILES)/Makefile.sim



# Convenience targets
run:
	$(MAKE) SIM=$(SIM)

waves:
	$(MAKE) SIM=$(SIM) WAVES=1

coverage:
	$(MAKE) SIM=$(SIM)
	@echo "Coverage JSON: $(COVERAGE_JSON)"
	@echo "Coverage HTML: $(COVERAGE_HTML)"

coverage-clean:
	rm -f $(COVERAGE_JSON) $(COVERAGE_HTML)

merge-coverage:
	python tools/merge_coverage.py merged_coverage.json coverage_*.json
	@echo "Merged coverage: merged_coverage.json / merged_coverage.html"

view-coverage:
	tools/view_coverage.sh

view-waves:
	tools/view_waves.sh

regression:
	tools/run_regression.sh

coverage-dashboard:
	python tools/coverage_dashboard.py

stimulus-plot:
	python tools/stimulus_plot.py
# Checks tool versions and environment sanity

PYTHON := ./py311/bin/python3
PIP := ./py311/bin/pip



check-python:
	@echo "Checking Python..."
	@$(PYTHON) --version

check-pip:
	@echo "Checking pip..."
	@$(PIP) --version

check-cocotb:
	@echo "Checking cocotb..."
	@$(PYTHON) -c "import pkgutil; print('cocotb present:', pkgutil.find_loader('cocotb') is not None)"



check-verilator:
	@echo "Checking Verilator..."
	@verilator --version

check-gtkwave:
	@echo "Checking GTKWave..."
	@gtkwave --version

check-build-tools:
	@echo "Checking gcc..."
	@gcc --version | head -n 1
	@echo "Checking g++..."
	@g++ --version | head -n 1
	@echo "Checking make..."
	@make --version | head -n 1
	@echo "Checking pkg-config..."
	@pkg-config --version

check-all: check-python check-pip check-cocotb check-verilator check-gtkwave check-build-tools
	@echo "Environment looks good."
clean::
	@echo "Cleaning build and regression artifacts..."
	@rm -rf sim_build
	@rm -rf regression_results
	@rm -rf coverage_html
	@rm -rf func_cov_html
	@rm -rf dashboard_html
	@rm -rf .pytest_cache
	@rm -rf waves
	@rm -rf logs
	@echo "Cleanup complete."

