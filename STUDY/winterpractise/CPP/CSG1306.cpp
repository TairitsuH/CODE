#include<iostream>
#include<cmath>
using namespace std;

const int N = 1e7 + 10;
int e1[N], ne1[N], pre1[N], e2[N], ne2[N], pre2[N], h, id;

int main()
{
    int n,m; cin >> n >> m;

    int H = h;
    for(int i=1; i<=n; i++)
    {
        id++;

        int x = (10000 * sin(n + i));
        int y = (10000 * sin(m + i));

        e1[id] = x;
        ne1[H] = id;
        pre2[id] = H;

        e1[id] = x;
        ne1[H] = id;
        pre2[id] = H;

        H++;
    }

    int M = m;
    int id1 = id;
    int id2 = id;
    while(M--)
    {
        int flag, ix, iy; cin >> flag >> ix >> iy;

        if(flag == 0)
        {
            int X = e1[id1];
            ne1[pre1[ix]] = ne1[ix];
            pre1[ne1[ix]] = pre1[ix]; //移除

            id2++;
            e2[id2] = X;
            pre2[id2] = pre2[iy];
            ne2[id2] = ne2[pre2[iy]];
            ne2[pre2[iy]] = id2;
            pre2[iy] = id2; //插入

        }
        else
        {
            int X = e2[id2];
            ne2[pre2[iy]] = ne2[iy];
            pre2[ne2[iy]] = pre2[iy]; //移除

            id1++;
            e1[id1] = X;
            pre1[id1] = pre1[ix];
            ne1[id1] = ne1[pre1[ix]];
            ne1[pre1[ix]] = id1;
            pre1[ix] = id1; //插入
        }

        int start, end; cin >> start >> end;
        for(int j=start; j<end; j++)
        {
            cout << e1[j] << endl;
        }

    }
    return 0;
}