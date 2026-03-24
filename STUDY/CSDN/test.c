// #include<stdio.h>
// int main()
// {
//     int a = 10;
//     int * pa = &a;
//     int A = * pa;
//     * pa = 0;
//     printf("%d %d",a,A);
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int * p = arr;
//     for(int i=0; i<5; i++)
//     {
//         printf("%d ", *(p+i));
//     }
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     char arr[7] = "abcde";
//     int sz = sizeof(arr) / sizeof(arr[0]);

//     char * p = arr; //p为arr数组首元素地址
//     for(int i=0; i<sz; i++)
//     {
//         if(arr[i] != '\0')
//         {
//             p++;
//         }
//     }

//     printf("%d", p-arr);
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char arr[] = "hello@.#world@@ni hao C yu.yan.";
//     const char * str = NULL; //置空避免野指针
//     char cpy[30] = {0};
//     strcpy(cpy, arr); //将str中的字符串拷贝到cpy中，方便后续对cpy进行切割
//     const char * sep = "@#. "; //确定切割字符

//     for(str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//     {
//         printf("%s\n",str);
//     }
    
//     return 0;
// }
