/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    LTNode* ha = headA;
    LTNode* hb = headB;

    int cna = 0;
    int cnb = 0;
    while(ha)
    {
        ha = ha->next;
        cna++;
    }
    while(hb)
    {
        hb = hb->next;
        cnb++;
    }
    ha = headA;
    hb = headB;
    int n = abs(cna-cnb);
    while(cnb > cna)
    {
        hb = hb->next;
        cnb--;
    }
    while(cna > cnb)
    {
        ha = ha->next;
        cna--;
    }

    LTNode* tmp;
    while(ha && hb)
    {
        if(ha == hb) tmp = ha;
        while(ha == hb)
        {
            if(ha == NULL) return tmp;
            ha = ha->next;
            hb = hb->next;
        }
        tmp = NULL;
        ha = ha->next;
        hb = hb->next;
    }
    return tmp;
}
// @lc code=end

//一刷：错误思路：两个指针分别从两个链表头节点开始遍历，直到遇到相同节点，此时进入第二个循环，判断后续节点是否相同，若不同则重新返回第一循环。
//不对不对，链表的长度不一定相同！这个思路算是报废了
//新错误思路：链表全部逆置，然后再从新的头结点比较？ 没招了，还是不行，题目要求是链表必须要求原结构TvT
//反思：有长度差的链表好像都可以通过计算长度差，让较长链表的指针移动这个长度。这样就可以进行比较了
//易错点：注意比较的是地址不是值，相交的含义是节点位于同一块内存