/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TNode;
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(!root)
    return NULL;

    TNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
// @lc code=end

//一刷；凡是遇到有返回值的递归函数务必要为每个子问题都设置返回值！

