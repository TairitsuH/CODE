/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 轮转数组
 */
 
// @lc code=start
void rotate(int* nums, int numsSize, int k)
{
    int n = numsSize;
    k %= n;
    int arr[n];
    //memcpy(dest, src, sizeof);
    memcpy(arr+k, nums, sizeof(int)*(n-k));
    memcpy(arr, nums+n-k, sizeof(int)*k);
    memcpy(nums, arr, sizeof(int)*n);
    //传入的是地址，复制的边界判断还需巩固！
}
// @lc code=end

//二刷：存在重复代码应该设计函数封装（力扣是支持函数封装的），复盘了一下三次逆置，尝试了空间换时间（strcpy）
// void reverse(int nums[], int left, int right)
// {
//     while(left < right)
//     {
//         int mid = nums[left];
//         nums[left] = nums[right];
//         nums[right] = mid;
//         left++;
//         right--;
//     }
// }
// void rotate(int* nums, int numsSize, int k) 
// {
//     int n = numsSize;
//     k %= n;

//     reverse(nums, 0, n-1-k);
//     reverse(nums, n-k, n-1);
//     reverse(nums, 0, n-1);
// }
//一刷：思路一：每次存储数组末尾的元素，整体向后挪动1步，循环k%size次（会超时
    //思路二：三次逆置，逆置前半，逆置后半，整个再次逆置
    //思路三：新建数组，空间换时间
//     void rotate(int* nums, int numsSize, int k)
// {
//     k %= numsSize;

//     int left = 0;
//     int right = numsSize-1-k;
//     while(left < right)
//     {
//         int tmp = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tmp;
//         left++;
//         right--;
//     }

//     left = numsSize - k;
//     right = numsSize - 1;
//     while(left < right)
//     {
//         int tmp = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tmp;
//         left++;
//         right--;
//     }

//     left = 0;
//     right = numsSize - 1;
//     while(left < right)
//     {
//         int tmp = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tmp;
//         left++;
//         right--;
//     }

// }
