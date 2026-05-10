#include <iostream>
#include <vector>
#include <list>
#include "Stack.h"

int main()
{
    using namespace tairitsu_h;

    std::cout << "========== 测试1: 默认deque栈 ==========" << std::endl;
    stack<int> st1;

    // 入栈
    for (int i = 1; i <= 5; ++i) {
        st1.push(i);
        std::cout << "push: " << i << ", size = " << st1.size() << std::endl;
    }

    // 查看栈顶
    std::cout << "\ntop = " << st1.top() << std::endl;

    // 出栈
    std::cout << "\npop: ";
    while (!st1.empty()) {
        std::cout << st1.top() << " ";
        st1.pop();
    }
    std::cout << "\npop后 size = " << st1.size() << std::endl;

    std::cout << "\n========== 测试2: 用vector做底层 ==========" << std::endl;
    stack<double, std::vector<double>> st2;

    st2.push(1.1);
    st2.push(2.2);
    st2.push(3.3);

    st2.top() = 9.9;  // 修改栈顶元素
    std::cout << "修改后的top = " << st2.top() << std::endl;

    while (!st2.empty()) {
        std::cout << st2.top() << " ";
        st2.pop();
    }
    std::cout << std::endl;

    std::cout << "\n========== 测试3: 用list做底层 ==========" << std::endl;
    stack<char, std::list<char>> st3;

    st3.push('A');
    st3.push('B');
    st3.push('C');

    std::cout << "size = " << st3.size() << std::endl;
    std::cout << "top = " << st3.top() << std::endl;

    while (!st3.empty()) {
        std::cout << st3.top() << " ";
        st3.pop();
    }
    std::cout << std::endl;

    std::cout << "\n========== 测试4: const栈 ==========" << std::endl;
    stack<int> st4;
    st4.push(10);
    st4.push(20);
    st4.push(30);

    const stack<int>& constRef = st4;
    std::cout << "const栈的top = " << constRef.top() << std::endl;
    // constRef.top() = 100;  // 这行会编译错误，因为const版本不能修改

    std::cout << "\n所有测试通过！" << std::endl;

    return 0;
}