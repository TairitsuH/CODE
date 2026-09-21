/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int next)
    {
        int newnext = next * 10 + root->val;

        if(!root->left && !root->right) return newnext;

        int ret = 0;
        if(root->left) ret += dfs(root->left, newnext); //检查非空指针
        if(root->right) ret += dfs(root->right, newnext);

        return ret;
    }

    int sumNumbers(TreeNode* root)
    {
        return dfs(root, 0);
    }
};
// @lc code=end
//二刷：递归实现，向上返回叶子节点的结果之和，向下传递逐层祖先拼接的数，注意空指针的解引用问题
//一刷：递归实现，注意函数参数/返回值/递归出口的设计都不同！分析好每个节点的任务
class Solution {
public:
    int BranchNum(TreeNode* root, int levelnum)
    {
        int dfs = levelnum * 10 + root->val;

        if(!root->left && !root->right) return dfs;

        int ret = 0;
        if(root->left) ret += BranchNum(root->left, dfs);
        if(root->right) ret += BranchNum(root->right, dfs);

        return ret;
    }

    int sumNumbers(TreeNode* root)
    {
        return BranchNum(root, 0);
    }
};