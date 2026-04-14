/*
 * @lc app=leetcode.cn id=344 lang=c
 *
 * [344] 反转字符串
 */

// @lc code=start
void reverseString(char* s, int sSize)
{
    char* left = &s[0];
    char* right = &s[sSize - 1];

    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }
}
// @lc code=end
//一刷：双指针从两端向中间走，每次都交换。和整型数组一样，只不过类型变了。
//看了下题解，确实把left和right赋值为下标可读性会更高，做法也更常见。
//传指针就可以直接对数组进行修改了，没必要用指针
