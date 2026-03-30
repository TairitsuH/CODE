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
        ListNode* DummyHead = new ListNode(0); //创建虚拟头结点
        DummyHead -> next = head;
        ListNode* cur = DummyHead;
        while(cur -> next != NULL)
        {
            if(cur -> next -> val == val)
            {
                ListNode* tmp = cur -> next;
                cur -> next = tmp -> next;
                delete tmp;
            }
            else //不要忘记不符合时要指向next！！否则会陷入死循环TvT
            {
                cur = cur -> next;
            }
        }
        head = DummyHead -> next;
        delete DummyHead; //记得释放内存
        return head;
    }
};
// @lc code=end

//一刷：没接触过用结构体实现，仅仅学过数组模拟链表，是照着题解边打边理解的
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val)
//     {
//         //头结点等于val时
//         while(head != NULL && head -> val == val) //用while不用if避免连续多个头结点都为val
//         {
//             ListNode* tmp = head;
//             head = head -> next;
//             delete tmp; //一定要先指向下一个结点再删除！否则就无法找到下一个了
//         }

//         //非头结点等于val时
//         ListNode* cur = head; //cur为current，表示当前结点
//         while(cur != NULL && cur -> next != NULL)
//         //接下来要操作cur->next，避免为空；同时也要取cur->的值，避免为空
//         {
//             if(cur -> next -> val == val) //head所在结点不为val，所以直接判断下一个结点的val
//             {
//                 ListNode* tmp = cur -> next;
//                 cur -> next = cur -> next -> next; //让下一个结点指向下下个结点
//                 delete tmp;
//             } 
//             else
//             {
//                 cur = cur -> next;
//             }
//         }

//         return head;
//     }
// };

//二刷：试了下虚拟头结点，不用分类讨论真不错！不过还是有很多细节需要注意
//test

//三刷：C语言版本
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    while(head != NULL && head->val == val)
    {
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }

    struct ListNode* pos = head;
    while(pos != NULL && pos->next != NULL)
    {
        if(pos->next->val == val)
        {
            struct ListNode* tmp = pos->next;
            pos->next = pos->next->next;
            free(tmp);
        }
        else
        {
            pos = pos->next;
        }
    }
    
    return head;
}