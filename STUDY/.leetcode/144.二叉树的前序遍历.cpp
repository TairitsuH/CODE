/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void PreOrder(vector<int>& v, TreeNode* root)
    {
        if(!root) return;

        v.push_back(root->val);
        PreOrder(v, root->left);
        PreOrder(v, root->right);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v;
        PreOrder(v, root);
        return v;
    }
};
// @lc code=end
//二刷：递归。发现好像不用设置返回值（￣︶￣）↗　
//递归遍历二叉树：前序为根->左->右
class Solution {
public:
    TreeNode* Fore(vector<int>& v, TreeNode* root)
    {
        if(root == nullptr) return root;

        v.push_back(root->val);
        Fore(v, root->left);
        Fore(v, root->right);

        return root;
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        Fore(ret, root);
        return ret;    
    }
};
