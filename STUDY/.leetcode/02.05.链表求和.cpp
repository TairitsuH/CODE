/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 && p2)
        {
            p1->val += p2->val;
            p2->val = p1->val;
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* head = l1;
        if(p1 == nullptr)
        {
            head = l2;
        }

        ListNode* tmp = head;
        while(tmp)
        {
            int add = (tmp->val) / 10;
            tmp->val %= 10;
            if(tmp->next)
            {
                tmp->next->val += add;
            }
            else if(add != 0)
            {
                ListNode* tail = new ListNode(add);
                tmp->next = tail;
                break;
            }

            tmp = tmp->next;
        }

        return head;
    
    }
};

//一刷：一开始想的是一个一个节点来算，但是边界条件太多了，想到可以套用高精度加法的方法，即全部相加再进位，边界条件果然少了很多