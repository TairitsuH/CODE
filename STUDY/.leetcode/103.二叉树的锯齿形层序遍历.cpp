/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        typedef TreeNode Node;

        if(!root) return {};

        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ret;
        int flag = 1;

        while(!q.empty())
        {
            int levelsize = q.size();
            vector<int> tmp;

            for(int i=0; i<levelsize; ++i)
            {
                Node* head = q.front();
                tmp.push_back(head->val);
                q.pop();

                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
            }

            if(flag == -1) reverse(tmp.begin(), tmp.end());
            flag *= -1;
            ret.push_back(tmp);
        }

        return ret;
    }
};
// @lc code=end

//一刷：队列宽搜，如果为偶数层则逆序tmp数组

