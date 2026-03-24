#include<iostream>
using namespace std;

string x;

int main()
{  
    cin >> x;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]>='a' && x[i]<='z') cout << (char)(x[i]-'a'+'A');
        else if(x[i]>='A' && x[i]<='Z') cout << (char)(x[i]-'A'+'a');
        else cout << x[i];
    }

    return 0;
}