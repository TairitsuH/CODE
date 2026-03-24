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

#include<stdio.h>
int main()
{
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int c[3] = {7, 8, 9};

    int * p[3] = {a, b, c};

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}