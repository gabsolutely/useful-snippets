# Configuration for ModelTrainer
# Edit these to train your model

model_type = "single_output"  # "single_output" or "multi_output", etc.
features = ["feature1", "feature2", "feature3"]  # List of input features
target = "label"  # String for single, list for multi
test_size = 0.2  # Fraction for testing
random_state = 42  # For reproducibility
n_estimators = 120  # Number of trees
max_depth = 8  # Max tree depth