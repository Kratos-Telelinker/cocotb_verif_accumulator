#!/usr/bin/env bash


export PYTEST_ADDOPTS="--assert=plain"

export PATH=$PWD/py311/bin:$PATH
export PYTHONPATH=$PWD/py311/lib/python3.11/site-packages
export LD_LIBRARY_PATH=$PWD/py311/lib/python3.11/site-packages/cocotb/libs:$LD_LIBRARY_PATH
export COCOTB_SIM=1


set -e

echo ""
echo "=== Regression Runner ==="
echo ""

rm -rf sim_build
mkdir -p regression_results

export VERILATOR_COVERAGE=1

TESTS=(
"sim.tests.test_smoke"
"sim.tests.test_basic"
"sim.tests.test_dual_agent"
"sim.tests.test_dual_constrained"
"sim.tests.test_directed_channel_A"
"sim.tests.test_directed_channel_B"
"sim.tests.test_constrained"
"sim.tests.test_randomized"
"sim.tests.test_randomized_stress"
"sim.tests.test_reset_randomized"
"sim.tests.test_cross_closure"

)

i=1
for T in "${TESTS[@]}"; do
    echo ""
    echo "Running test $i: $T"
    echo ""

    rm -f results.xml

    COCOTB_TEST_MODULES=$T TESTCASE= make results.xml

    # Save Verilator coverage
    if [ -f coverage.dat ]; then
        cp coverage.dat "regression_results/coverage_${i}.dat"
    fi

    # Save results.xml
    if [ -f results.xml ]; then
        cp results.xml "regression_results/results_${i}.xml"
    fi

    # Save waveform
    if [ -f dump.fst ]; then
        cp dump.fst "regression_results/waves_${i}.fst"
    elif [ -f dump.vcd ]; then
        cp dump.vcd "regression_results/waves_${i}.vcd"
    fi

    i=$((i+1))
done

# echo ""
# echo "=== Exporting Functional Coverage (YAML) ==="
# echo ""

# python3 - << 'EOF'
# from sim.tb.coverage import export_coverage
# export_coverage("regression_results/functional_coverage.yaml")
# print("Functional coverage exported.")
# EOF


echo ""
echo "=== Converting Functional Coverage YAML → JSON ==="
echo ""

python3 tools/convert_coverage_yaml_to_json.py \
    regression_results/functional_coverage.yaml \
    regression_results/functional_coverage.json

echo ""
echo "=== Merging Verilator Coverage ==="
echo ""

verilator_coverage --write-info coverage.info regression_results/coverage_*.dat

echo ""
echo "=== Generating HTML Code Coverage ==="
echo ""

rm -rf coverage_html
genhtml coverage.info -o coverage_html

echo ""
echo "=== Merging Functional Coverage JSON ==="
echo ""

python3 tools/merge_coverage_json.py \
    regression_results/merged_coverage.json \
    regression_results/functional_coverage.json

echo ""
echo "=== Generating Functional Coverage HTML ==="
echo ""

rm -rf func_cov_html
python3 tools/functional_cov_to_html.py \
    regression_results/merged_coverage.json \
    func_cov_html

echo ""
echo "=== Functional Coverage Summary ==="
echo ""

python3 tools/print_functional_summary.py \
    regression_results/merged_coverage.json

echo ""
echo "=== Per‑Test Functional Coverage ==="
echo ""

python3 tools/print_per_test_summary.py

echo ""
echo "=== Generating Unified Dashboard ==="
echo ""

rm -rf dashboard_html
python3 tools/coverage_dashboard.py \
    coverage_html \
    func_cov_html \
    dashboard_html

echo ""
echo "=== Regression Complete ==="
echo "Code Coverage HTML:      coverage_html/index.html"
echo "Functional Coverage HTML: func_cov_html/index.html"
echo "Dashboard:               dashboard_html/index.html"
echo ""
