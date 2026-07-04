#!/usr/bin/env bash

echo "=== cocotb_modified3 Environment Verification ==="

# Python
echo "[Python]"
./py311/bin/python3 --version || { echo "Python missing"; exit 1; }

# Cocotb
echo "[cocotb]"
./py311/bin/python3 - << 'EOF'
import pkgutil
print("cocotb present:", pkgutil.find_loader("cocotb") is not None)
EOF

# Verilator
echo "[Verilator]"
verilator --version || { echo "Verilator missing"; exit 1; }

# GTKWave
echo "[GTKWave]"
gtkwave --version || { echo "GTKWave missing"; exit 1; }

# Build tools
echo "[Build Tools]"
gcc --version | head -n 1
g++ --version | head -n 1
make --version | head -n 1
pkg-config --version

echo "=== Verification Complete ==="

