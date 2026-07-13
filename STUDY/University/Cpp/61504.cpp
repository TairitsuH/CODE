#include <iostream>
#include <string>
using namespace std;

class CXGraph {
private:
    int n;  // 当前大小（奇数，1~21）
public:
    CXGraph(int size) : n(size) {}

    // 显示当前图案（返回字符串，便于输出）
    string show() const {
        string result;
        for (int i = 0; i < n; i++) {
            int spaces = min(i, n - 1 - i);
            int stars = n - 2 * spaces;
            result.append(spaces, ' ');
            result.append(stars, 'X');
            if (i != n - 1) result += '\n';
        }
        return result;
    }

    // 放大
    void enlarge() {
        if (n + 2 <= 21) n += 2;
    }

    // 缩小
    void shrink() {
        if (n - 2 >= 1) n -= 2;
    }

    // 前置++
    CXGraph& operator++() {
        enlarge();
        return *this;
    }

    // 后置++
    CXGraph operator++(int) {
        CXGraph temp = *this;
        enlarge();
        return temp;
    }

    // 前置--
    CXGraph& operator--() {
        shrink();
        return *this;
    }

    // 后置--
    CXGraph operator--(int) {
        CXGraph temp = *this;
        shrink();
        return temp;
    }

    // 输出运算符重载
    friend ostream& operator<<(ostream& os, const CXGraph& g) {
        os << g.show();
        return os;
    }
};

// 主函数（题目给定，不可修改）
int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }

        cout << endl;
    }
    return 0;
}