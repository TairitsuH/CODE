/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode* root)
    {
        if(root->val == 1) return true;
        if(root->val == 0) return false;

        if(root->val == 2)
        {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } 
        else
        {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};
// @lc code=end
//一刷：递归解决
