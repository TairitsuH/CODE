/*
 * @lc app=leetcode.cn id=138 lang=c
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
    if(!head)
    {
        return NULL;
    }

    Node* pcur = head;
    while(pcur)
    {
        Node* tmp = pcur->next;
        Node* cpy = (Node*) malloc (sizeof(Node));
        if(!cpy)
        {
            exit(1);
        }
        cpy->val = pcur->val;

        pcur->next = cpy;
        cpy->next = tmp;
        pcur = tmp;
    }

    pcur = head;
    while(pcur)
    {
        Node* cpy = pcur->next;
        if(!pcur->random)
        {
            cpy->random = NULL;
        }
        else
        {
            cpy->random = pcur->random->next;
        }
        pcur = cpy->next;
    }

    Node* newhead = head->next;
    Node* cpy = newhead;
    while(cpy->next)
    {
        cpy->next = cpy->next->next;
        cpy = cpy->next; //二刷忘记移动指针了TvT
    }
    return newhead;
}
// @lc code=end


//二刷：新建节点放在对应节点后，复制val，串联；复制random；改变next，返回新的头节点。
//错误思路：遍历原链表，先复制val和next，再次遍历，复制random，遍历找到对应节点然后设置random。
//但是通过遍历找到random的节点存在问题，val可能重复，所以找到的标准不能确定，思路报废TvT
//不过第一次就大致实现了自己的思路（除了没有在开头判空，其他部分都对），没有其他编译错误，还是可喜可贺的
//一刷：非常巧妙的思路：复制一遍链表，使每个新节点插入对应原节点的后面，在复制random的时候就可以直接通过next进行访问了！无敌了！！
//一刷一遍过！！好耶ψ(｀∇´)ψ
// typedef struct Node Node;
// struct Node* copyRandomList(struct Node* head)
// {
//     if(head == NULL) return NULL;

//     Node* pcur = head;
//     Node* tmp = head;
//     while(pcur)
//     {
//         Node* cpy = (Node*)malloc(sizeof(Node));
//         if(cpy == NULL) exit(1);
//         tmp = pcur->next;

//         pcur->next = cpy;
//         cpy->val = pcur->val;
//         cpy->next = tmp;

//         pcur = tmp;
//     }

//     pcur = head;
//     while(pcur)
//     {
//         Node* cpy = pcur->next;
//         if(pcur->random == NULL) cpy->random = NULL;
//         else
//         {
//             cpy->random = pcur->random->next;
//         }
//         pcur = cpy->next;
//     }

//     Node* newhead = head->next;
//     Node* cpy = newhead;
//     while(cpy->next)
//     {
//         cpy->next = cpy->next->next;
//         cpy = cpy->next;
//     }
//     return newhead;
// }