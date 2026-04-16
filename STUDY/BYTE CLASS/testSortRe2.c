#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SortRevise2.c"

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
        a[i] = rand() % 100;
    }

    PrintArr(a, n);

    // BubbleSort(a, n);
    // QuickSort(a, 0, n-1);
    QuickSortNonR(a, 0, n-1);

    PrintArr(a, n);

    return 0;
}