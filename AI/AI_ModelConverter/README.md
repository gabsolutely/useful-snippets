# AI_ModelConverter
- A configurable Python script to convert trained scikit-learn models to C code for embedded deployment, supporting multi-class or multi-output predictions with minimal tweaks for different use cases.

## Files
 - `converter.py` — main conversion script using m2cgen
 - `example_model.pkl` — sample trained model file (Sensor values trained)
 - `model.c/.h` — converted output file

## Features
 - Generates C header and source files from .pkl models
 - Supports multi-class (e.g., security actions like benign/throttle/isolate/lockdown) or multi-output (e.g., IoT controls like LED/buzzer)
 - Extracts and deduplicates helper functions
 - Integrates with constraints patch for ESP32 memory limits
 - Configurable input features, decision logic, and tags via Python variables
 - Beginner-friendly, just edit config.py for new models without code changes

## Configuration setting is available in config.py

## Usage
Ensure model.pkl exists, then run:
``` bash
python converter.py
```
- This generates model.h and model.c in the configured output path. Switch between multi-class and multi-output by changing "model_type" in config.py.

## An example model is provided provided for testing.