#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;


typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next; //还未声明结束，不能省略struct
}SLTNode;

//创建新节点
SLTNode* SLTBuyNode(SLTDataType x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit(1); //异常退出
    }
    newnode->data = x;
    newnode->next = NULL;

    return newnode;
}

//尾插
SLTNode* SLTPushBack(SLTNode** pphead, SLTDataType x)
{
    //有头节点
    SLTNode* pcur = *pphead;
    while(pcur->next)
    {
        pcur = pcur->next;
    }

    SLTNode* newnode = SLTBuyNode(x);

    pcur->next = newnode;
    return newnode;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int ysf(int n, int m)
        {
        SLTNode* phead = SLTBuyNode(1);
        SLTNode* ptail = SLTBuyNode(n);
        ptail->next = phead;

        if(n > 2)
        {
            SLTNode* pnew;
            for(int i=2; i<n; i++)
            {
                pnew = SLTPushBack(&phead, i);
            }
            pnew->next = ptail;
        }

        while(phead->next != phead)
        {
            int cnt = m - 1;
            while(cnt--)
            {
                phead = phead->next;
                ptail = ptail->next;
            }
            SLTNode* tmp = phead;
            phead = phead->next;
            ptail->next = phead;

            free(tmp);
            tmp = nullptr;
        }

        return phead->data;
    }
};