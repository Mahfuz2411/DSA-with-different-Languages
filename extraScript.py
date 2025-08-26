import os
import fnmatch
from urllib.parse import quote

IGNORE_PATTERNS = [".git", ".gitignore", ".vscode", "m_Assets", "*.exe", "*.class", "*.o", "extra.*", "extraScript.py"]
ROOT_DIR = "."
OUTPUT_FILE = "FOLDER_STRUCTURE.md"

GITHUB_BASE_URL = "https://github.com/Mahfuz2411/DSA-with-different-Languages/blob/main/"

FOLDER_ICON = "📁"
GENERIC_FILE_ICON = "📄"

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

def should_ignore(rel_path):
    for pattern in IGNORE_PATTERNS:
        if fnmatch.fnmatch(rel_path, pattern) or fnmatch.fnmatch(os.path.basename(rel_path), pattern):
            return True
    return False

def get_icon(path):
    if os.path.isdir(path):
        return FOLDER_ICON
    _, ext = os.path.splitext(path.lower())
    return EXT_ICONS.get(ext, GENERIC_FILE_ICON)

def generate_tree(path=".", prefix=""):
    try:
        entries = os.listdir(path)
    except PermissionError:
        # Skip directories that can't be accessed
        return

    entries = [e for e in entries if not should_ignore(os.path.join(path, e))]
    entries.sort(key=lambda x: (not os.path.isdir(os.path.join(path, x)), x.lower()))

    pointers = ['├── '] * (len(entries) - 1) + ['└── '] if entries else []

    for pointer, name in zip(pointers, entries):
        full_path = os.path.join(path, name)
        rel_path = os.path.relpath(full_path, ROOT_DIR).replace("\\", "/")
        icon = get_icon(full_path)

        if os.path.isdir(full_path):
            output_lines.append(f"{prefix}{pointer}{icon} {name} </br>")
            extension = '│   ' if pointer == '├── ' else '    '
            generate_tree(full_path, prefix + extension)
        else:
            encoded_path = quote(rel_path)
            github_url = GITHUB_BASE_URL + encoded_path
            # Markdown link: [icon name](url)
            output_lines.append(f'{prefix}{pointer}[{icon} {name}]({github_url}) </br>')

output_lines = []
output_lines.append("# 📁 Folder Structure\n\n")  # Header + blank line

generate_tree(ROOT_DIR)

output_lines.append("\n")  # Add an extra newline at end of file

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    f.writelines(output_lines)

print(f"✅ Folder structure with clickable file links written to: {OUTPUT_FILE}")
