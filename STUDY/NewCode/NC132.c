// #include<stdio.h>
// #include<stdlib.h>

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param n int整型 
 * @param m int整型 
 * @return int整型
 */
//创建链表
typedef struct SLTNode
{
    int data;
    struct SLTNode* next;

}SLTNode;

//初始化链表
SLTNode* SLInit(int num)
{
    SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
    if(tmp)
    {
        tmp->data = num;
        tmp->next = NULL;
        return tmp;
    }
    exit(1);
}

//形成链表
SLTNode* SLForm(SLTNode* head, int n)
{
    SLTNode* tail = head;
    for(int i=2; i<=n; i++)
    {
        SLTNode* tmp = SLInit(i);
        tail->next = tmp;
        tail = tail->next; //最后一个节点
    }

    if(n == 1) return head;
    return tail;
}

int ysf(int n, int m)
{
    SLTNode* head = SLInit(1);
    SLTNode* tail = SLForm(head, n);

    tail->next = head; //闭环

    SLTNode* tmp = tail;
    SLTNode* prev = tmp;

    while(tmp->next != tmp)
    {
        for(int i=1; i<=m; i++)
        {
            prev = tmp;
            tmp = tmp->next; //这里才真正开始计数
        }
        prev->next = tmp->next;
        free(tmp);
        tmp = prev; //细节：tmp要从上一个节点开始！
    }
    return tmp->data;
}

// int main()
// {
//     int a = ysf(6, 3);
//     printf("%d", a);
//     return 0;
// }

//一刷：听懂和写代码真的是两回事......很多细节需要注意