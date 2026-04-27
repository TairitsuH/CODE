//法1
#include<iostream>
using namespace std;

char x;

int main()
{
    int cnt = 0;
    while((x = getchar()) != '\n')
    {
        if(x >= '0' && x <= '9')
        {
            cnt++;
        }
    }

    cout << cnt;
    

    return 0;
}

//法2
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int cnt = 0;
    string x;
    getline(cin, x);

    for(int i=0; i<x.size(); i++)
    {
        if(isdigit(x[i]))
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}