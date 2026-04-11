#include<stdio.h>

void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//向下调整建大堆
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child+1] > a[child])
        {
            child += 1;
        }

        if(a[parent] < a[child])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* a, int n)
{
    //建堆
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    //交换删除
    int end = n-1;
    while(end > 0)
    {
        Swap(&a[end], &a[0]);

        AdjustDown(a, end, 0);
        end--;
    }
}

int main()
{
    int a[10] = {3, 4, 1, 9, 6, 5, 0, 2 ,8, 7};

    HeapSort(a, 10);

    for(int i=0; i<10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}


