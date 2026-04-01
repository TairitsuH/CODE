/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 轮转数组
 */

// @lc code=start
void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;

    int left = 0;
    int right = numsSize-1-k;
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }

    left = numsSize - k;
    right = numsSize - 1;
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }

    left = 0;
    right = numsSize - 1;
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }

}
// @lc code=end

//一刷：思路一：每次存储数组末尾的元素，整体向后挪动1步，循环k%size次（会超时
    //思路二：三次逆置，逆置前半，逆置后半，整个再次逆置
    //思路三：新建数组，空间换时间
