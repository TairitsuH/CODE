#include<iostream>
#include<vector>
using namespace std;

const int N = 10;

//利用size打印vector
void print(vector<int>& a)
{
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    //创建vector
    vector<int> a1;
    vector<int> a2(N);
    vector<int> a3(N,2);
    vector<int> a4 = {1,2,3,4,5};

    //判断vector是否有空间
    if(a1.empty() == 0)
    {
        cout << "空" << endl;
    }
    else
    {
        cout << "不空" << endl;
    }

    //遍历vector(begin, end, 范围for, auto)
    for(vector<int>::iterator it = a4.begin(); it != a4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    //优化1
    for(auto it = a4.begin(); it != a4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    //优化2(利用范围for)
    for(auto x : a4)
    {
        cout << x << " ";
    }
    cout << endl;

    //利用push_back与pop_back实现尾插/尾删
    for(int i=0; i<5; i++)
    {
        a1.push_back(i);
        print(a1);
    }
    while(!a1.empty())
    {
        a1.pop_back();
        print(a1);
    }

    //front与back
    cout << a4.front() << " " << a4.back() << " " << endl;

    //resize
    vector<int> aa(5, 1);
    print(aa);
    aa.resize(10);
    print(aa);
    aa.resize(1);
    print(aa);

    //clear
    aa.resize(10);
    cout << aa.size() << endl;
    aa.clear();
    cout << aa.size() << endl;
    return 0;
}