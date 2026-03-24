#include<iostream>
#include<string>
using namespace std;

int n,sz;

void bubble_sort(string arr[], int sz)
{
    for(int i=0; i<sz-1; i++)
    {
        for(int j=0; j<sz-1-i; j++)
        {
            if(arr[j] < arr[j+1])
            {
                string mid = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = mid;
            }
        }
    }
}

int main()
{
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);
    
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}