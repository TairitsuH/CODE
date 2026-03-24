#include<iostream>
using namespace std;

struct S
{
    char a[30];
    char b[30];
    char c[5];
    char d[5];
    char e[10];
    char f[30];
    char g[20];
    char h[20];

}s1;

int main()
{
    int n; cin >> n;
    while(n--)
    {
        cin >> s1.a >> s1.b >> s1.c >> s1.d;
        cin >> s1.e >> s1.f >> s1.g >> s1.h;

        for(int i=4; i<12; i++)
        {
            s1.f[i] = '*';
        }

        cout << "Name: " << s1.a << endl;
        cout << "Terminal: " << s1.b << " ";
        cout << "operator: " << s1.c << endl;
        cout << "Card Issuers: " << s1.d << " ";
        cout << "Validity: " << s1.e << endl;
        cout << "CardNumber: " << s1.f << endl;
        cout << "Traded: " << s1.g << endl;
        cout << "Costs: $" << s1.h << endl;
        cout << endl;
    }
    return 0;
}