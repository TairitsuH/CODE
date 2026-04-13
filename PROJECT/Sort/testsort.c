#include "Sort.h"
#include "Sort.c"
#include "time.h"

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
    int n = 50;
    int a[n];
    for(int i=0; i<n; i++)
    {
        a[i] = rand() % 100 + i;
    }
    PrintArr(a, n);

    // BubbleSort(a, n);
    // SelectSort(a, n);
    // InsertSort(a, n);
    // ShellSort1(a, n);
    // ShellSort2(a, n);
    // HeapSort(a, n);
    // QuickSort1(a, 0, n-1);
    // QuickSort2(a, 0, n-1);
    // QuickSort3(a, 0, n-1);
    // QuickSortNonR(a, 0, n-1);
    // MergeSort(a, n);
    // CountSort(a, n);
    MergeSortNonR(a, n);

    PrintArr(a, n);

    return 0;
}