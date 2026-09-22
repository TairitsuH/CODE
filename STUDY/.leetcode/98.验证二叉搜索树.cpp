/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long long cmp = LONG_MIN;
    
    bool dfs(TreeNode* root)
    {
        if(!root) return true;

        int retl = dfs(root->left);
        if(retl == 0) return false; //剪枝

        if(root->val <= cmp) return false; //剪枝
        cmp = root->val;

        int retr = dfs(root->right);

        return retr;
    }

    bool isValidBST(TreeNode* root)
    {
        return dfs(root);
    }
};
// @lc code=end
//一刷：递归，借助二叉搜索树中序遍历有序的特点设置全局变量+剪枝优化
class Solution {
public:
    long long comp = LONG_MIN;

    bool isValidBST(TreeNode* root)
    {
        if(!root) return true;

        int retleft = isValidBST(root->left);
        if(retleft == 0) return false; //剪枝

        int retcur = 1;
        if(comp >= root->val) return false; //剪枝
        else comp = root->val;
        
        int retright = isValidBST(root->right);

        return retleft && retcur && retright;
    }
};
//二刷：注意比较逻辑和节点的空/非空
