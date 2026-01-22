import pandas as pd
import random
from config import max_samples, output_file, features, thresholds, label_logic

rows = []

for _ in range(max_samples):
    row = []
    for feat in features[:-1]:  # all but label
        # generate feature value based on some logic
        row.append(random.uniform(0, 100))  # default range 0-100

    # label generation logic
    if label_logic == "threshold_based":
        # example: binary label based on threshold of first feature
        label = 1 if row[0] > thresholds.get("feature1_threshold", 50) else 0
    elif label_logic == "multi_label":
        label = [1 if random.random() > 0.5 else 0 for _ in range(len(features) - len(features[:-1]))]  # Placeholder
    else:
        label = 0  # default

    row.append(label)
    rows.append(row)

# save to CSV
df = pd.DataFrame(rows, columns=features)
df.to_csv(output_file, index=False)
print(f"[OK] {output_file} generated")