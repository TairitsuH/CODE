#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../PROJECT/Stack/Stack.c"

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

// //插入排序
// void InsertSort(int* a, int n)
// {
//     for(int i=0; i<n-1; i++)
//     {
//         int end = i;
//         int obj = a[end + 1]; //复制一份防止丢失
//         while(end >= 0)
//         {
//             if(a[end] > obj)
//             {
//                 a[end + 1] = a[end];
//                 end--;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         a[end + 1] = obj;
//     }
// }

//插入排序
void InsertSort(int* a, int n)
{
    for(int i=0; i<n-1; i++)
        {
        int end = i;
        int obj = a[end + 1];
        while(end >= 0)
        {
            if(a[end] > obj) //倒序改成<
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }

        a[end + 1] = obj; //在while结束后赋值，相比在while内部可以大大减少不必要的赋值次数
    }
}

// //希尔排序
// //法一：（法二去掉j变量for循环，i变量初始值改为0）
// void ShellSort(int* a, int n)
// {
//     int gap = n;
//     while(gap >= 1)
//     {
//         gap = gap / 3 + 1;

//         for(int j=0; j<gap; j++) //一共gap组
//         {
//             for(int i=j; i<n-1; i+=gap)
//             {
//                 int end = 0;
//                 int obj = a[end + gap];
//                 while(end >= 0)
//                 {
//                     if(a[end] > obj)
//                     {
//                         a[end + gap] = a[end];
//                         end -= gap;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }

//             a[end + gap] = obj;
//             }
//         }
//     }
// }

//希尔排序
void ShellSort(int* a, int n)
{
    int gap = n-1;
    while(gap > 1)
    {
        gap = gap / 3 + 1;
        for(int j=0; j<gap; j++)
        {
            for(int i=j; i<n-gap; i+=gap)
            {
                int end = i;
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

// //选择排序
// void SelectSort(int* a, int n)
// {
//     int begin = 0;
//     int end = n-1;
//     while(begin < end)
//     {
//         int mini = begin, maxi = begin; //注意初始化为区间开头
//         for(int i=begin+1; i<=end; i++)
//         {
//             if(a[i] < a[mini])
//             {
//                 mini = i;
//             }

//             if(a[i] > a[maxi])
//             {
//                 maxi = i;
//             }
//         }
//         //交换
//         int tmp = a[begin]; a[begin] = a[mini]; a[mini] = tmp;
//         if(maxi == begin)
//         {
//             maxi = mini;
//         }
//         //交换
//         tmp = a[end]; a[end] = a[maxi]; a[maxi] = tmp;

//         begin++;
//         end--;
//     }
// }

// //堆排序(小堆)
// void AdjustDown(int* a, int n, int parent)
// {
//     int child = parent * 2 + 1;
//     while(child < n)
//     {
//         if(child + 1 < n && a[child+1] < a[child])
//         {
//             child += 1;
//         }

//         if(a[parent] > a[child])
//         {
//             int tmp = a[parent];
//             a[parent] = a[child];
//             a[child] = tmp;
//             parent = child;
//             child = parent * 2 + 1;
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// void HeapSort(int* a, int n)
// {
//     for(int i=(n-1-1)/2; i>=0; i--)
//     {
//         AdjustDown(a, n, i);
//     }

//     int end = n - 1;
//     while(end > 0)
//     {
//         int tmp = a[end];
//         a[end] = a[0];
//         a[0] = tmp;

//         AdjustDown(a, end, 0); //注意堆的大小要传end！

//         end--;
//     }
// }


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
    while(begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }

    while(begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
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

//快速排序（非递归：栈）
int PartSort(int* a, int begin, int end) //双指针快排
{
    int prev = begin, cur = begin + 1;
    int keyi = begin;
    while(cur <= end)
    {
        if(a[cur] < a[keyi])
        {
            prev++;
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[keyi], &a[prev]);
    return prev;
}
void QuickSortNonR(int* a, int begin, int end)
{
    ST st;
    STInit(&st);

    //入栈先左后右
    STPush(&st, begin);
    STPush(&st, end);

    while(!STEmpty(&st))
    {
        //出栈先右后左
        int right = STTop(&st);
        STPop(&st);
        int left = STTop(&st);
        STPop(&st);

        //排序
        int keyi = PartSort(a, left, right);

        //拆分入栈
        if(left < keyi - 1)
        {
            STPush(&st, left);
            STPush(&st, keyi - 1);
        }
        if(keyi + 1 < right)
        {
            STPush(&st, keyi+1);
            STPush(&st, right);
        }
    }

    STDestroy(&st);
}

//归并排序（非递归：循环，后序）
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if(!tmp)
    {
        perror("malloc fail");
        exit(1);
    }

    int gap = 1;
    while(gap < n)
    {
        for(int i=0; i<n; i+=gap * 2)
        {
            int begin1 = i, end1 = begin1 + gap - 1;
            int begin2 = i + gap, end2 = begin2 + gap - 1;

            //第一组已经有序，不必再归并
            if(begin2 >= n)
            {
                break;
            }
            //第二组元素不足
            if(end2 >= n)
            {
                end2 = n - 1;
            }

            int j = i;
            while(begin1 <= end1 && begin2 <= end2)
            {
                if(a[begin1] <= a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }

            while(begin1 <= end1)
            {
                tmp[j++]  = a[begin1++];
            }
            while(begin2 <= end2)
            {
                tmp[j++]  = a[begin2++];
            }

            memcpy(a + i, tmp + i, sizeof(int)*(end2 - i + 1) );
        }

        gap *= 2;
    }

    //不要忘记释放！
    free(tmp);
    tmp = NULL;
}


//计数排序
void CountSort(int* a, int n)
{
    //step1：找出min，max，确定范围
    int max = a[0];
    int min = a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    int range = max - min + 1;

    //step2：另外开辟空间，初始化为0
    int* tmp = (int*)calloc(range, sizeof(int));
    if(!tmp)
    {
        perror("calloc fail");
        exit(1);
    }

    //step3：统计次数
    for(int i=0; i<n; i++)
    {
        tmp[a[i] - min]++;
    }

    //step4：还原并放回数组
    int j = 0;
    for(int i=0; i<range; i++)
    {
        while(tmp[i]--)
        {
            a[j++] = i + min;
        }
    }

    //不要忘记释放！
    free(tmp);
    tmp = NULL;
}

//选择排序
void SelectSort(int* a, int begin, int end)
{
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

        Swap(&a[mini], &a[begin]);
        if(begin == maxi) maxi = mini;
        Swap(&a[end], &a[maxi]);

        //记得缩小区间范围
        begin++;
        end--;
    }
}

//堆排序
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child + 1] > a[child])
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
    //整理成堆
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    //排序
    int end = n - 1;
    while(end > 0)
    {
        Swap(&a[end], &a[0]);
        AdjustDown(a, end, 0);
        end--;
    }
}