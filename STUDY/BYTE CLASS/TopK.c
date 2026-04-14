#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//最大建小堆，最小建大堆（此处建小堆）
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child + 1] < a[child])
        {
            child += 1;
        }

        if(a[parent] > a[child])
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

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
    //开辟空间
    int* tmp  = (int*)malloc(sizeof(int) * k);
    if(!tmp)
    {
        perror("malloc fail");
        exit(1);
    }

    //打开文件
    const char* file = "data.txt";
    FILE* fout = fopen(file, "r");
    if(!fout)
    {
        perror("fopen fail");
        exit(1);
    }

    //将前k个数放入空间中，建堆
    for(int i=0; i<k; i++)
    {
        fscanf(fout, "%d", &tmp[i]);
    }
    for(int i=(k-1-1)/2; i>=0; i--)
    {
        AdjustDown(tmp, k, i);
    }

    //剩下的数逐个和堆顶元素比较
    int x = 0;
    while(fscanf(fout, "%d", &x) > 0)
    {
        if(x > tmp[0])
        {
            tmp[0] = x;
            AdjustDown(tmp, k, 0);
        }
    }

    //对前k个数进行排序
    int end = k - 1;
    while(end > 0)
    {
        Swap(&tmp[end], &tmp[0]);
        AdjustDown(tmp, end, 0);
        end--;
    }

    //打印
    for(int i=0; i<k; i++)
    {
        printf("%d ", tmp[i]);
    }
    printf("\n");

    //释放空间
    free(tmp);
    tmp = NULL;
}

int main()
{
    CreateNDate();
    int k;
    printf("请输入你要打印的前k个数>");
    scanf("%d", &k);
    PrintTopK(k);

    return 0;
}