// #include<stdio.h>

// void my_swap(int a, int b)
// {
//     int mid = a;
//     a = b;
//     b = mid;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     my_swap(a, b);
//     printf("a = %d\nb = %d", a, b);
//     return 0;
// }

#include<stdio.h>

void my_swap(int* x, int* y)
{
    int mid = 0;
    mid = *x;
    *x = *y;
    *y = mid;
}

int main()
{
    int a = 10;
    int b = 20;
    my_swap(&a, &b);
    printf("a = %d\nb = %d", a, b);
    return 0;
}