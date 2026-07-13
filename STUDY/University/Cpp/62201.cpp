#include<iostream>
#include<vector>
using namespace std;

template<class T>
void Find_Pos(vector<T> arr, T key)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == key)
        {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << '0' << endl;
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
            
            int key; cin >> key;
            Find_Pos(arr, key);
        }
        else if(op == 'D')
        {
            vector<double> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            double key; cin >> key;
            Find_Pos(arr, key);
        }
        else if(op == 'C')
        {
            vector<char> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            char key; cin >> key;
            Find_Pos(arr, key);
        }
        else
        {
            vector<string> arr(n);
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
            }

            string key; cin >> key;
            Find_Pos(arr, key);
        }

    }
    return 0;
}