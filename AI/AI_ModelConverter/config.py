# Configuration for AIModelConverter
# Edit these to match your model and use case

model_type = "multi_class"  # "multi_class" for single action, "multi_output" for multiple binary outputs
tags = ["class1", "class2", "class3", "class4"]  # Replace with your class names, e.g., temp, hum, etc.
features = ["feature1", "feature2", "feature3", "feature4"]  # Replace with your input feature names
output_path = ""  # Path to save generated C files
patch_after_conversion = False  # Set to False if not using ESP32, uses constraints patch