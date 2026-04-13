/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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
int TreeHeight(TNode* root)
{
    if(!root) return 0;

    int ret1 = TreeHeight(root->left);
    int ret2 = TreeHeight(root->right);
    return ret1 < ret2 ? ret2 + 1 : ret1 + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if(!root) return true;

    int h1 = TreeHeight(root->left);
    int h2 = TreeHeight(root->right);
    if(abs(h1 - h2) > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}
// @lc code=end
//二刷：很不错了，游刃有余。
//一刷：大体思路是对的，不过卡在了符合条件时不用返回true要继续递归TvT
// 来自评论区大佬指点：附上一个我觉得很啰嗦的解法...但是我觉得树的递归大部分都可以这么套路的解决，相当于一个解题模版（初学数据结构的菜鸡
// 模版一共三步，就是递归的三部曲：
// 找终止条件：什么时候递归到头了？此题自然是root为空的时候，空树当然是平衡的。
// 思考返回值，每一级递归应该向上返回什么信息？参考我代码中的注释。
// 单步操作应该怎么写？因为递归就是大量的调用自身的重复操作，因此从宏观上考虑，只用想想单步怎么写就行了，左树和右树应该看成一个整体，即此时树一共三个节点：root，root.left，root.right。
// typedef struct TreeNode TNode;
// int TreeHeight(TNode* root)
// {
//     if(!root)
//     return 0;

//     int ret1 = TreeHeight(root->left);
//     int ret2 = TreeHeight(root->right);
//     return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
// }


// bool isBalanced(struct TreeNode* root)
// {
//     if(!root)
//     return true;

//     int h1 = TreeHeight(root->left);
//     int h2 = TreeHeight(root->right);
//     if(abs(h1 - h2) > 1)
//     {
//         return false;
//     }

//     return isBalanced(root->left) && isBalanced(root->right);
// }