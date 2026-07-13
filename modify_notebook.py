"""
Rewrite the Wine exercise cell by constructing it line-by-line from the original.
This avoids fragile string markers.
"""
import json

TEMP_PATH = r"c:\Users\mh_sk\AppData\Local\Temp\MicrosoftEdgeDownloads\5b9c3b82-41dc-4bfe-9d6b-727e540a9f85\机器学习实验-练习.ipynb"
OUT_PATH = r"d:\University\机器学习实验-练习.ipynb"

with open(TEMP_PATH, "r", encoding="utf-8") as f:
    nb = json.load(f)

for i, cell in enumerate(nb["cells"]):
    if cell.get("id") == "77791eae-950a-4c48-910d-fcd73598923f":
        target_cell = cell
        break
else:
    print("ERROR: Cell not found!")
    exit(1)

src = "".join(target_cell["source"])
lines = src.split("\n")

# Find the line numbers where each exercise section begins
section_starts = {}
for linenum, line in enumerate(lines):
    s = line.strip()
    if s.startswith("# 练习1") and ": " not in s:
        section_starts["ex1"] = linenum
    elif s.startswith("# 练习2") and ": " not in s:
        section_starts["ex2"] = linenum
    elif s.startswith("# 练习3") and ": " not in s:
        section_starts["ex3"] = linenum
    elif s.startswith("# 练习4") and ": " not in s:
        section_starts["ex4"] = linenum
    elif s.startswith("# 练习5") and ": " not in s:
        section_starts["ex5"] = linenum
    elif s.startswith("# 最终课堂总结"):
        section_starts["final"] = linenum

print(f"Found sections: {section_starts}")

# Each exercise section includes:
# - Header (# 练习N：...)
# - Comment block (# 目标：..., # 本题主要练习：...)
# - Empty lines
# We want to insert code AFTER the comment block, BEFORE the next section

# Exercise 2 code
ex2_code = '''# 计算所有特征之间的相关系数矩阵
feature_cols = wine.feature_names
corr_matrix = df[feature_cols].corr()

# 找出与 alcohol 相关性最高的三个变量（排除 alcohol 自身）
alcohol_corr = corr_matrix["alcohol"].drop("alcohol").sort_values(ascending=False)

print("\\n练习2：与 alcohol 相关性分析")
print("\\n与 alcohol 正相关最高的三个变量：")
display(alcohol_corr.head(3))

print("\\n与 alcohol 相关性最低的三个变量：")
display(alcohol_corr.tail(3))

# 绘制相关性热图
plt.figure(figsize=(10, 8))
sns.heatmap(
    corr_matrix,
    annot=True,
    cmap="coolwarm",
    center=0,
    fmt=".2f",
    linewidths=0.5
)
plt.title("葡萄酒化学特征相关性热图")
plt.tight_layout()
plt.show()

print("\\n练习2参考结论：")
print("高相关性意味着两个变量之间存在较强的线性关系，一个变量的变化往往伴随着另一个变量的变化。")
print("如果两个变量高度相关，可能存在信息冗余，不一定都需要保留。")
print("可以通过PCA降维来消除这种冗余。")'''

ex3_code = '''# 对13个特征进行标准化
X = df[feature_cols]
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 使用 PCA 提取全部13个主成分
pca13 = PCA(n_components=13)
X_pca13 = pca13.fit_transform(X_scaled)

# 每个主成分的解释方差比例
ratio = pca13.explained_variance_ratio_

# np.cumsum() 用于计算累计和
cum_ratio = np.cumsum(ratio)

# 将结果整理成 DataFrame
pca13_result = pd.DataFrame({
    "主成分": [f"PC{i+1}" for i in range(13)],
    "解释方差比例": ratio,
    "累计解释方差比例": cum_ratio
})

print("\\n练习3：PCA主成分数量分析")
display(pca13_result)

# 绘制累计解释方差曲线
plt.figure(figsize=(8, 5))
plt.plot(range(1, 14), cum_ratio, marker="o", linewidth=2)
plt.axhline(y=0.9, linestyle="--", color="red", label="90% 信息阈值")
plt.xticks(range(1, 14))
plt.title("PCA累计解释方差曲线")
plt.xlabel("主成分数量")
plt.ylabel("累计解释方差比例")
plt.legend()
plt.grid(True)
plt.show()

# 计算保留90%以上信息需要多少个主成分
n90 = np.argmax(cum_ratio >= 0.9) + 1
print(f"保留90%以上信息需要 {n90} 个主成分。")

print("\\n练习3参考结论：")
print(f"前 {n90} 个主成分即可保留原始数据90%以上的信息，这说明原始13个特征之间存在较强的相关性。")
print("可以用少量主成分代替原始特征进行分析和建模。")'''

ex4_code = '''# 使用 PCA 提取前三个主成分
pca3d = PCA(n_components=3)
X_pca3d = pca3d.fit_transform(X_scaled)

# 构造包含 PC1、PC2、PC3 的数据表
df_pca3d = pd.DataFrame(X_pca3d, columns=["PC1", "PC2", "PC3"])
df_pca3d["target"] = df["target"]
df_pca3d["target_name"] = df["target_name"]

print("\\n练习4：三维PCA数据")
display(df_pca3d.head())

print("\\n三个主成分的解释方差比例：")
for i, r in enumerate(pca3d.explained_variance_ratio_):
    print(f"  PC{i+1}: {r*100:.2f}%")
print(f"  累计: {pca3d.explained_variance_ratio_.sum()*100:.2f}%")

# 绘制三维散点图
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection="3d")

for i, name in enumerate(wine.target_names):
    temp = df_pca3d[df_pca3d["target"] == i]
    ax.scatter(temp["PC1"], temp["PC2"], temp["PC3"], label=name, s=50, alpha=0.8)

ax.set_title("葡萄酒数据集 PCA 三维投影")
ax.set_xlabel(f"PC1 ({pca3d.explained_variance_ratio_[0]*100:.1f}%)")
ax.set_ylabel(f"PC2 ({pca3d.explained_variance_ratio_[1]*100:.1f}%)")
ax.set_zlabel(f"PC3 ({pca3d.explained_variance_ratio_[2]*100:.1f}%)")
ax.legend()
plt.show()

print("\\n练习4参考结论：")
print("三维图相比二维图可以展示更多信息（三个主成分累计解释方差更高），能更全面地观察类别之间的空间分布关系。")'''

ex5_code = '''# 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(
    X_scaled, df["target"],
    test_size=0.3, random_state=42, stratify=df["target"]
)

print("\\n练习5：KNN分类模型")
print(f"训练集大小: {X_train.shape[0]} 样本")
print(f"测试集大小: {X_test.shape[0]} 样本")

# 尝试不同的 k 值
k_values = [3, 5, 7]
knn_results = []

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)
    y_pred = knn.predict(X_test)
    acc = accuracy_score(y_test, y_pred)
    knn_results.append({"k值": k, "测试集准确率": acc})
    print(f"k={k}, 测试集准确率: {acc:.4f}")

knn_df = pd.DataFrame(knn_results)
print("\\n不同k值下的KNN分类结果：")
display(knn_df)

# 绘制比较图
plt.figure(figsize=(7, 4))
sns.barplot(data=knn_df, x="k值", y="测试集准确率")
plt.title("不同k值下KNN分类准确率比较")
plt.xlabel("k值（邻居数量）")
plt.ylabel("测试集准确率")
plt.ylim(0, 1.05)
plt.show()

# 找出最佳k值
best_idx = knn_df["测试集准确率"].idxmax()
best_k = knn_df.loc[best_idx, "k值"]
best_acc = knn_df.loc[best_idx, "测试集准确率"]
print(f"\\n最佳 k 值: {best_k}，对应准确率: {best_acc:.4f}")

print("\\n练习5参考结论：")
print("k值太小（如k=1）模型容易受噪声影响，可能过拟合；")
print("k值太大（如k=7）决策边界过于平滑，可能欠拟合；")
print("适中的k值（如k=3或5）通常在偏差和方差之间取得较好平衡。")'''

final_code = '''print("\\n" + "=" * 60)
print("葡萄酒数据集综合实验总结")
print("=" * 60)
print()
print("1. 数据探索分析：")
print("   - 不同类别葡萄酒在化学特征上存在明显差异")
print("   - color_intensity 和 proline 是区分能力较强的变量")
print()
print("2. 特征相关性分析：")
print("   - 部分化学特征之间存在较高相关性，存在信息冗余")
print()
print("3. PCA 降维：")
print(f"   - 前{n90}个主成分即可解释90%以上原始数据信息")
print()
print("4. 三维可视化：")
print("   - 三维图可以展示更多数据结构")
print("   - 不同类别在 PCA 空间中分离明显")
print()
print("5. KNN 分类：")
print(f"   - 最佳 k 值为 {best_k}，准确率为 {best_acc:.4f}")
print("   - k 值的选择需要在过拟合与欠拟合之间权衡")
print()
print("6. 核心收获：")
print("   - 数据标准化对基于距离的算法至关重要")
print("   - PCA 是有效的降维工具，可用于可视化和去冗余")
print("   - KNN 简单直观，但需要合适的 k 值选择")'''

# Build new content by assembling sections
# Parts:
# [0 to ex2_start]: header + exercise 1 code
# [ex2_start to ex3_start]: exercise 2 header comments
# [ex3_start to ex4_start]: exercise 3 header comments
# [ex4_start to ex5_start]: exercise 4 header comments
# [ex5_start to final_start]: exercise 5 header comments
# [final_start to end]: final section

# For each exercise, we keep the header comments and add our code after them,
# then the next section header.

# Find the END of the comment block for each exercise section
# This is the last line before empty lines that precede the next section
def find_comment_end(lines, section_start, next_section_start):
    """Find the last line of the comment block for a section."""
    # Walk backwards from next_section_start to find the last non-empty line
    end = next_section_start - 1
    while end > section_start and lines[end].strip() == "":
        end -= 1
    return end

# Build the new source
new_lines = []

# Part 1: Everything before exercise 2
new_lines.extend(lines[:section_starts["ex2"]])

# Part 2: Exercise 2 header + code
ex2_end = find_comment_end(lines, section_starts["ex2"], section_starts["ex3"])
new_lines.extend(lines[section_starts["ex2"]:ex2_end + 1])
new_lines.append("")
new_lines.extend(ex2_code.split("\n"))
new_lines.append("")
new_lines.append("")

# Part 3: Exercise 3 header + code
ex3_end = find_comment_end(lines, section_starts["ex3"], section_starts["ex4"])
new_lines.extend(lines[section_starts["ex3"]:ex3_end + 1])
new_lines.append("")
new_lines.extend(ex3_code.split("\n"))
new_lines.append("")
new_lines.append("")

# Part 4: Exercise 4 header + code
ex4_end = find_comment_end(lines, section_starts["ex4"], section_starts["ex5"])
new_lines.extend(lines[section_starts["ex4"]:ex4_end + 1])
new_lines.append("")
new_lines.extend(ex4_code.split("\n"))
new_lines.append("")
new_lines.append("")

# Part 5: Exercise 5 header + code
ex5_end = find_comment_end(lines, section_starts["ex5"], section_starts["final"])
new_lines.extend(lines[section_starts["ex5"]:ex5_end + 1])
new_lines.append("")
new_lines.extend(ex5_code.split("\n"))
new_lines.append("")
new_lines.append("")

# Part 6: Final section
new_lines.extend(lines[section_starts["final"]:section_starts["final"] + 1])  # header
new_lines.append("")
new_lines.extend(final_code.split("\n"))

# Join back
new_source = "\n".join(new_lines)
target_cell["source"] = [new_source]

with open(OUT_PATH, "w", encoding="utf-8") as f:
    json.dump(nb, f, ensure_ascii=False, indent=1)

print("Notebook successfully modified!")
print(f"Output: {OUT_PATH}")
print(f"New source length: {len(new_source)} chars")
print(f"Exercises: ex1=✓, ex2=✓, ex3=✓, ex4=✓, ex5=✓, final=✓")
