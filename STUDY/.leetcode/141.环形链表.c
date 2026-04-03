/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LTNode;

bool hasCycle(struct ListNode *head)
{
    LTNode* slow = head;
    LTNode* fast = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}
// @lc code=end

//一刷：巧妙的思路！快慢指针，采用快走2步，慢走一步的方式，如果存在环则转化为追及问题！
