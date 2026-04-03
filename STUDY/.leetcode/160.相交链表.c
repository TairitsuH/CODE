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

// @lc code=end
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
    LTNode* pcura = headA;
    LTNode* pcurb = headB;
    int la = 1, lb = 1; //由于要比较尾节点，所以不能等到NULL才停止遍历，因此长度要+1才是总长度

    while(pcura->next)
    {
        pcura = pcura->next;
        la++;
    }
    while(pcurb->next)
    {
        pcurb = pcurb->next;
        lb++;
    }

    if(pcura != pcurb) return NULL; //尾节点不同

    int n = abs(la - lb);
    LTNode* l = headA, *s = headB;
    if(la < lb)
    {
        l = headB;
        s = headA;
    }

    while(n--)
    {
        l = l->next;
    }

    while(l != s)
    {
        l = l->next;
        s = s->next;
    }

    return l;
}

//三刷：整体思路：首次遍历计算出两个链表的长度并判断尾部节点是否为同一个（不同就可以返回NULL了）；
//计算出长度差，移动长指针使两指针对齐；第二次遍历，直接找出相交的第一个节点并返回。
//一遍过！verygooooooood!!![]~(￣▽￣)~*

//二刷：用假设法解决较长链表后移问题，题解区的大佬思路无敌了orz
// typedef struct ListNode LTNode;
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
// {
//     LTNode* cura = headA;
//     LTNode* curb = headB;
//     int la = 1, lb = 1;
//     while(cura->next)
//     {
//         cura = cura->next;
//         la++;
//     }
//     while(curb->next)
//     {
//         curb = curb->next;
//         lb++;
//     }

//     //不相交
//     if(cura != curb) return NULL;

//     int n = abs(la - lb);
//     LTNode* long1 = headA;
//     LTNode* short1 = headB;
//     if(la < lb)
//     {
//         long1 = headB;
//         short1 = headA;
//     }
//     while(n--)
//     {
//         long1 = long1->next;
//     }

//     while(long1 != short1)
//     {
//         long1 = long1->next;
//         short1 = short1->next;
//     }
//     return long1;
// }

//一刷：错误思路：两个指针分别从两个链表头节点开始遍历，直到遇到相同节点，此时进入第二个循环，判断后续节点是否相同，若不同则重新返回第一循环。
//不对不对，链表的长度不一定相同！这个思路算是报废了
//新错误思路：链表全部逆置，然后再从新的头结点比较？ 没招了，还是不行，题目要求是链表必须要求原结构TvT
//反思：有长度差的链表好像都可以通过计算长度差，让较长链表的指针移动这个长度。这样就可以进行比较了
//易错点：注意比较的是地址不是值，相交的含义是节点位于同一块内存
// typedef struct ListNode LTNode;
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
// {
//     LTNode* ha = headA;
//     LTNode* hb = headB;

//     int cna = 0;
//     int cnb = 0;
//     while(ha)
//     {
//         ha = ha->next;
//         cna++;
//     }
//     while(hb)
//     {
//         hb = hb->next;
//         cnb++;
//     }
//     ha = headA;
//     hb = headB;
//     int n = abs(cna-cnb);
//     while(cnb > cna)
//     {
//         hb = hb->next;
//         cnb--;
//     }
//     while(cna > cnb)
//     {
//         ha = ha->next;
//         cna--;
//     }

//     LTNode* tmp;
//     while(ha && hb)
//     {
//         if(ha == hb) tmp = ha;
//         while(ha == hb)
//         {
//             if(ha == NULL) return tmp;
//             ha = ha->next;
//             hb = hb->next;
//         }
//         tmp = NULL;
//         ha = ha->next;
//         hb = hb->next;
//     }
//     return tmp;
// }