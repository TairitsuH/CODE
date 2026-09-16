/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(list1 == nullptr) return list2;
        else if(list2 == nullptr) return list1;

        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end
//四刷：递归，注意走到头时返回另一个链表的头节点
//三刷：递归思路，找重复子问题（取出两个节点中较小的一个）->
//单独子问题分析（取出节点->拼接节点->最后返回头指针）->
//递归出口（其中一个走到空，返回另一个）（其实可以不用另开函数）
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(list1 == nullptr) return list2;
        else if(list2 == nullptr) return list1;
        
        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }
};

//二刷：设置虚拟头结点（哨兵位），减少了重复代码（养成好习惯，记得free！
typedef struct ListNode LTNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //判空
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    LTNode* p1 = list1;
    LTNode* p2 = list2;
    LTNode* dumbegin = (LTNode*)malloc(sizeof(LTNode));
    LTNode* end = dumbegin;

    //p1, p2均不为空
    while(p1 && p2)
    {
        if(p1->val < p2->val)
        {
            end->next = p1;
            end = end->next;

            p1 = p1->next;
        }
        else
        {
            end->next = p2;
            end = end->next;

            p2 = p2->next;
        }
    }

    if(p1)
    {
        end->next = p1;
    }
    else
    {
        end->next = p2;
    }

    LTNode* ret = dumbegin->next;
    free(dumbegin);
    dumbegin = NULL;
    return ret;
   
}
//一刷：在原链表上操作很复杂，故直接新建链表。
//很多需要注意的细节，比如在合并前需要对数组判空，设置两个指针分别指向两个链表的开头，再新建两个指针指向新建链表的头尾。
// typedef struct ListNode LTNode;
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
// {
//     //判空
//     if(list1 == NULL) return list2;
//     if(list2 == NULL) return list1;

//     LTNode* p1 = list1;
//     LTNode* p2 = list2;
//     LTNode* begin = NULL;
//     LTNode* end = NULL;

//     //p1, p2均不为空
//     while(p1 && p2)
//     {
//         if(p1->val < p2->val)
//         {
//             if(begin == NULL) begin = end = p1;
//             else 
//             {
//                 end->next = p1;
//                 end = end->next;
//             }

//             p1 = p1->next;
//         }
//         else
//         {
//             if(begin == NULL) begin = end = p2;
//             else
//             {
//                 end->next = p2;
//                 end = end->next;
//             }
            
//             p2 = p2->next;
//         }
//     }

//     if(p1)
//     {
//         end->next = p1;
//     }
//     else
//     {
//         end->next = p2;
//     }

//     return begin;
   
// }

