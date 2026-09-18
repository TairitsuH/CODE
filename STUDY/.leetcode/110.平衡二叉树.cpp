/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int TreeHeight(TreeNode* root)
    {
        if(!root) return 0;

        int hl = TreeHeight(root->left);
        int hr = TreeHeight(root->right);

        return max(hl, hr) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if(!root) return true;
        
        int hl = TreeHeight(root->left);
        int hr = TreeHeight(root->right);

        if(abs(hl - hr) <= 1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }

        else return false;
    }
};
// @lc code=end
//一刷：二叉树递归，竟然自己写出来了，虽然中间很多曲折的过程。重点在于第一遍自己写的时候不要害怕复杂度过高，要敢于下手，后期再慢慢优化

