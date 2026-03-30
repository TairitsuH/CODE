/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        struct ListNode* p1 = head;
        struct ListNode* p2 = head;

        while(p2 && p2->next)
        {
            p2 = p2->next; 
            p2 = p2->next;
            p1 = p1->next; 
        }
        return p1;
    }
};
// @lc code=end

