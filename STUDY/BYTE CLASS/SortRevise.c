#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//冒泡排序
void BubbleSort(int* a, int n)
{
    for(int i=0; i<n-1; i++) //最后一个数无法冒泡
    {
        int flag = 0;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = 1;
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
        if(flag == 0)
        {
            return;
        }
    }
}

//插入排序
void InsertSort(int* a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int end = i;
        int obj = a[end + 1]; //复制一份防止丢失
        while(end >= 0)
        {
            if(a[end] > obj)
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }

        a[end + 1] = obj;
    }
}

//希尔排序
//法一：（法二去掉j变量for循环，i变量初始值改为0）
void ShellSort(int* a, int n)
{
    int gap = n;
    while(gap >= 1)
    {
        gap = gap / 3 + 1;

        for(int j=0; j<gap; j++) //一共gap组
        {
            for(int i=j; i<n-1; i+=gap)
            {
                int end = 0;
                int obj = a[end + gap];
                while(end >= 0)
                {
                    if(a[end] > obj)
                    {
                        a[end + gap] = a[end];
                        end -= gap;
                    }
                    else
                    {
                        break;
                    }
                }

            a[end + gap] = obj;
            }
        }
    }
}

//选择排序（双指针）
void SelectSort(int* a, int n)
{
    int begin = 0;
    int end = n-1;
    while(begin < end)
    {
        int mini = begin, maxi = begin; //注意初始化为区间开头
        for(int i=begin+1; i<=end; i++)
        {
            if(a[i] < a[mini])
            {
                mini = i;
            }

            if(a[i] > a[maxi])
            {
                maxi = i;
            }
        }
        //交换
        int tmp = a[begin]; a[begin] = a[mini]; a[mini] = tmp;
        if(maxi == begin)
        {
            maxi = mini;
        }
        //交换
        tmp = a[end]; a[end] = a[maxi]; a[maxi] = tmp;

        begin++;
        end--;
    }
}

//堆排序(小堆)
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child+1] < a[child])
        {
            child += 1;
        }

        if(a[parent] > a[child])
        {
            int tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
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
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while(end > 0)
    {
        int tmp = a[end];
        a[end] = a[0];
        a[0] = tmp;

        AdjustDown(a, end, 0); //注意堆的大小要传end！

        end--;
    }
}


//基础快排（递归）
void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void QuickSort1(int* a, int begin, int end)
{
    if(begin >= end) return;

    int left = begin;
    int right = end;
    int keyi = begin;

    while(left < right)
    {
        //先移动右指针
        while(left < right && a[right] >= a[keyi])
        {
            right--;
        }

        while(left < right && a[left] <= a[keyi]) //等于号防止死循环！
        {
            left++;
        }

        if(left < right) //最后相遇时减少一次自交换
        {
            Swap(&a[left], &a[right]);
        }
    }

    Swap(&a[keyi], &a[left]);
    keyi = left;

    QuickSort1(a, begin, keyi - 1);
    QuickSort1(a, keyi + 1, end);
}

//基础快排（三数选中，小区间优化，递归）
int GetMidi(int* a, int begin, int end)
{
    int midi = (begin + end) / 2;
    if(a[begin] < a[midi])
    {
        if(a[end] < a[midi])
        {
            if(a[begin] < a[end])
            {
                return end;
            }
            else
            {
                return begin;
            }
        }
        else
        {
            return midi;
        }
    }
    else // a[begin] > a[midi]
    {
        if(a[end] < a[begin])
        {
            if(a[end] < a[midi])
            {
                return midi;
            }
            else
            {
                return end;
            }
        }
        else
        {
            return begin;
        }
    }
}

void QuickSort2(int* a, int begin, int end)
{
    int left = begin;
    int right = end;
    if(right - left + 1 <= 10)
    {
        InsertSort(a+left, right - left + 1); //传参要注意参数的种类！
        return;
    }

    //三数选中
    int keyi = GetMidi(a, left, right);
    Swap(&a[keyi], &a[left]);
    keyi = left;

    while(left < right)
    {
        //先右后左
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
            Swap(&a[left], &a[right]);
        }
    }

    //交换，更新keyi位置
    Swap(&a[left], &a[keyi]);
    keyi = left;

    //[begin, keyi - 1] keyi [keyi + 1, end]
    QuickSort2(a, begin, keyi - 1);
    QuickSort2(a, keyi + 1, end);
}

//归并排序
//手误打错成begin1 <= end2了，幸好调试出来了TvT
void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if(begin >= end) return;

    int mid = (begin + end) / 2;
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid+1, end);

    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int i = begin;
    
    while(begin1 <= end1 && begin2 <= end2)
    {
        if(a[begin1] < a[begin2])
        {
            tmp[i++] = a[begin1++];
        }
        else
        {
            tmp[i++] = a[begin2++];
        }
    }

    //补充剩余数
    if(begin1 > end1)
    {
        while(begin2 <= end2)
        {
            tmp[i++] = a[begin2++];
        }
    }
    else
    {
        while(begin1 <= end1)
        {
            tmp[i++] = a[begin1++];
        }
    }

    memcpy(a+begin, tmp+begin, sizeof(int)*(end-begin+1));
}

void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int)*n);
    if(!tmp)
    {
        perror("melloc fail");
        exit(1);
    }

    int begin = 0;
    int end = n - 1;
    _MergeSort(a, tmp, begin, end);

    free(tmp);
    tmp = NULL;
}

