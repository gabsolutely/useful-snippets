# Configuration for ConstraintsPatch
# Edit these to match your array patterns

array_pattern = r"double\s+(var\d+)\s*\$(\d+)\$\s*;"  # Regex for local double arrays (adjusted for indentation)
global_prefix = "// ESP32 stack fix (deduplicated)"  # Comment prefix for globals