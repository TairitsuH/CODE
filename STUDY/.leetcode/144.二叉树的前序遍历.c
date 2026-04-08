/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int TreeSize(struct TreeNode* root)
{
    if(!root)
    return 0;

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PreOrder(struct TreeNode* root, int* a, int* pi)
{
    if(!root)
    return;

    a[(*pi)++] = root->val;
    PreOrder(root->left, a, pi);
    PreOrder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int)*(*returnSize));
    int i = 0;
    PreOrder(root, a, &i);
    return a;
}

// @lc code=end

//二刷：计算size->开辟空间->前序遍历并放入数组->返回数组（做的真不错，除了在前序遍历传参时下意识只传了一个<(＿　＿)>
//一刷：先遍历树得出节点大小size，再通过size开辟空间建立数组，最后再次遍历填数(前中后序指的是根的遍历位置)
// int TreeSize(struct TreeNode* root)
// {
//     return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
// }

// void PreOrder(struct TreeNode* root, int* a, int* pi)
// {
//     if(root == NULL)
//     return;
//     a[(*pi)++] = root->val;
//     PreOrder(root->left, a, pi);
//     PreOrder(root->right, a, pi);
// }

// int* preorderTraversal(struct TreeNode* root, int* returnSize)
// {
//     *returnSize = TreeSize(root);
//     int* a = (int*)malloc(sizeof(int)*(*returnSize));
//     int i = 0;
//     int* pi = &i;
//     PreOrder(root, a, pi);
//     return a;
// }