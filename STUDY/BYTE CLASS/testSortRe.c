#include "SortRevise.c"
#include <time.h>

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
    srand(time(NULL));
    int n = 20;
    int a[n];
    for(int i=0; i<n; i++)
    {
        a[i] = rand() % 10;
    }
    PrintArr(a, n);

    // QuickSort2(a, 0, n-1);
    MergeSort(a, n);

    PrintArr(a, n);

    return 0;
}