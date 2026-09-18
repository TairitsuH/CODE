/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* root)
    {
        if(!root) return "";

        string ret = to_string(root->val);
        if(root->left || root->right)
        {
            ret +='(';
            ret += tree2str(root->left);
            ret += ')';
        }

        if(root->right)
        {
            ret += '(';
            ret += tree2str(root->right);
            ret += ')';
        }

        return ret;
    }
};
// @lc code=end
//二刷：递归分类讨论，一种新的分类方式，更简洁
//一刷：递归分情况讨论，一定要画图+推演！
class Solution {
public:
    string tree2str(TreeNode* root)
    {
        if(root == nullptr) return "";

        string ret = to_string(root->val);
        
        if(!root->left && root->right) //左子树为空
        {
            ret += "()";
            ret += '(' + tree2str(root->right) + ')';
        }
        else if(root->left && !root->right) //右子树为空
        {
            ret += '(' + tree2str(root->left) + ')';
        }
        else if(!root->left && !root->right) //左右都为空
        {
            return ret;
        }
        else //都不为空
        {
            ret += '(' + tree2str(root->left) + ')';
            ret += '(' + tree2str(root->right) + ')';
        }

        return ret;
    }
};
