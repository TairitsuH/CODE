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
// @lc code=end
//一刷：递归实现，注意函数参数/返回值/递归出口的设计都不同！分析好每个节点的任务

