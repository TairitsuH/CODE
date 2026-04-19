/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head)
        return nullptr;

        ListNode* tmp = head;
        while(tmp && tmp->next)
        {
            while(tmp && tmp->next && tmp->val == tmp->next->val)
            {
                ListNode* obj = tmp->next->next;
                delete tmp->next;
                tmp->next = obj;
            }

            tmp = tmp->next;
        }
        return head;
    }
};
// @lc code=end

//一刷：遗漏了很多需要注意的点，比如外层while检验空指针不完善，内层应该用while不能用if，用if无法处理两个以上的相同值节点

