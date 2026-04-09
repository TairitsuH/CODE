/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
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
bool isPalindrome(struct ListNode* head)
{
    if(!head) return false;

    LTNode* fast = head;
    LTNode* slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    LTNode* tmp = slow;
    LTNode* newhead = NULL;
    while(tmp)
    {
        LTNode* tmp2 = tmp->next;
        tmp->next = newhead;
        newhead = tmp;
        tmp = tmp2;
    }

    LTNode* left = head;
    LTNode* right = newhead;
    while(left && right)
    {
        if(left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

// @lc code=end

//四刷：熟悉的感觉又回来了╰(*°▽°*)╯ 一遍过~
//三刷：又有点忘了TAT，把newhead置空会更好做
// typedef struct ListNode LTNode;
// bool isPalindrome(struct ListNode* head)
// {
//     LTNode* fast = head;
//     LTNode* slow = head;
//     while(fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     LTNode* newhead = NULL;
//     LTNode* tmp = slow;
//     while(tmp)
//     {
//         LTNode* n1 = tmp->next;
//         tmp->next = newhead;
//         newhead = tmp;
//         tmp = n1;
//     }

//     LTNode* left = head;
//     LTNode* right = newhead;
//     while(left && right)
//     {
//         if(left->val != right->val)
//         {
//             return false;
//         }

//         left = left->next;
//         right = right->next;
//     }

//     return true;

// }
//二刷：先查找中间节点，记录并使中间往后的节点逆置；然后从两端开始往中间遍历，判断是否回文。
//一遍过~！我真棒ヾ(≧▽≦*)o
// typedef struct ListNode LTNode;
// bool isPalindrome(struct ListNode* head)
// {
//     LTNode* fast = head, *slow = head;

//     //查找中间节点
//     while(fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     //逆置
//     LTNode* newhead = NULL;
//     while(slow)
//     {
//         LTNode* tmp = slow->next;
//         slow->next = newhead;
//         newhead = slow;
//         slow = tmp;
//     }

//     LTNode* headleft = head;
//     while(headleft && newhead)
//     {
//         if(headleft->val != newhead->val) return false;
//         headleft = headleft->next;
//         newhead = newhead->next;
//     }
//     return true;
// }

//一刷：思路是先查找中间节点，然后将中间往后的节点逆置，再用双指针一头一尾比较val。
//注意点：对reverse的设计还需完善。刚开始写的时候没有设置newhead，导致slow指向NULL并回传，产生了对空指针解引用的错误
// typedef struct ListNode LTNode;
// LTNode* reverse(LTNode* slow)
// {
//     LTNode* newhead = NULL;
//     while(slow)
//     {
//         LTNode* next = slow->next;
//         slow->next = newhead;
//         newhead = slow;
//         slow = next;
//     }
//     return newhead;
// }

// bool isPalindrome(struct ListNode* head)
// {
//     LTNode* fast = head;
//     LTNode* slow = head;

//     while(fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     LTNode* rmid = reverse(slow);

//     slow = head;

//     while(slow && rmid)
//     {
//         if(slow->val != rmid->val) return false;
//         slow = slow->next;
//         rmid = rmid->next;
//     }
//     return true;
// }

