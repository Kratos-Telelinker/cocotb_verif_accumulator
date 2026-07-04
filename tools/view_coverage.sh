#!/usr/bin/env bash

# Simple helper to view coverage results from cocotb_coverage
# Works with coverage.json and coverage.html

COV_JSON="coverage.json"
COV_HTML="coverage.html"

echo ""
echo "=== Coverage Viewer ==="
echo ""

if [ -f "$COV_JSON" ]; then
    echo "Found JSON coverage: $COV_JSON"
else
    echo "No coverage.json found."
fi

if [ -f "$COV_HTML" ]; then
    echo "Found HTML coverage: $COV_HTML"
else
    echo "No coverage.html found."
fi

echo ""
echo "Opening HTML coverage report (if available)..."
echo ""

# Linux (xdg-open), macOS (open), Windows Git Bash (cmd.exe /c start)
if command -v xdg-open >/dev/null 2>&1; then
    xdg-open "$COV_HTML" 2>/dev/null
elif command -v open >/dev/null 2>&1; then
    open "$COV_HTML" 2>/dev/null
else
    cmd.exe /c start "$COV_HTML" 2>/dev/null
fi

echo ""
echo "Done."
