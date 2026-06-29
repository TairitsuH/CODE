/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head->next) return head;

        ListNode* c1 = head;
        ListNode* c2 = head->next;
        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;

        while(c1 && c2)
        {
            ListNode* tmp = c2->next;
            c1->next = tmp;
            c2->next = c1;

            prev->next = c2;
            prev = c1;
            c1 = c1->next;

            if(!c1) break;
            c2 = c1->next;
        }

        ListNode* ret = newhead->next;
        delete newhead;
        return ret;
    }
};
// @lc code=end
//一刷：整体不难，模拟方式，循环交换。一定要舍得画图！分类讨论好每一种情况！注意顺序，引入头结点方便操作
