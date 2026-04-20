// Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        if(!node) return;
        ListNode* tmp = node;
        ListNode* prev = node;
        while(tmp->next)
        {
            tmp->val = tmp->next->val;
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = nullptr;
        delete tmp;
    }
};

//一刷：总是混淆带!和不带!的区别，边界条件也没有考虑全，切记在删除最后一个节点前，需要置空倒数第二个节点的next！