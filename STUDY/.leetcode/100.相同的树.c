/*
 * @lc app=leetcode.cn id=100 lang=c
 *
 * [100] 相同的树
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q)
    return true;
    
    //p,q有一个不为空
    if(!p || !q)
    return false;

    if(p->val != q->val)
    return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
// @lc code=end

//一刷：到了二叉树难度果然有点大，不太适应递归的写法，希望后续可以熟能生巧