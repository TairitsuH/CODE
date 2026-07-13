import json

TEMP_PATH = r"c:\Users\mh_sk\AppData\Local\Temp\MicrosoftEdgeDownloads\5b9c3b82-41dc-4bfe-9d6b-727e540a9f85\机器学习实验-练习.ipynb"

with open(TEMP_PATH, "r", encoding="utf-8") as f:
    nb = json.load(f)

for cell in nb["cells"]:
    if cell.get("id") == "77791eae-950a-4c48-910d-fcd73598923f":
        src = "".join(cell["source"])

        # Find the transition from end of ex2 comment to start of ex3 header
        # Show content between "热图" and "# 练习3"
        for kw_before, kw_after in [("热图。", "# ============================================================\n# 练习3"),
                                     ("折线图。", "# ============================================================\n# 练习4"),
                                     ("分组画图。", "# ============================================================\n# 练习5"),
                                     ("计算准确率。", "# ============================================================\n# 最终课堂总结")]:
            idx1 = src.find(kw_before)
            idx2 = src.find(kw_after, idx1)
            if idx1 >= 0 and idx2 >= 0:
                print(f"=== Between '{kw_before}' and '{kw_after[:40]}' ===")
                print(repr(src[idx1:idx2 + len(kw_after)]))
                print()
        break
