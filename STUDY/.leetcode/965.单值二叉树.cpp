/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool isSameVal(int val, TreeNode* root)
    {
        if(!root) return true;

        bool ret1 = isSameVal(val, root->left);
        bool ret2 = isSameVal(val, root->right);

        return ret1 && ret2 && val == root->val;
    }


    bool isUnivalTree(TreeNode* root)
    {
        if(!root) return true;

        return isSameVal(root->val, root);
    }
};
// @lc code=end
//一刷：递归，当一个函数无法满足需求的时候，大胆另设函数。考虑到给定函数无法和val对比，因此另加了一个传入val的函数
