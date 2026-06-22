#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

template<class T>
void Find_Winner(vector<T>& arr)
{
    unordered_map<T, int> hash;
    for(auto x : arr)
    {
        hash[x]++;
    }

    int max_times = 0;
    T max_op;
    for(auto x : hash)
    {
        if(x.second > max_times)
        {
            max_times = x.second;
            max_op = x.first;
        }
    }
    
    cout << max_op << ' ' << max_times << endl;
}


int main()
{
    int t; cin >> t;
    while(t--)
    {
        char op; cin >> op;
        int n; cin >> n;

        if(op == 'I')
        {
            vector<int> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            Find_Winner(arr);
        }
        else if(op == 'C')
        {
            vector<char> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            Find_Winner(arr);

        }
        else
        {
            vector<string> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            Find_Winner(arr);

        }
    }
    return 0;
}