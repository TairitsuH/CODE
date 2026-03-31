/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode LTNode;
struct ListNode* partition(struct ListNode* head, int x)
{
    LTNode* dumhead = (LTNode*)malloc(sizeof(LTNode));
    dumhead->next = head;
    dumhead->val = -300;

    LTNode *s, *ps;
    ps = dumhead;
    s = head;

    while(s != NULL)
    {
        if(s->val >= x || ps == dumhead)
        {
            ps = s;
            s = s->next;
        }
        else if(s-> val < x)
        {
            LTNode* tmp = s->next;

            ps->next = s->next;
            s->next = dumhead->next;
            dumhead->next = s;
            s = tmp;
        }
    }

    return dumhead->next;
}

//一刷：坑点：返回值不应为head，因为头结点在头插的过程中已经被改变。