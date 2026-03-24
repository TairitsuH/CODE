// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     int arr1[10] = {0};
//     int arr2[5] = {1, 2, 3, 4, 5};

//     memcpy(arr1, arr2, 20);
//     //注意需要拷贝的int型数据的字节是 5 * 4 = 20

//     for(int i=0; i<10; i++)
//     {
//         printf("%d ", arr1[i]);
//     }
//     return 0;
// }

// void * my_memcpy(void * dst, const void * src, size_t sz)
// {
//     //先拷贝一份目标空间的起始地址
//     void * dst2 = dst;

//     //拷贝前确保不是空指针
//     assert(dst);
//     assert(src);

//     //由于指针为任意类型，无法直接通过解引用实现数据拷贝和指针运算，
//     //因此需要在拷贝前进行强制类型转换。而char*所能访问的字节数最小(1)，
//     //故转化为char*类型。
//     while(sz--)
//     {
//         *(char *)dst = *(char *)src;
//         dst = (char *)dst + 1;
//         src = (char *)src + 1;
//     }

//     return dst2;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     memmove(arr, arr+2, 20);
//     for(int i=0; i<10; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// void * my_memmove(void * dst, void * src, size_t sz)
// {
//     void * dst2 = dst;

//     assert(dst);
//     assert(src);

//     //从前往后:第1，3种情况
//     if(dst <= src || ((char *)src + sz) <= (char *)dst)
//     {
//         while(sz--)
//         {
//             *(char *)dst = *(char *)src;
//             dst = (char *)dst + 1;
//             src = (char *)src + 1;
//         }
//     }
//     //从后往前：第2种情况
//     else
//     {
//         while(sz--)
//         {
//             dst = (char *)dst + sz - 1;
//             src = (char *)src + sz - 1;
//             *(char *)dst = *(char *)src;

//             while(sz--)
//             {
//                 dst = (char *)dst - 1;
//                 src = (char *)src - 1;
//             }
//         }
//     }
//     return dst2;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr[20] = {"hello world"};
//     int sz = strlen(arr);
//     printf("%d", sz);
//     return 0;
// }

// int my_strlen(const char * str)
// {
//     assert(str);
//     int cnt = 0;

//     while(*str)
//     {
//         cnt++;
//         str++;
//     }

//     return cnt;
// }

// int my_strlen(const char * str)
// {
//     assert(str);
//     if(*str == '\0') return 0;
//     else
//     {
//         return 1 + my_strlen(str+1);
//     } 
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr1[10] = {"hello"};
//     char arr2[20] = {0};
    
//     strcpy(arr2, arr1);

//     printf("%s", arr2);
//     return 0;
// }

// char * my_strcpy(char * dst, const char * src)
// {
//     assert(dst);
//     assert(src);

//     char * dst2 = dst;
//     while(*src != '\0')
//     {
//         *dst = *src;
//         dst++;
//         src++;
//     }
//     //记得在dst末尾补充src所指向的'\0'
//     *dst = *src;

//     return dst2;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr1[15] = {"hello worldxx"};
//     char arr2[20] = {0};
//     strncpy(arr2, arr1, 11);
//     printf("%s", arr2); 
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr1[15] = {"hello world"};
//     char arr2[30] = {"haha "};
//     strcat(arr2, arr1);
//     printf("%s", arr2);
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr1[15] = {"hello world"};
//     char arr2[30] = {"haha "};
//     strncat(arr2, arr1, 5);
//     printf("%s", arr2);
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char str1[15] = {"hello C"};
//     char str2[15] = {"hello world"};
//     int ret = strcmp(str1, str2);
//     printf("%d", ret);
//     //由于C的ASCII码值小于w，所以打印结果为负整数
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char str1[15] = {"hello C"};
//     char str2[15] = {"hello world"};
//     int ret = strncmp(str1, str2, 5);
//     printf("%d", ret);
//     //由于两个字符串的前5个字符相同，故返回0
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char str2[15] = {"hello"};
//     char str1[15] = {"hello world"};
//     char * ret = strstr(str1, str2);
    
//     if(ret != NULL)
//     {
//         printf("%s\n", ret);
//     }
//     else
//     {
//         printf("您所查找的字符串不存在。\n");
//     }


//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// #include<errno.h>
// int main()
// {
//     FILE * pfile = NULL;
//     pfile = fopen("unexist.ent","r")
//     //以只读模式打开文件unexist.ent
//     if(pfile == NULL)
//     {
//         printf("错误信息是：%s\n", strerror(errno));
//         //或者替换为：
//         //perror("错误信息是");
//         return 1;
//     }


//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char a[15] = "Hello World";
//     memset(a, '*', 5);
//     printf("%s", a);
//     return 0;
// }

#include<stdio.h>
#include<string.h>
int main()
{
    char a[15] = {"hello world"};
    char b[15] = {"hello C"};
    int ret1 = memcmp(a, b, 5);
    int ret2 = memcmp(a, b, 7);
    printf("%d\n%d\n", ret1, ret2);
    return 0;
}