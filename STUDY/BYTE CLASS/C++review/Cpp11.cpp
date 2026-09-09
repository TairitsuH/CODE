#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<string.h>
#include<algorithm>
using namespace std;

// //基础认知
// int main()
// {
//     //左值
//     int* p = new int(0);
//     int b = 1;
//     const int c = b;
//     *p = 10;
//     string s("111111");
//     s[0] = 'x';
//     // cout << &c << endl;
//     // cout << (void*)&s[0] << endl; //打印地址

//     //左值引用
//     string& si = s;
//     int*& pi = p;

//     //右值
//     double x = 1.1, y = 2.2;
//     // 以下⼏个10、x + y、fmin(x, y)、string("11111")都是常⻅的右值
//     10;
//     x + y;
//     string("11111");


//     //右值引用
//     double&& z = x + y;
//     int&& num = 10;

//     // cout << z << endl;
//     // cout << num << endl;
    
//     //左/右值引用右左值
//     const int& ci = 10;
//     double&& f = move(x);
//     cout << ci << endl;
//     cout << f << endl;
//     return 0;
// }

// //参数匹配
// void f(int& x)
// {
// std::cout << "左值引⽤重载 f(" << x << ")\n";
// }
// void f(const int& x)
// {
// std::cout << "到 const 的左值引⽤重载 f(" << x << ")\n";
// }
// void f(int&& x)
// {
// std::cout << "右值引⽤重载 f(" << x << ")\n";
// }
// int main()
// {
//     int x = 10;
//     int y = 20;
//     const int z = 30;
//     f(x);
//     f(15);
//     f(z);
//     f(std::move(x));
//     return 0;
// }


namespace bit
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
        friend ostream& operator<<(ostream& out, const string& s);


        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }

        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            cout << "string(char* str)-构造" << str << endl;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }

        string(const string& s)
            :_str(nullptr)
        {
            cout << "string(const string& s) -- 拷贝构造" << s << endl;
            reserve(s._capacity);
            for (auto ch : s)
            {
                push_back(ch);
            }
        }

        // 移动构造
        string(string&& s)
        {
            cout << "string(string&& s) -- 移动构造" << s << endl;
            swap(s);
        }

        //拷贝赋值
        string& operator=(const string& s)
        {
            cout << "string& operator=(const string& s) -- 拷贝赋值" << s << endl;
            if (this != &s)
            {
                _str[0] = '\0';
                _size = 0;
                reserve(s._capacity);
                for (auto ch : s)
                {
                    push_back(ch);
                }
            }
            return *this;
        }

        // 移动赋值
        string& operator=(string&& s)
        {
            cout << "string& operator=(string&& s) -- 移动赋值" << s << endl;
            swap(s);
            return *this;
        }

        ~string()
        {
            // cout << "~string() -- 析构" << endl;
            delete[] _str;
            _str = nullptr;
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                if (_str)
                {
                    strcpy(tmp, _str);
                    delete[] _str;
                }
                _str = tmp;
                _capacity = n;
            }
        }

        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }

        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        const char* c_str() const
        {
            return _str;
        }

        size_t size() const
        {
            return _size;
        }

    private:
        char* _str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;
    };

    ostream& operator<<(ostream& out, const string& s)
    {
        for(size_t i=0; i<s._size; i++)
        {
            out << s._str[i];
        }
        return out;
    }

}



// int main()
// {
//     bit::string s1("xxxxx");
//     // 拷贝构造
//     bit::string s2 = s1;
//     // 构造+移动构造，优化后直接构造
//     bit::string s3 = bit::string("yyyyy");
//     // 移动构造
//     bit::string s4 = move(s1);
//     cout << "******************************" << endl;
//     return 0;
// }



namespace bit
{
    string addStrings(string num1, string num2)
    {
        string str;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
            int ret = val1 + val2 + next;
            next = ret / 10;
            ret = ret % 10;
            str += ('0' + ret);
        }
        if (next == 1)
            str += '1';
        reverse(str.begin(), str.end());
        cout << "******************************" << endl;
        return str;
    }
}

//场景1
//不存在移动构造时返回3构造+1拷贝构造；
//存在移动构造时返回3构造+1移动构造
// int main()
// {
//     bit::string ret = bit::addStrings("11111", "2222");
//     cout << ret.c_str() << endl;
//     return 0;
// }

//场景2
int main()
{
bit::string ret; //1构造
ret = bit::addStrings("11111", "2222"); //括号内部2构造，return1构造，1移动赋值
cout << ret.c_str() << endl;
return 0;
}