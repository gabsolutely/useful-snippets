# DataGenerator
- A flexible Python script to generate synthetic training data for AI models, simulating various features (e.g., sensors or network metrics) with configurable thresholds and labels.

## Files
 - `CreateData.py` — main data generation script
 - `training_data.csv` — output CSV file (generated)

## Features
 - Creates labeled datasets for classification tasks (single or multi-label)
 - Includes anomaly detection (e.g., z-scores, predictions) for realism
 - Supports different domains: IoT sensors (temp/hum/light) or network security (RSSI/entropy)
 - Random but threshold-driven data for quick prototyping
 - Easily tweakable via config.py—no coding needed for basic changes

## Configuration setting is available in config.py

## Usage
Run to generate data:
```bash
python CreateData.py
```
- Edit config.py to change features (e.g., add/remove sensors), thresholds, or label rules for your specific model.

## Training data output is provided as an example.