# ModelTrainer
- A versatile Python script to train and save machine learning models using scikit-learn, with support for single or multi-output classification on custom data.

## Files
 - `TrainModel.py` — training script
 - `training_data.csv` — input data file
 - `model.pkl` — output trained model

## Features
 - Uses RandomForest for robust classification
 - Handles single-target or multi-target labels
 - Splits data for training/testing with accuracy reporting
 - Saves model as .pkl for conversion to C
 - Configurable hyperparameters via Python variables
 - Accessible for all skill levels: defaults work out-of-the-box, advanced users can tweak

## Configuration setting is available in config.py

## Usage
After generating data, run:
```bash
python train.py
```
- Adjust config.py for model complexity, target columns, or to switch between single/multi-output modes.

## Training data is provided as an example/demo.