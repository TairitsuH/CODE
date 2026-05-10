#include <iostream>
#include <deque>
#include <list>
#include"Queue.h"

int main()
{
    using namespace tairitsu_h;

    std::cout << "========== 测试1: 默认deque队列 ==========" << std::endl;
    queue<int> q;

    for (int i = 1; i <= 5; ++i) {
        q.push(i);
        std::cout << "push: " << i << ", size = " << q.size() << std::endl;
    }

    std::cout << "\nfront = " << q.front() << ", back = " << q.back() << std::endl;

    std::cout << "\npop: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\npop后 size = " << q.size() << std::endl;

    std::cout << "\n========== 测试2: 用list做底层 ==========" << std::endl;
    queue<double, std::list<double>> q2;
    q2.push(1.1);
    q2.push(2.2);
    q2.push(3.3);

    q2.front() = 9.9;
    std::cout << "修改后的front = " << q2.front() << std::endl;

    while (!q2.empty()) {
        std::cout << q2.front() << " ";
        q2.pop();
    }
    std::cout << std::endl;

    std::cout << "\n========== 测试3: const队列 ==========" << std::endl;
    queue<int> q3;
    q3.push(10);
    q3.push(20);
    q3.push(30);

    const queue<int>& constRef = q3;
    std::cout << "const队列的front = " << constRef.front() << std::endl;
    std::cout << "const队列的back = " << constRef.back() << std::endl;

    std::cout << "\n所有测试通过！" << std::endl;

    return 0;
}