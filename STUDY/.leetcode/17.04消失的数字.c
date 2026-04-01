int missingNumber(int* nums, int numsSize)
{
    int ret = 0;
    for(int i=0; i<=numsSize; i++)
    {
        ret ^= i;
    }
    for(int i=0; i<numsSize; i++)
    {
        ret ^= nums[i];
    }
    return ret;
}

//二刷：异或，和自己异或为0，和0异或为自己
//一刷：全部累加再减去数组中的值（弊端：可能会超范围
// int missingNumber(int* nums, int numsSize)
// {
//     int n = numsSize;
//     int sum = n*(n+1)/2;
//     for(int i=0; i<numsSize; i++)
//     {
//         sum -= nums[i];
//     }
//     return sum;
// }
