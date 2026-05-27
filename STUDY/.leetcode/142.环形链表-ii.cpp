/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* cur = head;
        set<ListNode*> s;
        while(cur)
        {
            if(s.count(cur))
            {
                return cur;
            }
            
            s.insert(cur);
            cur = cur->next;
        }

        return nullptr;
    }
};
// @lc code=end

//一刷：用set的方式做了

