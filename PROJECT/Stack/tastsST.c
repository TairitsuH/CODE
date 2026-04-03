#include "stack.h"
#include "stack.c"

int main()
{
    ST st;
    STInit(&st);

    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);
    STPush(&st, 4);
    STPrint(&st);

    STPush(&st, 1);
    STPush(&st, 2);

    STPrint(&st);

    STPop(&st);
    STPrint(&st);

    STPop(&st);
    STPrint(&st);

    STPush(&st, 3);
    STPush(&st, 4);
    STPrint(&st);

    int n = STSize(&st);
    int x = STTop(&st);
    printf("现在栈中有%d个数据，栈顶元素为%d\n", n, x);

    STDestroy(&st);

    return 0;
}