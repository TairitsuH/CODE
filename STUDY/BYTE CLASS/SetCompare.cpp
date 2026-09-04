//哈希表和红黑树的效率差异
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int test_set2()
{
    const size_t N = 1000000;          // 数据量 100 万

    unordered_set<int> us;             // 哈希表实现的无序集合
    set<int> s;                        // 红黑树实现的有序集合
    vector<int> v;
    v.reserve(N);

    srand(time(0));                    // 设置随机种子

    // 生成 N 个随机数，插入到 vector 中
    for (size_t i = 0; i < N; ++i)
    {
        // 三种测试模式可切换：
        // v.push_back(rand());         // 重复值较多
        v.push_back(rand() + i);        // 重复值相对少
        // v.push_back(i);              // 无重复，且有序
    }

    // 1. 测试 set 的插入性能
    size_t begin1 = clock(); //计时开始
    for (auto e : v)
    {
        s.insert(e);
    }
    size_t end1 = clock(); //计时结束
    cout << "set insert:" << end1 - begin1 << endl;

    // 2. 测试 unordered_set 的插入性能（先预分配空间）
    size_t begin2 = clock();
    us.reserve(N);
    for (auto e : v)
    {
        us.insert(e);
    }
    size_t end2 = clock();
    cout << "unordered_set insert:" << end2 - begin2 << endl;

    // 3. 测试 set 的查找性能
    int m1 = 0;
    size_t begin3 = clock();
    for (auto e : v)
    {
        auto ret = s.find(e);
        if (ret != s.end())
        {
            ++m1;
        }
    }
    size_t end3 = clock();
    cout << "set find:" << end3 - begin3 << "->" << m1 << endl;

    // 4. 测试 unordered_set 的查找性能
    int m2 = 0;
    size_t begin4 = clock();
    for (auto e : v)
    {
        auto ret = us.find(e);
        if (ret != us.end())
        {
            ++m2;
        }
    }
    size_t end4 = clock();
    cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;

    // 5. 输出实际插入的元素个数（去重后）
    cout << "插入数据个数：" << s.size() << endl;
    cout << "插入数据个数：" << us.size() << endl << endl;

    // 6. 测试 set 的删除性能
    size_t begin5 = clock();
    for (auto e : v)
    {
        s.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase:" << end5 - begin5 << endl;

    // 7. 测试 unordered_set 的删除性能
    size_t begin6 = clock();
    for (auto e : v)
    {
        us.erase(e);
    }
    size_t end6 = clock();
    cout << "unordered_set erase:" << end6 - begin6 << endl << endl;

    return 0;
}

int main()
{
    test_set2();
    return 0;
}