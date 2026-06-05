#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

struct Compare
{
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const
    {
        if(p1.second == p2.second)
        {
            return p1.first < p2.first;
        }

        return p1.second > p2.second;
    }
};

int main()
{
    string str;
    map<string, int> hash;

    while(getline(cin, str))
    {
        string s = "";
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] != ' ' && str[i] != '.')
            {
                s += tolower(str[i]);
            }
            else
            {
                hash[s]++;
                s = "";
            }
        }
    }

    vector<pair<string, int>> v(hash.begin(), hash.end());
    stable_sort(v.begin(), v.end(), Compare());

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i].first << ":" << v[i].second << endl;
    }

    return 0;
}

//一刷：处理输入花了比较长的时间。如果出现两个分隔符，可以试试先读取整一行再分割