/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

// @lc code=end
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        int levelsize = 1;
        while(!q.empty())
        {
            vector<int> v;

            while(levelsize--)
            {
                TreeNode* tmp = q.front();
                v.push_back(tmp->val);
                q.pop(); 
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }

            levelsize = q.size();
            ret.push_back(v);
        }    

        return ret;
    }
};

//五刷：队列+levelsize，一层出完后队列内的节点数就是下一次循环的levelsize
//四刷：忘记删除节点了TAT
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
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

        return vv;
    }
};
//三刷：重新捋了一遍思路就顺了^_^
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root)
//     {
//         vector<vector<int>> vv;
//         queue<TreeNode*> q;
//         int levelsize = 0;

//         if(root)
//         {
//             q.push(root);
//             levelsize = 1;
//         }

//         while(!q.empty())
//         {
//             vector<int> v;
//             while(levelsize--)
//             {
//                 v.push_back(q.front()->val);
//                 if(q.front()->left)
//                 {
//                     q.push(q.front()->left);
//                 }
//                 if(q.front()->right)
//                 {
//                     q.push(q.front()->right);
//                 }

//                 q.pop();
//             }

//             vv.push_back(v);
//             levelsize = q.size();
//         }

//         return vv;
//     }
// };
//二刷：熟练度和审题还需提升
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root)
//     {
//         vector<vector<int>> vv;
//         queue<TreeNode*> q;
//         int levelsize = 0;
//         if(root)
//         {
//             q.push(root);
//             levelsize = 1;
//         }

//         while(!q.empty())
//         {
//             vector<int> v;

//             while(levelsize--)
//             {
//                 v.push_back(q.front()->val);

//                 if(q.front()->left)
//                 {
//                     q.push(q.front()->left);
//                 }
//                 if(q.front()->right)
//                 {
//                     q.push(q.front()->right);
//                 }
                
//                 q.pop();
//             }

//             levelsize = q.size();
//             vv.push_back(v);
//         }

//         return vv;
//     }
// };
//一刷：思路一是一层一层出队列，用while和levelsize记录和控制每一层的节点数，队列记录每一层的节点指针
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root)
//     {
//         vector<vector<int>> vv;
//         int levelsize = 0;
//         queue<TreeNode*> q;
//         if(root)
//         {
//             q.push(root);
//             levelsize = 1;
//         }

//         while(!q.empty())
//         {
//             vector<int> v;
//             while(levelsize--)
//             {
//                 v.push_back(q.front()->val);

//                 if(q.front()->left)
//                 {
//                     q.push(q.front()->left);
//                 }

//                 if(q.front()->right)
//                 {
//                     q.push(q.front()->right);
//                 }     

//                 q.pop();
//             }

//             levelsize = q.size();
//             vv.push_back(v);
//         }

//         return vv;
//     }
// };