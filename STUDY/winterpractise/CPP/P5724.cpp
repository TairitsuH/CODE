#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,i;
    cin >> n;
    int max1 = 0;
    int min1 = 100;
    for(i=0; i<n; i++)
    {
        int N;
        cin >> N;
        max1 = max(max1, N);
        min1 = min(min1, N);
    }
    cout << max1 - min1 << endl;
    return 0;
}