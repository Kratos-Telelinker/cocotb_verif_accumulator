# Waveform Generation (Verilator + Cocotb)

Waveform dumping is an essential part of debugging and analyzing DUT behavior.  
This verification environment uses **Verilator** to generate **VCD** or **FST** waveform files that
can be viewed in **GTKWave**.

This page explains how waveform dumping works, how to enable it, where files are stored, and how to
use them effectively.

---

# 🎛 Enabling Waveform Dumps

Waveform dumping is controlled by Verilator.  
To enable tracing, set the environment variable:


