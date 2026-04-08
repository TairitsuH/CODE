/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

typedef long long LL;
typedef char STDataType;
typedef struct stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

//初始化
void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0;
    pst->capacity = 0;
}

//销毁
void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->top = pst->capacity = 0;
}

//入栈
void STPush(ST* pst, STDataType x)
{
    assert(pst);
    if(pst->top == pst->capacity) //判断是否需要扩容！！
    {
        int newcapacity = pst->capacity == 0 ? 4 : 2*pst->capacity;
        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity*sizeof(STDataType));
        if(tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        pst->capacity = newcapacity;
        pst->a = tmp;
    }
    pst->a[pst->top] = x;
    pst->top++;
}

//出栈
void STPop(ST* pst)
{
    assert(pst && pst->top>0);
    pst->top--;
}

//判空
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}

//栈顶元素
STDataType STTop(ST* pst)
{
    assert(pst && pst->top > 0);
    return pst->a[pst->top-1];
}

bool isValid(char* s)
{
    ST st;
    ST* pst = &st;
    STInit(pst);

    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            STPush(pst, s[i]);
        }
        else
        {
            if(STEmpty(pst)) return false;
            
            char x = STTop(pst);
            STPop(pst);

            if((s[i] == ')' && x != '(') 
            || (s[i] == '}' && x != '{') 
            || (s[i] == ']' && x != '['))
            return false;
        }
    }

    if(STEmpty(pst))
    {
        STDestroy(pst);
        return true;
    }

    STDestroy(pst);
    return false;
}

// @lc code=end

//三刷：在s[i]为右括号时判断条件的左右括号写反了TvT
//二刷：整体的栈框架已经掌握，需要注意一些细节，比如在扩容前判断容器是否已满
// bool isValid(char* s)
// {
//     ST st;
//     STInit(&st);

//     while(*s)
//     {
//         if(*s == '(' || *s == '{' || *s == '[')
//         {
//             STPush(&st, *s);
//         }
//         else
//         {
//             if(STEmpty(&st))
//             {
//                 STDestroy(&st);
//                 return false;
//             }

//             STDataType x = STTop(&st);

//             if((x == '(' && *s != ')') 
//             || (x == '{' && *s != '}') 
//             || (x == '[' && *s != ']'))
//             {
//                 STDestroy(&st);
//                 return false;
//             }
            
//             STPop(&st);
//         }
//         s++;
//     }

//     if(STEmpty(&st))
//     {
//         STDestroy(&st);
//         return true;
//     }

//     STDestroy(&st);
//     return false;
// }

//一刷：栈思想，左括号则入栈，右括号则出栈匹配（出栈前判空），匹配错误false，最后栈不为空也是false，return前要destroy！
// typedef char STDataType;
// typedef struct Stack
// {
//     STDataType* a; //指向动态数组的指针
//     int top; //动态数组中最后一个有效元素的下一位
//     int capacity; //动态数组的总容量
// }ST;

// void STInit(ST* pst)
// {
//     assert(pst);
//     pst->a = NULL;
//     pst->top = 0; //指向数组末尾有效元素的下一位
//     pst->capacity = 0;
// }

// //销毁
// void STDestroy(ST* pst)
// {
//     assert(pst);
//     free(pst->a);
//     pst->a = NULL;
//     pst->top = pst->capacity = 0;
// }


// //入栈
// void STPush(ST* pst, STDataType x)
// {
//     assert(pst);

//     //需要扩容的情况
//     if(pst->top == pst->capacity)
//     {
//         int newcapacity = pst->capacity == 0 ? 4 : 2*pst->capacity;
//         STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
//         if(tmp == NULL)
//         {
//             perror("realloc fail");
//             exit(1);
//         }
//         pst->a = tmp;
//         pst->capacity = newcapacity;
//     }
    
//     pst->a[pst->top] = x;
//     pst->top++; 
// }

// //出栈
// void STPop(ST* pst)
// {
//     assert(pst && pst->top != 0);
//     pst->top--;
// }

// //查询栈顶元素
// STDataType STTop(ST* pst)
// {
//     assert(pst && pst->top>0);
//     return pst->a[pst->top-1];
// }

// //判空
// bool STEmpty(ST* pst)
// {
//     assert(pst);
//     return pst->top == 0;
// }

// //查询数据个数
// int STSize(ST* pst)
// {
//     assert(pst);
//     return pst->top;
// }

// bool isValid(char* s)
// {
//     ST st;
//     STInit(&st);

//     while(*s)
//     {
//         if(*s == '(' || *s == '{' || *s == '[')
//         {
//             STPush(&st, *s);
//         }
//         else
//         {
//             if(STEmpty(&st))
//             {
//                 STDestroy(&st);
//                 return false;
//             }

//             char x = STTop(&st);
//             STPop(&st);

//             if((*s == ')' && x != '(')
//             || (*s == '}' && x != '{')
//             || (*s == ']' && x != '['))
//             {
//                 STDestroy(&st);
//                 return false;
//             }
//         }

//         ++s;
//     }

//     bool ret = STEmpty(&st); //存储，以便于释放栈空间
//     STDestroy(&st);

//     return ret;
// }
