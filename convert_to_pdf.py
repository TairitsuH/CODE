"""
Convert notebook to PDF: HTML via nbconvert, then to PDF via Edge headless.
No execution needed - the code itself is what matters for the assignment.
"""
import subprocess
import sys
import os

NOTEBOOK_PATH = r"d:\University\机器学习实验-练习.ipynb"
OUTPUT_DIR = r"d:\University"
HTML_PATH = os.path.join(OUTPUT_DIR, "机器学习实验-练习.html")
PDF_PATH = os.path.join(OUTPUT_DIR, "机器学习实验-练习.pdf")

# --- Step 1: Convert notebook to HTML (no execute, show source) ---
print("Step 1: Converting notebook to HTML...")
cmd1 = [
    sys.executable, "-m", "jupyter", "nbconvert",
    "--to", "html",
    "--no-input",  # This hides input... actually we WANT to show input
    "--output-dir", OUTPUT_DIR,
    "--output", "机器学习实验-练习.html",
    NOTEBOOK_PATH
]
# Remove --no-input, we want to show the code
cmd1 = [
    sys.executable, "-m", "jupyter", "nbconvert",
    "--to", "html",
    "--output-dir", OUTPUT_DIR,
    "--output", "机器学习实验-练习.html",
    NOTEBOOK_PATH
]

print("Running:", " ".join(cmd1))
result1 = subprocess.run(cmd1, capture_output=True, text=True, timeout=120, cwd=OUTPUT_DIR)
print("STDOUT:", result1.stdout.strip() if result1.stdout else "")
if result1.stderr:
    lines = result1.stderr.strip().split("\n")
    # Show last 3 lines
    for l in lines[-3:]:
        print("STDERR:", l)
print(f"Exit code: {result1.returncode}")

if not os.path.exists(HTML_PATH):
    print(f"ERROR: HTML not created at {HTML_PATH}")
    sys.exit(1)

html_size = os.path.getsize(HTML_PATH)
print(f"HTML created: {HTML_PATH} ({html_size} bytes)")

# --- Step 2: HTML to PDF via Edge ---
print("\nStep 2: Converting HTML to PDF via Edge...")
msedge = r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe"

# Use file:/// URL format for Edge
html_url = f"file:///{HTML_PATH.replace(chr(92), '/')}"

cmd2 = [
    msedge,
    "--headless",
    "--disable-gpu",
    f"--print-to-pdf={PDF_PATH}",
    "--no-pdf-header-footer",
    html_url
]

print("Running Edge...")
result2 = subprocess.run(cmd2, capture_output=True, text=True, timeout=120)
print(f"Edge exit code: {result2.returncode}")
if result2.stderr:
    print("Edge STDERR:", result2.stderr[:200])

if os.path.exists(PDF_PATH):
    pdf_size = os.path.getsize(PDF_PATH)
    print(f"\nSUCCESS! PDF created: {PDF_PATH} ({pdf_size} bytes)")
else:
    print(f"\nERROR: PDF not created at {PDF_PATH}")
    sys.exit(1)
