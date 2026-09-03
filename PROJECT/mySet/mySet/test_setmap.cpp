#include<iostream>
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
    for (auto e : a)
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