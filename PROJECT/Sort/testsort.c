#include "Sort.h"
#include "Sort.c"

void PrintArr(int* a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10] = {6,4,8,2,3,1,5,9,7,0};
    int n = 10;
    PrintArr(a, n);

    // BubbleSort(a, n);
    // SelectSort(a, n);
    // InsertSort(a, n);
    // ShellSort1(a, n);
    // ShellSort2(a, n);
    // HeapSort(a, n);
    PrintArr(a, n);

    return 0;
}