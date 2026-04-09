// #include<stdio.h>
// int main()
// {
//     int a = 10; 
//     int* pa = &a; //a的地址
//     int** ppa = &pa; //pa的地址

//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a = 10; 
//     int* pa = &a; //a的地址
//     int** ppa = &pa; //pa的地址
//     printf("%d\n", a);

//     *pa = 20;
//     printf("%d\n", *pa);

//     **ppa = 30;
//     printf("%d\n", **ppa);

//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a[3] = {1, 2, 3};
//     int b[3] = {4, 5, 6};
//     int c[3] = {7, 8, 9};

//     int * p[3] = {a, b, c};

//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j<3; j++)
//         {
//             printf("%d ", p[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include<stdio.h>

// void test(int (*p)[5], int r, int c)
// {
//     for(int i=0; i<4; i++)
//     {
//         for(int j=0; j<c; j++)
//         {
//             printf("%d ", *((*p) + i) + j);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int arr[4][5] = {{1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7}, {4,5,6,7,8}};

//     test(arr, 4, 5);

//     return 0;
// }

#include<stdio.h>

int Add(int x, int y)
{
    return x + y;
}

int main()
{
    int a = 1;
    int b = 2;
    int (*p1) (int x, int y) = Add;
    int (*p2) (int, int) = Add; //省略形参名也是合法的

    int ret1 = (*p1)(a, b);
    int ret2 = (*p2)(a, b);

    printf("%d %d", ret1, ret2);

    return 0;
}