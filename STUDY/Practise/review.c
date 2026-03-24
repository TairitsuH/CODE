// //插入排序
// #include<stdio.h>
// int main()
// {
//     int N,x;
//     scanf("%d",&N);
//     int arr[11] = {0};

//     for(int i=0; i<N; i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     scanf("%d",&x);

//     if(x > arr[N-1]) arr[N] = x;
//     else
//     {
//         for(int i=N-1; i>=0; i--)
//         {
//             if(x < arr[i])
//             {
//                 arr[i+1] = arr[i];
//                 arr[i] = x;
//             }
            
//         }
//     }

//     for(int i=0; i<=N; i++)
//     {
//         printf("%d",arr[i]);
//     }
//     return 0;
// }

// //定义一个求m到n范围内斐波那契数的函数，并且定义一个输出第项斐波那契数的函数
// #include<stdio.h>

// int fib(int i)
// {
//     if(i == 1 || i == 2)
//     {
//         return 1;
//     }
//     return fib(i-1) + fib(i-2);
// }

// void print_fn(int m, int n)
// {
//     int i=1, cnt = 0;
//     while(fib(i) < m)
//     {
//         i++;
//     }
//     while(fib(i) <= n)
//     {
//         printf("%d ",fib(i));
//         cnt++;
//         i++;
//     }
//     if(cnt == 0)
//     {
//         printf("No Fibonacci number");
//     }
// }


// int main()
// {
//     int m,n;
//     scanf("%d%d",&m,&n);
//     print_fn(m, n);
//     return 0;
// }


