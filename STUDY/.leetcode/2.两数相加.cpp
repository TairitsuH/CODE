/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head1 = l1;
        ListNode* head2 = l2;

        while(head1 && head2)
        {
            head1->val += head2->val;
            head2->val = head1->val;

            head1 = head1->next;
            head2 = head2->next;
        }

        ListNode* head = l1;
        if(!head1)
        {
            head = l2;
        }

        ListNode* tmp = head;
        while(tmp)
        {
            int add = tmp->val / 10;
            tmp->val %= 10;
            if(!tmp->next && add >= 1)
            {
                ListNode* obj = new ListNode(add);
                tmp->next = obj;
                break;
            }
            else if(add >= 1)
            {
                tmp->next->val += add;
            }

            tmp = tmp->next;
        }

    return head;
    }
};
// @lc code=end

//一刷：高精度加法思想，不过!表示空指针的问题真的不能再犯了TvT

