/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start
char* reverseStr(char* s, int k)
{
    int len = strlen(s);
    int i;
    for(i=0; i<len; i+=2*k)
    {
        // k影响end，这样算结束时k的值：
        //i + k - 1 = len - 1, k = len - i;
        k = i + k >= len ? len - i : k;
        int begin = i;
        int end = i + k - 1;
        while(begin < end)
        {
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;

            begin++;
            end--;
        }
    }

    return s;
}
// @lc code=end
//二刷：
// char 类型因为有 \0 作为结束标志，可以用 strlen 这个"专用工具"辅助算出长度；
// 其他类型没有这种工具，平时只能用 sizeof 算，但一旦传到函数内部（退化后）就算不了了。

//一刷：对于边界的控制还是不太熟练。题目看上去边界条件很多，但稍微理解就会发现并没有那么复杂
// char* reverseStr(char* s, int k)
// {
//     int length = strlen(s);
//     for(int i=0; i<length; i+=2*k)
//     {
//         k = i + k > length ? length - i : k;
        
//         int left = i, right = i + k - 1;
//         while(left < right)
//         {
//             char tmp = s[left];
//             s[left] = s[right];
//             s[right] = tmp;

//             left++;
//             right--;
//         }
//     }

//     return s;
// }