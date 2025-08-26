import os
import fnmatch
from urllib.parse import quote

# === CONFIGURATION ===
IGNORE_PATTERNS = [".git", ".gitignore", ".vscode", "m_Assets", "*.exe", "*.class", "*.o", "extra.*", "extraScript.py"]
ROOT_DIR = "."  # Project root
OUTPUT_FILE = "FOLDER_STRUCTURE.md"

# GitHub repo root URL
GITHUB_BASE_URL = "https://github.com/Mahfuz2411/DSA-with-different-Languages/blob/main/"

FOLDER_ICON = "📁"
GENERIC_FILE_ICON = "📄"

# === EXTENSION-BASED ICONS ===
EXT_ICONS = {
    ".py": "🐍",
    ".c": "🧩",
    ".cpp": "🧩",
    ".cc": "🧩",
    ".java": "☕",
    ".js": "🌐",
    ".ts": "🌐",
    ".cs": "💻",
    ".dart": "💻",
}

# === IGNORE FILTER ===
def should_ignore(rel_path):
    for pattern in IGNORE_PATTERNS:
        if fnmatch.fnmatch(rel_path, pattern) or fnmatch.fnmatch(os.path.basename(rel_path), pattern):
            return True
    return False

# === ICON SELECTOR ===
def get_icon(path):
    if os.path.isdir(path):
        return FOLDER_ICON
    _, ext = os.path.splitext(path.lower())
    return EXT_ICONS.get(ext, GENERIC_FILE_ICON)

# === TREE GENERATOR ===
def generate_tree(path=".", prefix=""):
    entries = os.listdir(path)
    entries = [e for e in entries if not should_ignore(os.path.join(path, e))]
    entries.sort(key=lambda x: (not os.path.isdir(os.path.join(path, x)), x.lower()))

    pointers = ['├── '] * (len(entries) - 1) + ['└── ']
    for pointer, name in zip(pointers, entries):
        full_path = os.path.join(path, name)
        rel_path = os.path.relpath(full_path, ROOT_DIR).replace("\\", "/")  # GitHub uses forward slashes
        icon = get_icon(full_path)

        if os.path.isdir(full_path):
            output_lines.append(f"{prefix}{pointer}{icon} {name}")
            extension = '│   ' if pointer == '├── ' else '    '
            generate_tree(full_path, prefix + extension)
        else:
            encoded_path = quote(rel_path)
            github_url = GITHUB_BASE_URL + encoded_path
            output_lines.append(f'{prefix}{pointer}[{icon} {name}]("{github_url}")')

# === MAIN EXECUTION ===
output_lines = []
output_lines.append("# 📁 Folder Structure\n")
output_lines.append("```")

generate_tree(ROOT_DIR)

output_lines.append("```")

# === WRITE TO FILE ===
with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    f.write("\n".join(output_lines))

print(f"✅ Folder structure with clickable file links written to: {OUTPUT_FILE}")
