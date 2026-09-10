#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m; cin >> m;
    vector<int> arr;
    while(m--)
    {
        char op; cin >> op;
        if(op == 'I')
        {
            int x; cin >> x;
            arr.push_back(x);
        }
        else if(op == 'D')
        {
            int x; cin >> x;
            for(int i=0; i<arr.size(); i++)
            {
                if(arr[i] == x)
                {
                    arr.erase(arr.begin() + i);
                    break;
                }
            }
        }
        else if(op == 'C')
        {
            cout << arr.size() << endl;
        }
        else
        {
            long long sum = 0;
            for(auto x : arr)
            {
                sum += x;
            }
            cout << sum << endl;
        }

    }
    return 0;
}