#include<iostream>
#include<cstring>
using namespace std;

int n,m;
string a,b;
int la;

int main()
{
    cin >> n >> m;
    cin >> a >> b;
    la = a.size();
    for(int i=0; i<m; i++) cout<< b[i];
    for(int i=n; i<la; i++) cout<< a[i];
    return 0;
}