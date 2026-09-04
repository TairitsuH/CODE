#include<iostream>
#include<utility>
#include "myMap.h"
#include "mySet.h"
#include "RBTree.h"

using namespace std;
using namespace mzh;

void Print(const set<int>& s)
{
    set<int>::const_iterator it = s.end();
    while (it != s.begin())
    {
        --it;
        // 不⽀持修改
        //*it += 2;

        cout << *it << " ";
    }
    cout << endl;
}

void test_set()
{
    set<int> s;
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    int b[] = { 72, 19, 45, 8, 93, 31, 57, 62, 14, 87 };
    for (auto e : a)
    {
        s.insert(e);
    }
    for (auto e : b)
    {
        s.insert(e);
    }

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    Print(s);
}

void test_map()
{
    map<string, string> dict;
    dict.insert({ "sort", "排序" });
    dict.insert({ "left", "左边" });
    dict.insert({ "right", "右边" });

    dict["left"] = "左边，剩余";
    dict["insert"] = "插⼊";
    dict["string"];

    map<string, string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        // 不能修改first，可以修改second
        //it->first += 'x';
        it->second += " hehe";

        cout << it->first << ":" << it->second << endl;
        ++it;
    }
    cout << endl;
}


int main()
{
    cout << "test_set:" << endl;
    test_set();
    cout << endl;
    cout << "test_map:" << endl;
    test_map();
    cout << endl;
    cout << "end" << endl;
}

