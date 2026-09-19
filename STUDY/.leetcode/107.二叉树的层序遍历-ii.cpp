/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        int levelsize = 0;
        if(root)
        {
            q.push(root);
            levelsize = 1;
        }

        while(!q.empty())
        {
            vector<int> v;
            while(levelsize--)
            {
                v.push_back(q.front()->val);

                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }

                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }

                q.pop();
            }

            vv.push_back(v);
            levelsize = q.size();
        }

        reverse(vv.begin(), vv.end());
        return vv;  
    }
};
// @lc code=end
//一刷：在lc102的基础上逆置数组即可

