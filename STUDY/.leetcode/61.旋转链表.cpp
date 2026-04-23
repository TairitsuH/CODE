/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head) return nullptr;

        int len = 1;
        ListNode* tail = head;
        while(tail->next)
        {
            len++;
            tail = tail->next;
        }

        k %= len;
        if(k == 0)
        {
            return head;
        }





    }
};
// @lc code=end

//一刷：思路是不改变next仅改变值，利用三次逆置实现(完了！逆置好像是回不去的O.o)