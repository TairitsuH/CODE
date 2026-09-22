#include<iostream>
#include<map>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        map<int, int> rbmap;
        int n; cin >> n; 
        for(int i=0; i<n; ++i)
        {
            int c, e; cin >> c >> e;
            rbmap[e] += c;
            if(rbmap[e] == 0) rbmap.erase(e);
        }

        int m; cin >> m;
        for(int i=0; i<m; ++i)
        {
            int c, e; cin >> c >> e;
            rbmap[e] += c;
            if(rbmap[e] == 0) rbmap.erase(e);
        }

        cout << rbmap.size() << endl;
        for(auto it : rbmap)
                cout << it.second << " " << it.first << endl;

    }
    return 0;
}


#include<stdio.h>
#include<memory.h>

#define NUM 1000010
long long poly[NUM];
long long recE[NUM];
long long recC[NUM];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        memset(poly, 0, sizeof(poly));

        int n; scanf("%d", &n);
        int i = 0;
        for(i=0; i<n; ++i)
        {
            int c, e; scanf("%d%d", &c, &e);
            poly[e] += c;
        }

        int m; scanf("%d", &m);
        for(i=0; i<m; ++i)
        {
            int c, e; scanf("%d%d", &c, &e);
            poly[e] += c;
        }

        int cnt = 0; //项数
        int pos = 0;
        for(i=0; i<NUM; ++i)
        {
            if(poly[i] != 0)
            {
                ++cnt;
                recC[pos] = poly[i];
                recE[pos] = i;
                ++pos;
            }
        }
        
        printf("%d\n", cnt);

        for(i=0; i<cnt; ++i)
        {
            printf("%d %d\n", recC[i], recE[i]);
        }
    }

    return 0;
}