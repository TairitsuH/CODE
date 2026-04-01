/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
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
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL) return head;

    LTNode* dum = (LTNode*)malloc(sizeof(LTNode));
    dum->next = head;
    LTNode* cur = dum;

    while(cur->next && cur->next->next)
    {
        LTNode* first = cur->next;
        LTNode* second = cur->next->next;
        LTNode* third = cur->next->next->next;

        cur->next = second;
        second->next = first;
        first->next = third;

        cur = first;
    }
    return dum->next;
}
// @lc code=end

//一刷：分类讨论很乱，指针太多导致的。感谢DeepSeek老师！！果然还是不能跳步骤，要一步步来。太容易对空指针解引用了啊啊TvT