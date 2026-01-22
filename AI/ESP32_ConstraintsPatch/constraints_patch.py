import re
import os
import sys
from config import array_pattern, global_prefix

def apply_constraints_patch(c_file_path):
    # check if file exists
    if not os.path.exists(c_file_path):
        print(f"[ERROR] {c_file_path} not found")
        return

    with open(c_file_path, "r") as f:
        code = f.read()

    matches = re.findall(array_pattern, code)

    # no matches
    if not matches:
        print("[INFO] No stack arrays found")
        print("[DEBUG] Pattern:", array_pattern)
        print("[DEBUG] First 500 chars of code:", repr(code[:500]))
        return

    print(f"[INFO] Found {len(matches)} local arrays: {matches}")

    code = re.sub(array_pattern, "", code)

    # deduplicate and prepare globals
    seen = set()
    globals_code = f"{global_prefix}\n"
    for name, size in matches:
        if name in seen:
            continue
        seen.add(name)
        globals_code += f"static double {name}[{size}];\n"
    globals_code += "\n"

    # insert globals at the top after includes
    lines = code.splitlines()
    insert_idx = 0
    for i, line in enumerate(lines):
        if not line.startswith("#include"):
            insert_idx = i
            break

    # insert
    lines.insert(insert_idx, globals_code)
    code = "\n".join(lines)

    with open(c_file_path, "w") as f:
        f.write(code)

    print(f"[SUCCESS] {len(seen)} unique stack arrays moved to globals")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python constraints_patch.py path/to/model.c")
        sys.exit(1)
    apply_constraints_patch(sys.argv[1])