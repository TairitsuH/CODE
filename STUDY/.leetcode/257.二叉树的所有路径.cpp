/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> ret;
    void dfs(TreeNode* root, string next)
    {
        if(!root) return;
        if(!root->left && !root->right) 
        {
            next += to_string(root->val);
            ret.emplace_back(next);
            return;
        }

        next += to_string(root->val) + "->";
        if(root->left) dfs(root->left, next);
        if(root->right) dfs(root->right, next);

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        dfs(root, "");
        return ret;
    }
};
// @lc code=end

//一刷：递归实现，注意字符串的拼接和恢复现场，字符串作为参数比全局变量更合适

