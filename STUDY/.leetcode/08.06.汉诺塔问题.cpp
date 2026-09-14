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

//一刷：递归实现，顺序为函数头->函数体->细节（出口），需要特别留意参数顺序（A借助B转移到C）