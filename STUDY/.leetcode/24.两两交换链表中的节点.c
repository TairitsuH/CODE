/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
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
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL) return head;

    LTNode* dum = (LTNode*)malloc(sizeof(LTNode));
    dum->next = head;
    LTNode* cur = dum;

    while(cur->next && cur->next->next)
    {
        LTNode* first = cur->next;
        LTNode* second = cur->next->next;
        LTNode* third = cur->next->next->next;

        cur->next = second;
        second->next = first;
        first->next = third;

        cur = first;
    }
    return dum->next;
}
// @lc code=end

//一刷：分类讨论很乱，指针太多导致的。感谢DeepSeek老师！！果然还是不能跳步骤，要一步步来。太容易对空指针解引用了啊啊TvT
//cur每次操作两个节点。（以4 / 5个节点来举例）
//偶数个节点时，cur最后指向4，此时cur->next为NULL，已经完成所有的交换，循环终止；
//奇数个节点时，cur最后指向4，此时cur->next为5，不需要交换，cur->next->next为NULL，循环终止；
//注意while内的条件顺序不能交换！否则就可能会对空指针解引用了
//关键：遍历的终止条件，两两交换的逻辑