# Functional Coverage

Functional coverage in this verification environment is implemented using
`cocotb_coverage` and is designed to measure stimulus completeness across both
channels of the dual‑channel adder. The coverage model includes:

- Operand bins
- Pattern bins
- Overflow bins
- Illegal condition bins
- Temporal bins
- Cross coverage
- Coverage thresholds and gating

Coverage is sampled on every monitor transaction and exported in YAML/XML formats
for regression analysis.

---

## 📐 Coverage Architecture

Coverage is defined in `external/coverage.py` and is sampled through the
`FunctionalCoverage` class. The model is structured into:

- **Base coverpoints**  
- **Cross coverage groups**  
- **Temporal coverage**  
- **Illegal condition detection**  
- **Regression‑level merging**  
- **Coverage threshold enforcement**

Coverage is sampled via:

```python
sample_coverage(sample)

