#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> arr(n);

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int t; cin >> t;
    while(t--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int pos; cin >> pos;
            cout << arr[pos - 1] << endl;
        }
        else if(op == 2)
        {
            long long num; cin >> num;
            int flag = 1;
            for(int i=0; i<n; i++)
            {
                if(arr[i] == num)
                {
                    flag = 0;
                    cout << i + 1 << endl;
                    break;
                }
            }

            if(flag == 1) cout << 0 << endl;
        }
    }
    return 0;
}