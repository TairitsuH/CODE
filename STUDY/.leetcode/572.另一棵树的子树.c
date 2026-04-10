/*
 * @lc app=leetcode.cn id=572 lang=c
 *
 * [572] 另一棵树的子树
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
bool isSameTree(TNode* p, TNode* q)
{
    if(!p && !q)
    return true;

    if(!p || !q)
    return false;

    if(p->val != q->val)
    return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if(!root)
    return false;

    if(root->val == subRoot->val && isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
// @lc code=end

//一刷：递归的思路还是要加强TvT。本质上是遍历树，找出所有子树与subroot进行比较，最后只要有true表示找到了子树（因为返回是或关系
// typedef struct TreeNode TNode;
// bool isSameTree(TNode* root, TNode* subroot)
// {
//     if(!root && !subroot) return true;

//     if(!root || !subroot) return false;

//     if(root->val != subroot->val) return false;

//     return isSameTree(root->left, subroot->left) && isSameTree(root->right, subroot->right);
// }

// bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
// {
//     if(!root)
//     {
//         return false; 
//     }

//     if(root->val == subRoot->val && isSameTree(root, subRoot))
//     {
//         return true;
//     }

//     return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

// }
