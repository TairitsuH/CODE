// // 打印1-100之间3的倍数
// #include<stdio.h>
// int main()
// {
//   int i = 0;
//   for(i=3; i<=100; i+=3)
//   {
//     printf("%d ",i);
//   }
//   return 0;
// }


// // 将三个整数数按从大到小输出
// #include<stdio.h>
// int main()
// {
//   int a,b,c;
//   scanf("%d%d%d",&a,&b,&c);
//   if(a>b)
//   {
//     if(a>c)
//     {
//       printf("%d %d %d",a,b,c);
//     }
//     else
//     {
//       printf("%d %d %d",c,a,b);
//     }
//   }
//   else
//   {
//     if(a>c)
//     {
//       printf("%d %d %d",b,a,c);
//     }
//     else if(b<c)
//     {
//       printf("%d %d %d",c,b,a);
//     }
//     else
//     {
//       printf("%d %d %d",b,c,a);
//     }
//   }
//   return 0;
// }


// //判断三角形类型
// #include<stdio.h>
// int main()
// {
//   int a,b,c;
//   while(scanf("%d%d%d",&a,&b,&c)!=EOF)
//   {
//     if((a+b>c)&&(a+c>b)&&(b+c>a))
//     {
//       if(a==b && b==c)
//       {
//        printf("Equilateral triangle!\n");
//       }
//       else if(((a==b)&&(b!=c))||((c==b)&&(c!=a))||((a==c)&&(b!=a)))
//       {
//        printf("Isosceles triangle!\n");
//       }
//       else
//       {
//         printf("Ordinary triangle!\n");
//       }
//     }
//     else
//     {
//       printf("Not a triangle!\n");
//     }
//   }
//   return 0;
// }

// //求10个整数中的最大值
// #include<stdio.h>
// int main()
// {
//   int t,i,T;
//   scanf("%d",&t);
//   for(i = 0; i<9; i++)
//   {
//     scanf("%d",&T);
//     if(T>t)
//     {
//       t=T;
//     }
//   }
//   printf("%d",t);
//   return 0;
// }

// // 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
// #include<stdio.h>
// int main()
// {
//   int i;
//   float N;
//   double sum = 0.0;
//   int n = 1;
//   int sign = 1;
//   for(i=0; i<100; i++)
//   {
//     N = 1.0/n*sign;
//     sum+=N;
//     n+=1;
//     sign *= -1;//或者用sign=-sign
//   }
//   printf("%f\n",sum);
//   return 0;
// }


// // 编写程序数一下 1到 100 所有整数中出现多少个数字9
// #include<stdio.h>
// int main()
// {
//   int i = 0;
//   int n = 1;
//   int N = 0;
//   for(i = 0; i<100; i++)
//   {
//     if( n%10==9 || n/10==9 )
//     {
//       N+=1;
//     }
//     n+=1;
//   }
//   printf("%d\n",N);
//   return 0;
// }


// // 打印1000年到2000年之间的闰年
// #include<stdio.h>
// int main()
// {
//   int year;
//   for(year=1000; year<=2000; year++)
//   {
//     if((year%4==0&&year%100!=0)||(year%400==0))
//     {
//       printf("%d ",year);
//     }
//     year+=1;
//   }
//   return 0;
// }


// // 给定两个数，并求这两个数的最大公约数
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//   int a,b,min,max;
//   int i;
//   int num = 0;
//   while(scanf("%d%d",&a,&b)!=EOF)
//   {
//     if(a<b)
//     {
//       min=a;
//       max=b;
//     }
//     else
//     {
//       min=b;
//       max=a;
//     }
//     for(i=1; i<=min; i++)
//     {
//       if((min%i==0)&&(max%i==0))
//       {
//         num = i;
//       }
//     }
//     printf("%d\n",num);
//   }
//   return 0;
// }

// // 找出100~200之间的所有质数，并打印出来
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//   int i,j,flag;
//   for(i=100; i<=200; i++)
//   {
//     flag = 1;
//     for(j=2; j<=sqrt(i); j++)
//     {
//       if(i%j==0)
//       {
//         flag = 0;
//         break;
//       }
//     }
//     if(flag==1)
//     {
//       printf("%d ",i);
//     }
//   }
//   return 0;
// }