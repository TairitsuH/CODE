class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers)
    {
        int minx = numbers[0];
        int maxx = numbers[0];

        for(auto num : numbers)
        {
            if(num < minx)
            {
                minx = num;
            }
            if(num > maxx)
            {
                maxx = num;
            }
        }

        int len = maxx - minx + 1;
        int* arr = new int[len]{};

        for(int i=0; i<numbers.size(); i++)
        {
            arr[numbers[i] - minx]++;
        }

        int j = 0;
        for(j=0; j<len; j++)
        {
            if(arr[j] > numbers.size()/2)
            {
                break;
            }
        }

        return j + minx;
    }
};

//一刷：用计数的方式统计数字出现的次数，题解思路是排序后返回中间的数，妙啊！