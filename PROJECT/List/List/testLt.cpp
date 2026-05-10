#include <iostream>
#include "List.h"
using namespace std;
using namespace tairitsu_h;

int main()
{
    list<int> lst;

    // 测试插入
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(0);

    // 测试遍历
    cout << "遍历: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 测试大小
    cout << "size: " << lst.size() << endl;

    // 测试删除
    lst.pop_back();
    lst.pop_front();
    cout << "删首尾后: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 测试拷贝构造
    list<int> lst2 = lst;
    lst2.push_back(100);
    cout << "拷贝并加100: ";
    for (auto it = lst2.begin(); it != lst2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 测试赋值
    list<int> lst3;
    lst3 = lst2;
    cout << "赋值后: ";
    for (auto it = lst3.begin(); it != lst3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}