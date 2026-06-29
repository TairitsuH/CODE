/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    struct cmp
    {
        bool operator()(ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        for(auto& l : lists)
        {
            if(l)
            {
                heap.push(l);
                l = l->next;
            }
        }

        ListNode* newhead = new ListNode(0);
        ListNode* cur = newhead;

        while(!heap.empty())
        {
            ListNode* tmp = heap.top();
            heap.pop();
            if(tmp->next)
            {
                heap.push(tmp->next);
            }

            cur->next = tmp;
            cur = cur->next;
        }

        ListNode* ret = newhead->next;
        delete newhead;

        return ret;
    }
};
// @lc code=end

//一刷：堆的解法，先创建一个小根堆，每个数组存放一个节点，共k个，每次取出堆顶元素放在新链表的后面，补齐堆中的元素，不断循环。
//注意堆的比较逻辑是优先级低为true，一遍过ψ(｀∇´)ψ
