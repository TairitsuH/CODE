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
        }

        a[end + 1] = obj;
    }
}


//希尔排序（预排序+插入排序，插入排序已被预排序包含）
//法一：逐组进（三层循环）
void ShellSort1(int* a, int n)
{
    int gap = n;
    while(gap > 1) //gap为1时为插入排序（最后一次循环先判断再变为1，因此不用加=）
    {
        gap = gap / 3 + 1;
        for(int j=0; j<gap; j++) //一共有gap数量的组
        {
            for(int i=j; i<n-gap; i+=gap) //改为n-gap，否则会越界；i要从j开始！（每组的第一个数）
            {
                int end = i;
                int obj = a[end + gap];
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
                a[end + gap] = obj;
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
            int obj = a[end + gap];
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
            a[end + gap] = obj;
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
void QuickSort1(int* a, int begin, int end)
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
    //小区间优化（插入排序）
    if((end - begin) + 1 <= 10)
    {
        InsertSort(a+begin, end-begin+1);
        return;
    }

    //三数取中
    int midi = GetMidi(a, begin, end);
    Swap(&a[midi], &a[begin]);

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

        //再次比较减少一次自交换
        if(left < right)
        {
            Swap(&a[left], &a[right]);
        }
    }

    //当两指针重合时交换keyi和重合点，更新keyi
    Swap(&a[keyi], &a[left]);
    keyi = left;

    //继续递归
    QuickSort2(a, begin, keyi - 1);
    QuickSort2(a, keyi + 1, end);
}

//快速排序（双指针）
int PartSort(int* a, int left, int right)
{
    int keyi = left;
    int prev = left;
    int cur = prev + 1;
    while(cur <= right)
    {
        if(a[cur] <= a[keyi])
        {
            prev++;
            Swap(&a[prev], &a[cur]);
        }

        cur++;
    }

    Swap(&a[keyi], &a[prev]);
    return prev;
}

void QuickSort3(int* a, int begin, int end)
{
    int left = begin;
    int right = end;

    if(right - left + 1 < 10)
    {
        InsertSort(a + begin, end - begin + 1); //特别注意不是从0位置开始插入排序！不要传错了
    }
    else
    {
        //双指针排序
        int keyi = PartSort(a, left, right);

        QuickSort3(a, begin, keyi - 1);
        QuickSort3(a, keyi + 1, end);
    }
}

//快速排序（非递归：栈）
void QuickSortNonR(int* a, int begin, int end)
{
    //数组首尾下标入栈
    ST st;
    STInit(&st);
    STPush(&st, begin);
    STPush(&st, end);

    //循环出入
    while(!STEmpty(&st))
    {
        //先入后出
        int right = STTop(&st);
        STPop(&st);
        int left = STTop(&st);
        STPop(&st);

        //排序
        int keyi = PartSort(a, left, right);

        //入栈(要判断边界是否有效！)
        // [left, keyi - 1] keyi [keyi + 1, right]
        if(left < keyi - 1)
        {
            STPush(&st, left);
            STPush(&st, keyi - 1);
        }

        if(keyi + 1 < right)
        {
            STPush(&st, keyi + 1);
            STPush(&st, right);
        }
    }

    STDestroy(&st);
}

//归并排序（递归）
void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if(begin >= end) return;

    int mid = (begin + end) / 2;

    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);

    int begin1 = begin, begin2 = mid + 1;
    int end1 = mid, end2 = end;
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

    //处理剩余数据
    while(begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }
    while(begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }

    //拷贝(不能用begin1因为已经被更改)
    memcpy(a+begin, tmp+begin, (end - begin + 1) * sizeof(int));

}

void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(n*sizeof(int));
    if(tmp == NULL)
    {
        perror("malloc fail");
        exit(1);
    }

    _MergeSort(a, tmp, 0, n-1);

    free(tmp);
    tmp = NULL;
}