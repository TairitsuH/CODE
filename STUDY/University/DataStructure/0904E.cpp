#include<iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        char op; cin >> op;
        int n; cin >> n;
        if(op == 'I')
        {
            int* arr = new int[n];
            int ave = 0;
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
                ave += arr[i];
            }

            cout << ave / n << endl;
        }
        else if(op == 'C')
        {
            char* arr = new char[n];
            char maxc = 0;
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
                maxc = max(maxc, arr[i]);
            }

            cout << maxc << endl;
        }
        else
        {
            float* arr = new float[n];
            float minn;
            for(int i=0; i<n; i++)
            {
                cin >> arr[i];
                if(i == 0) minn = arr[i];
                minn = min(minn, arr[i]);
            }

            printf("%.1f\n", minn);
        }
    }
    return 0;
}