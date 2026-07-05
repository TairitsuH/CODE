/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(k == 1) return head;

        int num = 0;
        for(Node* cur=head;cur; cur=cur->next)
        {
            num++;
        }
        num /= k;

        Node* newhead = new Node(0);
        Node* prev = newhead;
        Node* cur1 = head;
        Node* next = head->next;
        Node* tail = cur1;

        if(num == 0) return nullptr;

        while(num--)
        {
            int cnt = 0;
            while(cnt < k)
            {
                Node* tmp = prev->next;
                prev->next = cur1;
                cur1->next = tmp;
                cur1 = next;
                if(cur1)
                {
                    next = next->next;
                }

                cnt++;
            }

            prev = tail;
            tail = cur1;
        }

        prev->next = cur1; //链接剩余节点

        Node* ret = newhead->next;
        delete newhead;
        return ret;
    }
};
// @lc code=end

//二刷：注意各个指针的指向关系，大大方方定义，不要吝惜变量。
//一刷：画图分析模拟，先遍历链表算出有多少组，然后一组组逆序。在计算组数记得重置num！
// class Solution {
// public:
//     typedef ListNode Node;

//     ListNode* reverseKGroup(ListNode* head, int k)
//     {
//         int set = 0;
//         int num = 0;
//         Node* n = head;
//         while(n) //或者计算出全部节点后num / k
//         {
//             num++;
//             if(num == k)
//             {
//                 set++;
//                 num = 0;
//             }

//             n = n->next;
//         }

//         Node* newhead = new Node(0);
//         Node* prev = newhead;
//         Node* cur = head;
//         Node* tail = cur;

//         while(set--)
//         {
//             tail = cur;
//             int cnt = 0;
//             while(cnt != k)
//             {
//                 Node* tmp = cur->next;
//                 Node* p = prev->next;
//                 prev->next = cur;
//                 cur->next = p;

//                 cur = tmp;
//                 cnt++;
//             }

//             // cnt == k
//             prev = tail;
//         }

//         tail->next = cur;
//         Node* ret = newhead->next;
//         delete newhead;
//         return ret;
//     }
// };
