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
    typedef ListNode Node;
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n = lists.size();
        return Merge(lists, 0, n - 1);
    }

    Node* Merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left > right) return nullptr;
        if(left == right) return lists[left]; //只有一个链表的时候

        int mid = (left + right) / 2;

        Node* n1 = Merge(lists, left, mid);
        Node* n2 = Merge(lists, mid + 1, right);

        return Merge_Sort(n1, n2);
    }

    Node* Merge_Sort(Node* n1, Node* n2)
    {
        if(!n1) return n2;
        if(!n2) return n1;

        Node* newhead = new Node(0);
        Node* cur = newhead;

        while(n1 && n2)
        {
            if(n1->val <= n2->val)
            {
                cur->next = n1;
                n1 = n1->next;
            }
            else
            {
                cur->next = n2;
                n2 = n2->next;
            }

            cur = cur->next;
        }

        while(n1)
        {
            cur->next = n1;
            n1 = n1->next;
            cur = cur->next;
        }

        while(n2)
        {
            cur->next = n2;
            n2 = n2->next;
            cur = cur->next;
        }

        Node* ret = newhead->next;
        delete newhead;
        return ret;
    }
};

// @lc code=end

//三刷：归并排序解法（分治 + 递归），和堆解法一样都是O(NKlogK)，注意这里的递归需要分成两个函数写
//二刷：注意lists中可能存储nullptr，入堆前先判断（堆解法）
// class Solution {
// public:
//     typedef ListNode Node;

//     struct cmp
//     {
//         bool operator()(Node* n1, Node* n2)
//         {
//             return n1->val > n2->val;
//         }
//     };

//     ListNode* mergeKLists(vector<ListNode*>& lists)
//     {
//         priority_queue<Node*, vector<Node*>, cmp> heap;

//         for(auto& l : lists)
//         {
//             if(l)
//             {
//                 heap.push(l);
//             } 
//         }

//         Node* newhead = new Node(0);
//         Node* cur = newhead;

//         while(!heap.empty())
//         {
//             Node* tmp = heap.top();
//             heap.pop();
//             cur->next = tmp;

//             if(tmp->next)
//             {
//                 heap.push(tmp->next);
//             }

//             cur = cur->next;
//         }

//         Node* ret = newhead->next;
//         delete newhead;
//         return ret;
//     }
// };
//一刷：堆的解法，先创建一个小根堆，每个数组存放一个节点，共k个，每次取出堆顶元素放在新链表的后面，补齐堆中的元素，不断循环。
//注意堆的比较逻辑是优先级低为true，一遍过ψ(｀∇´)ψ
// class Solution {
// public:
//     struct cmp
//     {
//         bool operator()(ListNode* l1, ListNode* l2)
//         {
//             return l1->val > l2->val;
//         }
//     };

//     ListNode* mergeKLists(vector<ListNode*>& lists)
//     {
//         priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

//         for(auto& l : lists)
//         {
//             if(l)
//             {
//                 heap.push(l);
//                 l = l->next;
//             }
//         }

//         ListNode* newhead = new ListNode(0);
//         ListNode* cur = newhead;

//         while(!heap.empty())
//         {
//             ListNode* tmp = heap.top();
//             heap.pop();
//             if(tmp->next)
//             {
//                 heap.push(tmp->next);
//             }

//             cur->next = tmp;
//             cur = cur->next;
//         }

//         ListNode* ret = newhead->next;
//         delete newhead;

//         return ret;
//     }
// };