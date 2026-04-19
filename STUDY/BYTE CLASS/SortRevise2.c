#include"../../PROJECT/Stack/Stack.c"

void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int flag = 0;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = 1;
                Swap(&a[j], &a[j+1]);
            }
        }
        if(flag == 0)
        {
            return;
        }
    }
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int begin, int end)
{
    int left = begin, right = end;
    int keyi = begin;
    while(left < right)
    {
        //右边先走
        while(left < right && a[right] >= a[keyi])
        {
            right--;
        }
        while(left < right && a[left] <= a[keyi])
        {
            left++;
        }

        if(left < right)
        {
            Swap(a+left, a+right);
        }
    }

    Swap(a+keyi, a+left);
    keyi = left;
    return keyi;
}

// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{
    int left = begin;
    int right = end;
    int key = a[begin];
    int keyi = begin;
    while(left < right)
    {
        while(left < right && a[right] >= key)
        {
            right--;
        }
        while(left < right && a[left] <= key)
        {
            left++;
        }

        // 注意挖坑法不是原地交换，不能写if(left < right)
        a[keyi] = a[right];
        a[right] = a[left];
        keyi = left;

    }

    a[keyi] = key;
    return keyi;
}
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end)
{
    int keyi = begin;
    int cur = begin + 1;
    int prev = cur;
    while(prev <= end)
    {
        if(a[prev] < a[keyi])
        {
            Swap(&a[prev], &a[cur]);
            cur++;
        }

        prev++;
    }
    Swap(a+keyi, a+cur-1);
    keyi = cur-1;
    return keyi;
}


void QuickSort(int* a, int begin, int end)
{
    if(begin >= end)
    return;

    // int keyi2 = PartSort1(a, begin, end);
    int keyi2 = PartSort2(a, begin, end);
    // int keyi2 = PartSort3(a, begin, end);
    QuickSort(a, begin, keyi2-1);
    QuickSort(a, keyi2+1, end);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end)
{
    ST st;
    STInit(&st);

    STPush(&st, begin);
    STPush(&st, end);

    while(!STEmpty(&st))
    {
        int right = STTop(&st);
        STPop(&st);
        int left = STTop(&st);
        STPop(&st);

        int keyi2 = PartSort2(a, left, right);

        if(left < keyi2 - 1)
        {
            STPush(&st, left);
            STPush(&st, keyi2-1);
        }

        if(keyi2 + 1 <right)
        {
            STPush(&st, keyi2+1);
            STPush(&st, right);
        }
    }

    STDestroy(&st);
}