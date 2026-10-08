class Solution {
public:
    //右下
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int ret = 1;
    int M, N;

    bool check(int x, int y, int cnt)
    {
        int sum = 0;
        while(x)
        {
            sum += x % 10;
            x /= 10;
        }

        while(y)
        {
            sum += y % 10;
            y /= 10;
        }

        if(sum <= cnt) return true;
        return false;
    }

    void dfs(vector<vector<int>>& grid, int m, int n, int cnt) //传入坐标
    {
        for(int i=0; i<2; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && check(x, y, cnt) && grid[x][y] != 1)
            {
                grid[x][y] = 1;
                ++ret;
                dfs(grid, x, y, cnt);
            }
        }
    }

    int wardrobeFinishing(int m, int n, int cnt)
    {
        M = m, N = n;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        dfs(grid, 0, 0, cnt);
        return ret;
    }
};

//一刷：floodfill递归回溯算法，用数组辅助走，注意初始化M和N