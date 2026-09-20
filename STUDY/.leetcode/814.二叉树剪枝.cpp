/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    void EraseNode(TreeNode*& root)
    {
        if(!root) return;

        EraseNode(root->left);
        EraseNode(root->right);

        if(root->val == 0 && !root->left && !root->right)
        {
            delete root; //如果节点是new出来的就需要delete，防止内存泄漏（可加可不加
            root = nullptr;
        }
    }

    TreeNode* pruneTree(TreeNode* root)
    {
        EraseNode(root);
        return root;
    }
};
// @lc code=end
//二刷：递归，不需要设置返回值了，因为已经从下至上删除节点可以直接获取信息，注意是传引用，因为会改变二叉树
//一刷：递归，从叶子到根逐个删除
class Solution {
public:
    bool EraseNode(TreeNode*& root)
    {
        if(!root) return true;

        bool l = EraseNode(root->left);
        bool r = EraseNode(root->right);
        cout << l << " " << r << endl;

        if(root->val == 0 && l && r)
        {
        cout << l << " " << r << "shanchu" << endl;

            root = nullptr;
            return true;
        }

        return false;
    }

    TreeNode* pruneTree(TreeNode* root)
    {
        EraseNode(root);
        return root;
    }
};
