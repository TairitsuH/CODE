#include<iostream>
using namespace std;

const int N = 1e4;
int num[N];
string str[N];
int n;

void bubble(int num[], string str[], int sz)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<sz-1-i; j++)
        {
            if(num[j] > num[j+1]) 
            {
                swap(num[j], num[j+1]);
                swap(str[j], str[j+1]);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
        getchar();
        cin >> str[i];
    }

    bubble(num, str, n);

    for(int i=0; i<n; i++)
    {
        cout << str[i] << endl;
    }

    return 0;
}