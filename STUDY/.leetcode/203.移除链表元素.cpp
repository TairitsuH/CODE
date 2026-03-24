/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val)
    {
        //头结点等于val时
        while(head != NULL && head -> val == val)
        {
            ListNode* tmp = head;
            head = head -> next;
            delete tmp; //一定要先指向下一个结点再删除！否则就无法找到下一个了
        }

        //非头结点等于val时
        ListNode* cur = head; //cur为current，表示当前结点
        while(cur != NULL && cur -> next != NULL)
        {
            if(cur -> next -> val == val) //head所在结点不为val，所以直接判断下一个结点的val
            {
                ListNode* tmp = cur -> next;
                cur -> next = cur -> next -> next; //让下一个结点指向下下个结点
                delete tmp;
            } 
            else
            {
                cur = cur -> next;
            }
        }

        return head;
    }
};
// @lc code=end

//一刷：没接触过用结构体实现，仅仅学过数组模拟链表，是照着题解边打边理解的

