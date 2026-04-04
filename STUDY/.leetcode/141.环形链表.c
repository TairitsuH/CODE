/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LTNode;
bool hasCycle(struct ListNode *head)
{
    LTNode *fast = head;
    LTNode *slow = head;
    while (fast && fast->next) //一次走两步，需要判断节点和下一个节点
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
    
}
// @lc code=end

//二刷：if的代码不太规范，还是建议仅有一条语句时也加上大括号
// 一刷：巧妙的思路！快慢指针，采用快走2步，慢走一步的方式，如果存在环则转化为追及问题！
//  typedef struct ListNode LTNode;

// bool hasCycle(struct ListNode *head)
// {
//     LTNode* slow = head;
//     LTNode* fast = head;
//     while(fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//         if(fast == slow) return true;
//     }
//     return false;
// }