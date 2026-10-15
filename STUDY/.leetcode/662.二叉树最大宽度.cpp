/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root)
    {
        typedef TreeNode Node;
        vector<pair<Node*, unsigned int>> q;
        q.push_back({root, 0});
        unsigned int maxwid = 1;

        while(q.size())
        {
            maxwid = max(q.back().second - q.front().second + 1, maxwid);

            vector<pair<Node*, unsigned int>> v;
            for(int i=0; i<q.size(); ++i)
            {
                Node* tmp = q[i].first;
                unsigned int pos = q[i].second;

                if(tmp->left) v.push_back({tmp->left, pos * 2});
                if(tmp->right) v.push_back({tmp->right, pos * 2 + 1});
            }

            q = v;
        }
         
        return maxwid;
    }
};
// @lc code=end
//二刷：思路同一刷，注意用unsigned int哪怕计算结果为负数也会通过环形取到正确的正数；pair初始化用<>
//一刷：数组模拟队列宽搜，存二叉树的节点和对应下标，注意数据用unsigned int（溢出会成环）
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        typedef TreeNode Node;
        if(!root) return 0;
        vector<pair<Node*, unsigned int>> q;

        q.push_back({root, 1}); //从1开始

        unsigned int ret = 0;

        while(q.size() != 0)
        {
            //更新本层
            auto& [x1, y1] = q[0];
            auto& [x2, y2] = q.back();
            ret = max(ret, y2 - y1 + 1);

            //下一层入队
            vector<pair<Node*, unsigned int>> tmp;
            for(int i=0; i<q.size(); ++i)
            {
                Node* node = q[i].first;
                unsigned int pos = q[i].second;

                if(node->left) tmp.push_back({node->left, 2 * pos});
                if(node->right) tmp.push_back({node->right, 2 * pos + 1});
            }

            //覆盖数组
            q = tmp;
        }
        
        return ret;
    }
};
