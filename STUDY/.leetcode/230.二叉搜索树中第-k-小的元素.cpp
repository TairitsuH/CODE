/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int count;
    int retnum;

    void kthdfs(TreeNode* root)
    {
        if(!root) return;

        if(root->left) kthdfs(root->left); 
        --count;
        if(count == 0)
        {
            retnum = root->val;
            return;
        }
        if(root->right) kthdfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        count = k;
        kthdfs(root);
        return retnum;
    }
};
// @lc code=end
//一刷：递归解决。二叉搜索树中序有序，设置全局变量count计数，retnum返回

