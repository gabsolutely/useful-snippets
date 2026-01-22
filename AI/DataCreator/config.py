# Configuration for DataGenerator
# Edit these to generate data for your use case

max_samples = 2000  # Number of data points
output_file = "training_data.csv"  # Output file name
features = ["feature1", "feature2", "feature3", "label"]  # List of features, last is label
thresholds = {"feature1_threshold": 50}  # Dict of thresholds for label logic
label_logic = "threshold_based"  # "threshold_based", "multi_label", or custom
# NOTE* Customize value ranges in CreateData.py for each feature