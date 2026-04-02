/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

typedef char STDataType;
typedef struct Stack
{
    STDataType* a; //指向动态数组的指针
    int top; //动态数组中最后一个有效元素的下一位
    int capacity; //动态数组的总容量
}ST;

void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0; //指向数组末尾有效元素的下一位
    pst->capacity = 0;
}

//销毁
void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = pst->capacity = 0;
}


//入栈
void STPush(ST* pst, STDataType x)
{
    assert(pst);

    //需要扩容的情况
    if(pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : 2*pst->capacity;
        STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
        if(tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
    }
    
    pst->a[pst->top] = x;
    pst->top++; 
}

//出栈
void STPop(ST* pst)
{
    assert(pst && pst->top != 0);
    pst->top--;
}

//查询栈顶元素
STDataType STTop(ST* pst)
{
    assert(pst && pst->top>0);
    return pst->a[pst->top-1];
}

//判空
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}

//查询数据个数
int STSize(ST* pst)
{
    assert(pst);
    return pst->top;
}

bool isValid(char* s)
{
    ST st;
    STInit(&st);

    while(*s)
    {
        if(*s == '(' || *s == '{' || *s == '[')
        {
            STPush(&st, *s);
        }
        else
        {
            if(STEmpty(&st))
            {
                STDestroy(&st);
                return false;
            }

            char x = STTop(&st);
            STPop(&st);

            if((*s == ')' && x != '(')
            || (*s == '}' && x != '{')
            || (*s == ']' && x != '['))
            {
                STDestroy(&st);
                return false;
            }
        }

        ++s;
    }

    bool ret = STEmpty(&st); //存储，以便于释放栈空间
    STDestroy(&st);

    return ret;
}
// @lc code=end

//一刷：栈思想，左括号则入栈，右括号则出栈匹配（出栈前判空），匹配错误false，最后栈不为空也是false

