#!/bin/bash
cd "$(dirname "$0")"

# Clean previous build
rm -rf sim_build

# Activate venv
source py311/bin/activate

# Enable Verilator coverage
export VERILATOR_COVERAGE=1

# Run tests
pytest -v sim -s "$@"

# Generate LCOV file
if [ -f sim_build/coverage.dat ]; then
    echo "Generating coverage.info..."
    verilator_coverage --write-info coverage.info sim_build/coverage.dat
else
    echo "ERROR: coverage.dat not found."
    exit 1
fi

# Generate HTML report
if command -v genhtml >/dev/null 2>&1; then
    echo "Generating HTML report..."
    genhtml coverage.info -o coverage_html
    echo "HTML report written to coverage_html/index.html"

    # Automatically open the report
    if command -v xdg-open >/dev/null 2>&1; then
        xdg-open coverage_html/index.html &
    else
        echo "xdg-open not found. Open coverage_html/index.html manually."
    fi
else
    echo "genhtml not installed. Install with: sudo apt install lcov"
fi
