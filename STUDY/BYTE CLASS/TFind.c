#include<stdio.h>

int bin_search(int arr[], int left, int right, int key)
{
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(arr[mid] <= key) left = mid;
        else right = mid - 1;
    }
    if(arr[left] == key) return left;
    return -1;

}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    for(int key=0; key<=15; key++)
    {
        int left = 0;
        int right = sizeof(arr) / sizeof(arr[0]) - 1;

        int a = bin_search(arr, left, right, key);
        if(a >= 0) printf("找到了！下标是%d\n", a);
        else printf("该数不存在！\n");
    }

    return 0;
}