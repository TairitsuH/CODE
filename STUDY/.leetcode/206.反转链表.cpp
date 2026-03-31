/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LTNode;
struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL) return head;

    LTNode *n1 = NULL;
    LTNode *n2 = head;
    LTNode *n3 = n2->next;

    while(n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3 != NULL) n3 = n3->next;
    }

    return n1;
}



//二刷
//一刷：需要注意最后一次循环中当n3为NULL时不可再次解引用。
// struct ListNode* reverseList(struct ListNode* head)
// {
//     if(head == NULL) return head;
//     struct ListNode* n1 = NULL;
//     struct ListNode* n2 = head;
//     struct ListNode* n3 = n2->next;

//     while(n2)
//     {
//         n2->next = n1;
//         n1 = n2;
//         n2 = n3;
//         if(n3 != NULL) n3 = n3->next;
//     }
//     return n1;
// }

