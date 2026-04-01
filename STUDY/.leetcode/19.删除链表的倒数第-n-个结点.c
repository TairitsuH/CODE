/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    LTNode* dum = (LTNode*)malloc(sizeof(LTNode));
    dum->val = 0;
    dum->next = head;
    LTNode* fast = dum;
    LTNode* slow = dum;
    n += 1;
    while(n-- && fast)
    {
        fast = fast->next;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    //删除
    slow->next = slow->next->next;
    head = dum->next;
    free(dum);
    return head;
}
// @lc code=end

//二刷：快慢指针，先让fast走n+1步让两个指针距离为n，然后两个指针同时移动，
//当快指针指向NULL时慢指针指向倒数第n个的前一个节点，就可以删除了

//一刷：思路是先扫描一遍得出size，再找到倒数第n个节点删除。
//还是老生常谈的细节问题没处理好，比如仅剩一个节点的时候需要特殊处理，总是混淆prev和prev->next这两个赋值对象
// typedef struct ListNode LTNode;
// struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
// {
//     if(head->next == NULL) return NULL;
//     LTNode* dum = (LTNode*)malloc(sizeof(LTNode));
//     dum->next = head;

//     LTNode* pcur = dum;
//     int size = 0;
//     while(pcur->next)
//     {
//         pcur = pcur->next;
//         size++;
//     }

//     int cur = size - n + 1;
//     LTNode* prev = dum;
//     pcur = dum;
//     while(cur--)
//     {
//         prev = pcur;
//         pcur = prev->next;
//     }
//     prev->next = prev->next->next; //易错！
//     free(pcur);
//     pcur = NULL;
//     LTNode* tmp = dum->next;
//     free(dum);
//     dum = NULL;
//     return tmp;
// }

