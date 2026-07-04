#!/usr/bin/env bash

# Waveform viewer helper for Verilator + cocotb
# Automatically opens dump.fst or dump.vcd if present

echo ""
echo "=== Waveform Viewer ==="
echo ""

FST="dump.fst"
VCD="dump.vcd"

if [ -f "$FST" ]; then
    WAVEFILE="$FST"
elif [ -f "$VCD" ]; then
    WAVEFILE="$VCD"
else
    echo "No waveform file found (dump.fst or dump.vcd)."
    exit 1
fi

echo "Found waveform: $WAVEFILE"
echo "Opening..."

# Linux (gtkwave), macOS (open), Windows Git Bash (cmd.exe /c start)
if command -v gtkwave >/dev/null 2>&1; then
    gtkwave "$WAVEFILE" &
elif command -v open >/dev/null 2>&1; then
    open "$WAVEFILE"
else
    cmd.exe /c start "$WAVEFILE"
fi

echo ""
echo "Done."
