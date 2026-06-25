/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
    typedef ListNode Node;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        Node* newhead = new Node(0);
        Node* prev = newhead;

        Node* cur1 = l1;
        Node* cur2 = l2;
        int s = 0;

        while(cur1 || cur2 || s)
        {
            if(cur1)
            {
                s += cur1->val;
                cur1 = cur1->next;
            }

            if(cur2)
            {
                s += cur2->val;
                cur2 = cur2->next;
            }

            prev->next = new Node(s % 10);
            prev = prev->next;
            s /= 10;
        }

        prev = newhead->next;
        delete newhead;

        return prev;
    }
};
// @lc code=end

//二刷：很多细节需要注意！例如prev需要跳跃到下一个节点，最后需要销毁虚拟头结点等等。
//一刷：高精度加法思想，不过!表示空指针的问题真的不能再犯了TvT。存在一些编译上的小错误，比如把tmp->val写成tmp之类的
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         if(!l1 && !l2) return nullptr;
//         if(!l1) return l2;
//         if(!l2) return l1;

//         ListNode* head1 = l1;
//         ListNode* head2 = l2;

//         while(head1 && head2)
//         {
//             head1->val += head2->val;
//             head2->val = head1->val;

//             head1 = head1->next;
//             head2 = head2->next;
//         }

//         ListNode* head = l1;
//         if(!head1)
//         {
//             head = l2;
//         }

//         ListNode* tmp = head;
//         while(tmp)
//         {
//             int add = tmp->val / 10;
//             tmp->val %= 10;
//             if(!tmp->next && add >= 1)
//             {
//                 ListNode* obj = new ListNode(add);
//                 tmp->next = obj;
//                 break;
//             }
//             else if(add >= 1)
//             {
//                 tmp->next->val += add;
//             }

//             tmp = tmp->next;
//         }

//     return head;
//     }
// };
