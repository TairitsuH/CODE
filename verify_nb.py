import json

with open(r"d:\University\机器学习实验-练习.ipynb", "r", encoding="utf-8") as f:
    nb = json.load(f)

for cell in nb["cells"]:
    if cell.get("id") == "77791eae-950a-4c48-910d-fcd73598923f":
        src = "".join(cell["source"])
        checks = ["练习1", "练习2", "练习3", "练习4", "练习5", "最终课堂总结",
                  "corr_matrix", "pca13", "pca3d", "KNeighborsClassifier",
                  "train_test_split", "accuracy_score", "boxplot",
                  "cumsum", "Axes3D"]
        all_ok = True
        for c in checks:
            ok = c in src
            if not ok:
                all_ok = False
            print(f"  {c}: {'OK' if ok else 'MISSING!'}")
        print(f"Length: {len(src)} chars")
        print(f"All checks passed: {all_ok}")
        break
