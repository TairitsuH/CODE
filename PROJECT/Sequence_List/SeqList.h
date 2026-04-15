//动态顺序表
#define INIT_CAPACITY 4
typedef int SLDataType; //方便后续按需替换

typedef struct SeqList
{
    SLDataType* arr; //指向动态数组的指针
    int size; //有效元素个数
    int capacity; //总容量
}SL;

void SLInit(SL* ps); //初始化
void SLDestroy(SL* ps); //销毁

void SLCheckCapacity(SL* ps); //检查内存，扩容
void SLPushFront(SL* ps, SLDataType x); //头插
void SLPushBack(SL* ps, SLDataType x); //尾插

void SLPopFront(SL* ps); //头删
void SLPopBack(SL* ps); //尾删

void SLInsert(SL* ps, int pos, SLDataType x); //指定插入
void SLErase(SL* ps, int pos); //指定删除

void SLFind(SL* ps, SLDataType x); //查找
void SLPrint(SL* ps); //打印



