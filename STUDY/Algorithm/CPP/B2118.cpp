#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char s1[30] = {0};
    char s2[30] = {0};
    cin >> s1 >> s2;
    if(strstr(s2, s1) != NULL)
    {
        cout << s1 << " is substring of " << s2 << endl;
    }
    else if(strstr(s1, s2) != NULL)
    {
        cout << s2 << " is substring of " << s1 << endl;
    }
    else
    {
        cout << "No substring";
    }
    return 0;
}