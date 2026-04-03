/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
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
struct ListNode *detectCycle(struct ListNode *head)
{
    LTNode* slow = head;
    LTNode* fast = head;
    LTNode* meet = NULL;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            meet = fast;
            break;
        }
    }
    if(fast == NULL || fast->next == NULL) return NULL;
    
    //切断
    LTNode* newhead = meet->next;
    meet->next = NULL;
    LTNode* pa = head;
    LTNode* pb = newhead;
    int la = 1, lb = 1;
    while(pa)
    {
        pa = pa->next;
        la++;
    }
    while(pb)
    {
        pb = pb->next;
        lb++;
    }

    int n = abs(la - lb);
    LTNode* l = head;
    LTNode* s = newhead;
    if(la < lb)
    {
        l = newhead;
        s = head;
    }
    while(n--)
    {
        l = l->next;
    }
    while(l != s)
    {
        l = l->next;
        s = s->next;
    }
    meet->next = newhead;
    return l;
}
// @lc code=end


//二刷：切断meet和meet->next，转化为相交链表，最后恢复为原链表即可(思路少步骤多)。
//一刷：看了题解才了解解法和原理。两个指针分别从meet和head节点开始走，相遇点即为环首节点。
//原理：L = (X-1)*C + C - N，其中L为非入环节点的长度，C为环长，N为环首到相遇点的距离，X为圈数
// typedef struct ListNode LTNode;
// struct ListNode *detectCycle(struct ListNode *head)
// {
//     LTNode* slow = head;
//     LTNode* fast = head;
//     LTNode* meet = NULL;
//     while(fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//         if(fast == slow)
//         {
//             meet = fast;
//             break;
//         }
//     }
//     if(fast == NULL || fast->next == NULL) return NULL;
//     LTNode* headb = head;
//     while(headb != meet)
//     {
//         headb = headb->next;
//         meet = meet->next;
//     }
//     return meet;
// }
