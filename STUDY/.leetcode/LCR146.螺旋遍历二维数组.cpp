#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array)
    {
        vector<int> ret;
        if(array.empty()) return ret;
        int m = array.size();
        int n = array[0].size();


        //确定上下左右边界
        int left = 0, right = n-1, up = 0, down = m-1; //right和down记得减1！
        while(1)
        {
            //右
            for(int i=left; i<=right; i++) ret.push_back(array[up][i]);
            up++;
            if(up > down) break; //判断是否越界

            //下
            for(int i=up; i<=down; i++) ret.push_back(array[i][right]);
            right--;
            if(right < left) break;

            //左
            for(int i=right; i>=left; i--) ret.push_back(array[down][i]);
            down--;
            if(down < up) break;

            //上
            for(int i=down; i>=up; i--) ret.push_back(array[i][left]);
            left++;
            if(left > right) break;
        }
        return ret;
    }
};

//一刷：遗漏了数组为空的情况TvT……已老实
//复盘：本质上还是没看数据范围
