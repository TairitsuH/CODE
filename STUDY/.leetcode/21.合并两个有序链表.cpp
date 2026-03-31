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

typedef struct ListNode LTNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //判空
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    LTNode* p1 = list1;
    LTNode* p2 = list2;
    LTNode* begin = NULL;
    LTNode* end = NULL;

    //p1, p2均不为空
    while(p1 && p2)
    {
        if(p1->val < p2->val)
        {
            if(begin == NULL) begin = end = p1;
            else 
            {
                end->next = p1;
                end = end->next;
            }

            p1 = p1->next;
        }
        else
        {
            if(begin == NULL) begin = end = p2;
            else
            {
                end->next = p2;
                end = end->next;
            }
            
            p2 = p2->next;
        }
    }

    if(p1)
    {
        end->next = p1;
    }
    else
    {
        end->next = p2;
    }

    return begin;
   
}
// @lc code=end

//一刷：在原链表上操作很复杂，故直接新建链表。
//很多需要注意的细节，比如在合并前需要对数组判空，设置两个指针分别指向两个链表的开头，再新建两个指针指向新建链表的头尾。

