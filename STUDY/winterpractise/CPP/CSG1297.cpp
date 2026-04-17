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

int main()
{
    ios::sync_with_stdio(false);  // 关闭C和C++ IO同步
    cin.tie(nullptr);              // 解除cin和cout的绑定
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >>k;

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
        int cnt = k - 1;
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

    cout << phead->data << endl;

    return 0;
}