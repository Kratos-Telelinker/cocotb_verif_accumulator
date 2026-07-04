#!/usr/bin/env bash

# --- CONFIG ---
PYTHON=python3

echo "=== Standard Library Modules ==="
$PYTHON << 'EOF'
import sysconfig, pkgutil
stdlib = sysconfig.get_paths()["stdlib"]
mods = sorted(name for _, name, _ in pkgutil.iter_modules([stdlib]))
for m in mods:
    print(m)
EOF

echo
echo "=== Installed Packages (pip/pkg_resources) ==="
$PYTHON << 'EOF'
import pkg_resources
pkgs = sorted(f"{p.key}=={p.version}" for p in pkg_resources.working_set)
for p in pkgs:
    print(p)
EOF

