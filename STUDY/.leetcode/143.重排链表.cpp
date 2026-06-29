/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head)
    {
        if(!head->next || !head->next->next) return;

        ListNode* cur1 = head;
        ListNode* cur2 = head;

        while(cur2->next && cur2->next->next)
        {
            cur1 = cur1->next;
            cur2 = cur2->next->next;
        }

        ListNode* mid = cur1;
        ListNode* cur3 = cur1->next;
        while(cur3)
        {
            ListNode* tmp = cur3->next; //临时变量存储避免死循环！
            cur3->next = cur1;
            cur1 = cur3;
            cur3 = tmp;
        }

        ListNode* left = head;
        ListNode* right = cur1;
        while(left != mid)
        {
            ListNode* tmpr = right->next;
            ListNode* tmpl = left->next;
            right->next = left->next;
            left->next = right;
            right = tmpr;
            left = tmpl;
        }

        right->next = nullptr;
    }
};
// @lc code=end
//一刷：先找到中间节点，逆序右边部分，最后合并两个链表。主逻辑竟然一遍过了！就是在逆序链表的时候稍微死循环了TvT

