/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode LTNode;
int kthToLast(struct ListNode* head, int k)
{
    LTNode* fast = head;
    LTNode* slow = head;
    while(k--)
    {
        fast = fast->next;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}

//一刷：双指针哈哈