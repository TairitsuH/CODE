#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int R, C, q; cin >> R >> C >> q;
    vector<vector<int>> a(R, vector<int>(C, 0));
    while(q--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int r, c, x; cin >> r >> c >> x;
            int flag = 1;
            for(int i=0; i<R; i++)
            {
                for(int j=0; j<C; j++)
                {
                    if(a[i][j] == x)
                    {
                        flag = 0;
                        cout << "failed" << endl;
                        break;
                    }
                }
                    if(flag == 0) break;

            }
            if(flag == 0) continue;
            
            if(a[r - 1][c - 1] == 0)
            {
                a[r - 1][c - 1] = x;
                cout << "ok" << endl;
            }
            else
            {
                cout << "failed" << endl;
            }

        }
        else if(op == 2)
        {
            int r, c; cin >> r >> c;
            if(a[r - 1][c - 1] != 0)
            {
                cout << a[r - 1][c - 1] << endl;
                a[r - 1][c - 1] = 0;
            }
            else
            {
                cout << "empty" << endl;
            }

        }
        else if(op == 3)
        {        
            int r, c; cin >> r >> c;    
            if(a[r - 1][c - 1] != 0)
            {
                cout << a[r - 1][c - 1] << endl;
            }
            else
            {
                cout << "empty" << endl;
            }
        }
        else if(op == 4)
        {
            int x; cin >> x;
            int flag = 0;

            for(int i=0; i<R; i++)
            {
                for(int j=0; j<C; j++)
                {
                    if(a[i][j] == x)
                    {
                        flag = 1;
                        cout << i + 1 << " " << j + 1 << endl;
                        break;
                    }
                }
                    if(flag == 1) break;

            }
            if(flag == 0) cout << "none" << endl;
        }
        else if(op == 5)
        {
            int r; cin >> r;
            int cnt = 0;
            for(int i=0; i<C; i++)
            {
                if(a[r - 1][i] == 0)
                {
                    ++cnt;
                }
            }
            cout << cnt << endl;
        }
        else
        {
            int cnt = 0;
            for(int i=0; i<R; i++)
            {
                for(int j=0; j<C; j++)
                {
                    if(a[i][j] == 0)
                    {
                        ++cnt;
                    }
                }
            }
            cout << cnt << endl;
        }
        
    }
    return 0;
}