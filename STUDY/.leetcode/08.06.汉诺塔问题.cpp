class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
    {
        int n = A.size();
        dfs(A, B, C, n);
    }

    void dfs(vector<int>& x, vector<int>& y, vector<int>& z, int n)
    {
        if(n == 1)
        {
            z.push_back(x.back());
            x.pop_back();
            return;
        }
        
        dfs(x, z, y, n - 1);
        z.push_back(x.back());
        x.pop_back();
        dfs(y, x, z, n - 1);
    }
};

//二刷：递归实现，一定要按步骤走，不要急于求成，从宏观上看待递归
//一刷：递归实现，顺序为函数头->函数体->细节（出口），需要特别留意参数顺序（A借助B转移到C）
class Solution {
public:
    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if(n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        dfs(A, C, B, n-1);
        C.push_back(A.back());
        A.pop_back();
        dfs(B, A, C, n-1);
    }


    void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
    {
        int n = A.size();
        dfs(A, B, C, n);
    }
};