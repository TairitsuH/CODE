#pragma once
#include<iostream>
#include<assert.h>
#include<cstring>

namespace tairitsu_h
{
    class String
    {
    private:
        char* _str;
        size_t _size;
        size_t _capacity;

    public:
        typedef char* iterator;

        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        // //无参构造
        // String()
        //     :_str(new char[1]{'\0'})
        //     ,_size(0)
        //     ,_capacity(0)
        // {}

        // //有参构造(构造函数不会按照声明顺序初始化)
        // String(char* str)
        // {
        //     _size = strlen(str);
        //     _capacity = _size;
        //     _str = new char[_capacity + 1];
        //     strcpy(_str, str);
        // }

        //全缺省构造
        String(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        //析构
        ~String()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        //拷贝构造
        String(const String& str)
        {
            _str = new char[str._capacity + 1];
            strcpy(_str, str._str);
            _size = str._size;
            _capacity = str._capacity;
        }

        size_t size() const
        {
            return _size;
        }

        size_t capacity() const
        {
            return _capacity;
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];        
        }

        const char* c_str() const
        {
            return _str;
        }

        void reserve(size_t n);
        void push_back(char ch);
        void append(const char* str);
        String& operator+=(char ch);
        String& operator+=(const char* str);

        void insert(size_t pos, char ch);
        void insert(size_t pos, const char* str);

        static const size_t npos;
        void erase(size_t pos, size_t len = npos);
    
    };
    
    const size_t String::npos = -1;
}