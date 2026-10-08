#include<iostream>
#include<vector>
using namespace std;

string matched_Prefix_Postfix(string str)
{
    int n = str.size();
    if(n <= 1) return "";
    vector<int> fail(n, 0);
    int k = 0;
    for(int i = 1; i < n; i++)
    {
        while(k > 0 && str[i] != str[k]) k = fail[k - 1];
        if(str[i] == str[k]) k++;
        fail[i] = k;
    }
    return fail[n - 1] == 0 ? "" : str.substr(0, fail[n - 1]);
}


int main()
{
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        string ret = matched_Prefix_Postfix(s);
        if(ret != "") cout << ret << endl;
        else cout << "empty" << endl;
    }
    return 0;
}