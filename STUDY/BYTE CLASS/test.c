// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     for(i=0; i<=12; i++)
//     {
//         arr[i] = 0;
//         printf("hello bit\n");
//     }
//     return 0;
// }
//死循环案例

// #include<stdio.h>
// int main()
// {
//     int money = 20;
//     int bo = 0;
//     int cnt = 0;
//     while(money--)
//     {
//         cnt++;
//         bo++;
//         if(bo == 2)
//         {
//             bo--;
//             cnt++;
//         }
//     }
//     printf("%d", cnt);
//     return 0;
// }


#include<stdio.h>
int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    printf("%0x %0x %0x %0x %0x %0x", a, b, c, d, e, f);
    return 0;
}