#include "Sort.h"

//通过对地址解引用修改值
void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//冒泡排序
void BubbleSort(int* a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                Swap(&a[j], &a[j+1]);
            }
        }
    }
}

//插入排序
void InsertSort(int* a, int n)
{
    for(int i=0; i<n-1; i++) //小于n-1是因为后面涉及end+1，如果小于n会越界
    {
        int end = i;
        int obj = a[end + 1];

        while(end >= 0)
        {
            if(a[end] > obj)
            {
                a[end + 1] = a[end]; //挪动比Swap更快
                end--;
            }
            else
            {
                break;
            }

            a[end + 1] = obj;
        }
    }
}


//希尔排序（预排序+插入排序，插入排序已被预排序包含）
//法一：逐组进（三层循环）
void ShellSort1(int* a, int n)
{
    int gap = n;
    while(gap > 1) //gap为1时为插入排序
    {
        gap = gap / 3 + 1;
        for(int j=0; j<gap; j++) //一共有gap数量的组
        {
            for(int i=0; i<n-gap; i+=gap) //改为n-gap，否则会越界
            {
                int end = i;
                while(end >= 0)
                {
                    if(a[end] > a[end+gap])
                    {
                        Swap(&a[end], &a[end+gap]);
                        end-=gap;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

//法二：多组并行
void ShellSort2(int* a, int n)
{
    int gap = n;
    while(gap > 1)
    {
        gap = gap / 3 + 1;
        for(int i=0; i<n-gap; i++)
        {
            int end = i;
            while(end >= 0)
            {
                if(a[end] > a[end + gap])
                {
                    Swap(&a[end], &a[end + gap]);
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
        }
    }
}


//选择排序（双指针）
void SelectSort(int* a, int n)
{
    int begin = 0;
    int end = n - 1;

    while(begin < end)
    {
        int mini = begin, maxi = begin;
        for(int i=begin+1; i<=end; i++)
        {
            if(a[i] > a[maxi])
            {
                maxi = i;
            }
            if(a[i] < a[mini])
            {
                mini = i;
            }
        }
        Swap(&a[maxi], &a[end]);

        //避免刻舟求剑TvT
        if(mini == end) mini = maxi;

        Swap(&a[mini], &a[begin]);

        begin++;
        end--;
    }
}

//堆排序（向下调整建大堆->每次交换首尾元素并end--，向下调整）
void HeapSort(int* a, int n)
{
    //向下调整
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        int parent = i;
        int child = parent * 2 + 1;

        while(child < n)
        {
            //假设法（右孩子存在且右孩子更大）
            if(child+1<n && a[child+1] > a[child])
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

    //设置end，交换首尾元素
    int end = n-1;
    while(end)
    {
        Swap(&a[end], &a[0]);

        //向下调整
        int parent = 0;
        int child = parent * 2 + 1;

        while(child < end)
        {
            if(child+1<end && a[child+1] > a[child])
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

        end--;
    }
}

//基础快排（递归）
void QuickSort(int* a, int begin, int end)
{
    //终止条件
    if(begin >= end)
    return;

    //begin和end用于标记区间范围
    //begin和end是在区间内移动的指针
    int keyi = begin;
    int left = begin;
    int right = end;
    
    while(left < right)
    {
        //先移动右指针，小于keyi就停下
        while(left < right && a[right] >= a[keyi])
        {
            right--;
        }
        //再移动左指针，大于keyi就停下
        while(left < right && a[left] <= a[keyi])
        {
            left++;
        }

        //交换两个指针的值
        Swap(&a[left], &a[right]);
    }

    //当两指针重合时交换keyi和重合点，更新keyi
    Swap(&a[keyi], &a[left]);
    keyi = left;

    //继续递归
    QuickSort(a, begin, keyi - 1);
    QuickSort(a, keyi + 1, end);
}