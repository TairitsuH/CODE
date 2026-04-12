//写排序技巧：先写一次排序（内层循环），再推广至整个数组排序（外层循环）
//这里演示的均为升序，降序仅需将大于号和小于号互换
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Stack/stack.c"
#include"../Stack/stack.h"

void Swap(int* x, int* y);

//冒泡排序
void BubbleSort(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序（双指针）
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//快速排序（递归）
void QuickSort1(int* a, int begin, int end);

//快速排序（递归，三数选中，小区间优化）
void QuickSort2(int* a, int begin, int end);

//快速排序（递归，双指针）
void QuickSort3(int* a, int begin, int end);

//快速排序（非递归：栈）
void QuickSortNonR(int* a, int begin, int end);

//归并排序（递归）
void MergeSort(int* a, int n);

//归并排序（非递归：循环）
void MergeSortNonR(int* a, int n);
