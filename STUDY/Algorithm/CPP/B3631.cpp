#include<iostream>
#include<vector>
using namespace std;

vector<int> a(1,1);
int cnt = 1;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int x,y,i; cin >> x >> y;
            for(i=0; i<cnt; i++)
            {
                if(a[i] == x) break;
            }
            cnt++;
            a.insert(a.begin()+i+1, y);
        }

        else if(op == 2)
        {
            int x,i; cin >> x;
            for(i=0; i<cnt; i++)
            {
                if(a[i] == x) break;
            }
            if(i == cnt-1)
            {
                cout << "0" << endl;
                continue;
            }
            else
            {
                cout << a[i+1] << endl;
            }
        }
        else
        {
            int x,i; cin >> x;
            for(i=0; i<cnt; i++)
            {
                if(a[i] == x) break;
            }
            a.erase(a.begin()+i+1);
            cnt--;
        }
    }
    return 0;
}

