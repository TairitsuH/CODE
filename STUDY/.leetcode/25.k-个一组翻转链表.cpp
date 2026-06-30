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
        int set = 0;
        int num = 0;
        Node* n = head;
        while(n) //或者计算出全部节点后num / k
        {
            num++;
            if(num == k)
            {
                set++;
                num = 0;
            }

            n = n->next;
        }

        Node* newhead = new Node(0);
        Node* prev = newhead;
        Node* cur = head;
        Node* tail = cur;

        while(set--)
        {
            tail = cur;
            int cnt = 0;
            while(cnt != k)
            {
                Node* tmp = cur->next;
                Node* p = prev->next;
                prev->next = cur;
                cur->next = p;

                cur = tmp;
                cnt++;
            }

            // cnt == k
            prev = tail;
        }

        tail->next = cur;
        Node* ret = newhead->next;
        delete newhead;
        return ret;
    }
};
// @lc code=end

//一刷：画图分析模拟，先遍历链表算出有多少组，然后一组组逆序。在计算组数记得重置num！

