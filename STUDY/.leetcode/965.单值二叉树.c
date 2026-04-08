/*
 * @lc app=leetcode.cn id=965 lang=c
 *
 * [965] 单值二叉树
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
bool isUnivalTree(struct TreeNode* root)
{
    if(!root)
    return true;

    if(root->left && root->left->val != root->val)
    return false;

    if(root->right && root->right->val != root->val)
    return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);

}

// @lc code=end

//二刷：问了DS，瞬间清晰了很多：遇到false的情况就可以终止这一节点的递归了，但遇到true还需要继续递归查看是否还有false的情况，不能返回true，否则会漏解。
//根据这个思路设计函数就非常清晰了ψ(｀∇´)ψ
//一刷：法1：不用遍历，直接返回bool值
// bool isUnivalTree(struct TreeNode* root)
// {
//     if(root == NULL)
//     return true;

//     //左子树存在且不等
//     if(root->left && root->left->val != root->val)
//     return false;

//     //右子树存在且不等
//     if(root->right && root->right->val != root->val)
//     return false;

//     return isUnivalTree(root->left) && isUnivalTree(root->right);
// }
// // 法2：新建一个子函数，传入固定值比较
// bool _isUnivalTree(struct TreeNode* root, int val)
// {
//     if(root == NULL) return true;

//     if(root->left && root->left->val != val)
//     return false;

//     if(root->right && root->right->val != val)
//     return false;

//     return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
// }

// bool isUnivalTree(struct TreeNode* root)
// {
//     return _isUnivalTree(root, root->val);
// }
