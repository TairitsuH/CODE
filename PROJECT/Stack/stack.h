#pragma once

typedef int STDataType;

typedef struct Stack
{
    STDataType* a; //指向动态数组的指针
    int top; //动态数组中最后一个有效元素的下一位
    int capacity; //动态数组的总容量
}ST;

//栈的初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

//入栈和出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

//查询栈顶元素
STDataType STTop(ST* pst);

//判空
bool STEmpty(ST* pst);

//查询数据个数
STDataType STSize(ST* pst);

//打印栈的元素
//如果需要更改STDataType的类型则对应的输出格式也要更改
void STPrint(ST *pst);
