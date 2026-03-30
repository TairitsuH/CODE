/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    struct ListNode* p3 = NULL;

    int flag = 0;
    struct ListNode* newhead;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->val < p2->val)
        {
            p3 = p1;
            p3 = p3->next;
            p1 = p1->next;

        }
        else
        {
            p3 = p2;
            p3 = p3->next;
            p2 = p2->next;
        }

        if(flag == 0)
        {
            flag = 1;
            newhead = p3;
        } 
    }
    
    if(p2 != NULL) p3 = p2;
    if(p1 != NULL) p3 = p1;

    return newhead;
}
// @lc code=end

