# ConstraintsPatch
- A Python script to automatically patch C code by moving local stack arrays to global scope, useful for fixing ESP32 memory constraints in embedded AI models.

## Files
 - `constraints_patch.py` — main patching script
 - `model.c/.h` — sample C file with stack arrays for testing

## Features
 - Detects and moves double arrays from local to global scope to avoid stack overflows
 - Deduplicates arrays for efficiency
 - Inserts globals at the top after includes
 - Command-line interface for easy integration into build processes
 - Configurable regex patterns for different array types

## Configuration setting is available in config.py

## Usage
Run the script on a C file:
```bash
python constraints_patch.py path/to/your/model.c
```

Or import as a module: (Can be appended to converter.py)
```python
from constraints_patch import apply_constraints_patch
apply_constraints_patch("model.c")
```

## An example.c file for testing/demo is provided.