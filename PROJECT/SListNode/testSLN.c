#include<stdio.h>
#include "SListNode.h"
#include "SListNode.c"

int main()
{
    SLTNode* plist = NULL;
    // SLTNode* new1 = SLTBuyNode(1);
    // SLTNode* new2 = SLTBuyNode(2);
    // SLTNode* new3 = SLTBuyNode(3);
    // SLTNode* new4 = SLTBuyNode(4);

    // new1->next = new2;
    // new2->next = new3;
    // new3->next = new4;
    // new4->next = NULL;

    // SLTNode** pphead = &new1;

    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushBack(&plist, 4);

    // SLTFind(plist, 1);
    // SLTFind(plist, 2);
    // SLTFind(plist, 3);
    // SLTFind(plist, 4);
    // SLTFind(plist, 6);

    SLTInsertBack(plist, 10);
    // SLTErase(&plist, plist->next);

    // SLTEraseAfter(plist);


    SLTPrint(plist);

    SLTDestroy(&plist);

    // SLTPopBack(&plist);
    // SLTPopBack(&plist);
    // SLTPopBack(&plist);
    // SLTPopBack(&plist);

    // SLTPopFront(&plist);
    // SLTPrint(plist);
    // SLTPopFront(&plist);
    // SLTPrint(plist);
    // SLTPopFront(&plist);
    // SLTPrint(plist);
    // SLTPopFront(&plist);
    // SLTPrint(plist);

    return 0;
}