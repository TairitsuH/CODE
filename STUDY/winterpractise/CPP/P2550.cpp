#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[7];
    for(int i=0; i<7; i++)
    {
        cin >> arr[i];
    }

    int score[7] = {0};

    for(int i=0; i<n; i++)
    {
        int s = 0;
        int arr1[7];
        for(int j=0; j<7; j++)
        {
            cin >> arr1[j];
            for(int k=0; k<7; k++)
            {
                if(arr1[j] == arr[k])
                {
                    s++;
                }
            }
        }
        int S = 7-s;
        score[S] += 1;
    }
    
for(int i=0; i<7; i++)
{
    cout << score[i] << " ";
}

    return 0;
}