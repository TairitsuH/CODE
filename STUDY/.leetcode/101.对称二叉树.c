/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q)
    return true;

    if(!p || !q)
    return false;

    if(p->val != q->val)
    return false;

    return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root)
{
    return _isSymmetric(root->left, root->right);
}

// @lc code=end

//一刷：由于root的左右子树是要分开比较的，所以需要再写一个函数单独处理左右子树

