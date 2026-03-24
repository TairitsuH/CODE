#include<iostream>
using namespace std;

int main()
{
    int T,n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        double arr[n] = {0};
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        double ave = sum / n;
        
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > ave) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}