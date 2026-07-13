#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    char x;
    string X;
    cin >> x >> X;
    int n = X.size();
    vector<char> arr(n);
    
    int i;
    for(i=0; i<n; i++)
    {
        arr[i] = X[i];
    }

    int flag = 0;
    for(int j=n-1; j>=0; j--)
    {
        if(arr[j] == x)
        {
            cout << "index = " << j << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) cout << "Not Found";


    return 0;
}