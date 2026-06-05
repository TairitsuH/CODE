//https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
//【模板】前缀和
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, t; cin >> n >> t;
    vector<long long> v(n + 1, 0); //防越界

    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        v[i] = v[i - 1] + x;
    }

    while(t--)
    {
        int l, r; cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }

    return 0;
}
