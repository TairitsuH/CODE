#include<iostream>
#include<vector>
using namespace std;

void step1(int N, vector<int> arr[])
{
    for(int j=0; j<N-1; j++)
    {
        for(int k=j+1; k<N; k++)
        {
            if(arr[j] == arr[k])
            {
                
            }
        }
    }
}

void bubble(int N, vector<int> arr[])
{

}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    step1(N, &arr);
    bubble(N, &arr);

    for(int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}