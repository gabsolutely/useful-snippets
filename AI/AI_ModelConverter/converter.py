import joblib
import m2cgen as m2c
import os
import re
import subprocess
from config import model_type, tags, features, output_path, patch_after_conversion

# path setup
ai_folder = os.path.dirname(__file__)
project_src = os.path.join(ai_folder, output_path)
os.makedirs(project_src, exist_ok=True)

model_path = os.path.join(ai_folder, "model.pkl")
if not os.path.exists(model_path):
    raise FileNotFoundError(f"{model_path} not found. Train the model first.")

clf = joblib.load(model_path)
print("[INFO] Loaded model.pkl")

# helper functions
def split_helpers_and_score(code: str):
    helper_pattern = (
        r"(void\s+add_vectors[\s\S]*?^\})"
        r"|(void\s+mul_vector_number[\s\S]*?^\})"
    )

    helpers = re.findall(helper_pattern, code, re.MULTILINE)
    helpers_code = "\n".join(h for tup in helpers for h in tup if h)

    code_no_helpers = re.sub(
        helper_pattern, "", code, flags=re.MULTILINE
    ).strip()

    return helpers_code, code_no_helpers

# generate C code
codes = [m2c.export_to_c(est, function_name=f"score_{tag}") for est, tag in zip(clf.estimators_, tags)]

# extract helpers and score functions
helpers_code, score_functions = [], []
for code in codes:
    h, s = split_helpers_and_score(code)
    helpers_code.append(h)
    score_functions.append(s)

# build decision logic as C code string
decision_logic = "double output[1];\nint result = 0;\n"
if model_type == "multi_class":
    for i, tag in enumerate(reversed(tags)):
        decision_logic += f"score_{tag}(input, output);\n"
        decision_logic += f"if (output[0] <= 0.5) {{ result = {len(tags) - 1 - i}; break; }}\n"
else:
    for i, tag in enumerate(tags):
        decision_logic += f"score_{tag}(input, output);\n"
        decision_logic += f"if (output[0] <= 0.5) result |= (1 << {i});\n"
decision_logic += "return result;"

# model.h content
header = f"""#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {{
#endif

{chr(10).join(f'void score_{tag}(double * input, double * output);' for tag in tags)}

int runAIModel({', '.join(f'float {feat}' for feat in features)});

#ifdef __cplusplus
}}
#endif
"""

# source code content
source = f"""
#include "model.h"

{chr(10).join(helpers_code)}

{chr(10).join(score_functions)}

int runAIModel({', '.join(f'float {feat}' for feat in features)}) {{
    double input[{len(features)}] = {{{', '.join(f'(double){feat}' for feat in features)}}};

    {decision_logic}
}}
"""

# safeguard checks
if re.search(r'\bvoid\s+score\s*\$', source):
    raise RuntimeError("UN-NAMESPACED score() STILL EXISTS")

# write
with open(os.path.join(project_src, "model.h"), "w") as f:
    f.write(header)

with open(os.path.join(project_src, "model.c"), "w") as f:
    f.write(source)

print(f"[OK] model.c / model.h generated in {project_src}")

# implement constraints patch
if patch_after_conversion:
    patch_script = os.path.join(ai_folder, "constraints_patch.py")
    model_c_path = os.path.join(project_src, "model.c")
    subprocess.run(["python", patch_script, model_c_path])