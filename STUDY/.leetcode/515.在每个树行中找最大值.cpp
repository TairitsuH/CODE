/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root)
    {
        typedef TreeNode Node;
        if(!root) return {};    

        queue<Node*> q;
        vector<int> ret;
        q.push(root);

        while(!q.empty())
        {
            int tmp = INT_MIN;
            int flag = 1;
            int levelsize = q.size();

            for(int i=0; i<levelsize; ++i)
            {
                Node* node = q.front();
                q.pop();
                tmp = max(tmp, node->val); //记录当前层的最大值

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ret.push_back(tmp);
        }

        return ret;
    }
};
// @lc code=end

//一刷：队列宽搜，只关注当前层比关注下一层的分类讨论少