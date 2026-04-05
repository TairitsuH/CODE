#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDataType;

//利用动态顺序表实现堆
typedef struct Heap
{
    HPDataType* a;
    int capacity;
    int size;
}Heap;

//初始化和销毁
void HPInit(Heap* php);
void HPDestroy(Heap* php);

//向上/下调整
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent); //n个元素

//插入元素
void HPPush(Heap* php, HPDataType x);

//删除堆顶元素
void HPPop(Heap* php);

//获取堆顶元素
HPDataType HPTop(Heap* php);

//判空
bool HPEmpty(Heap* php);

//打印堆
void HPPrint(Heap* php);