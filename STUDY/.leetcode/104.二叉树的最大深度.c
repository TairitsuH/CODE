/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
int maxDepth(struct TreeNode* root)
{
    if(!root)
    return 0;

    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
// @lc code=end

//一刷：求树的深度，取左右子树的较大深度，加上自身层数后递归即可。