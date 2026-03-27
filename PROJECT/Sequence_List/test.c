#include<stdio.h>
#include "SeqList.h"

int main()
{
    SL list;
    SLInit(&list);

    int x = 10;
    SLPushFront(&list, x);
    SLPushFront(&list, x);
    SLPushFront(&list, x);

    int y = 5;
    SLPushBack(&list, y);
    SLPushBack(&list, y);
    SLPushBack(&list, y);

    // PopFront(&list);
    // PopFront(&list);
    // PopBack(&list);
    // PopBack(&list);

    int z = 1;
    int pos = 3;
    SLInsert(&list, 0, z);
    SLInsert(&list, list.size, x);

    // SLErase(&list, 0);
    // SLErase(&list, list.size-1);


    SLPrint(&list);

    SLFind(&list, 1);


    return 0;
}