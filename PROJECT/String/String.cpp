#include"String.h"

namespace tairitsu_h
{
    const size_t String::npos = -1;

    void String::reserve(size_t n)
    {
        if(n > _capacity)
        {
            // cout << "reserve: new_cap=" << n << ", old_cap=" << _capacity << endl;
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
            // cout << "reserve: new_cap=" << n << ", old_cap=" << _capacity << endl;
        }
    }

    void String::push_back(char ch)
    {
        //检查扩容
        if(_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }

        //尾插字符
        _str[_size++] = ch;
        _str[_size] = '\0';
    }

    void String::append(const char* str)
    {
        size_t len = strlen(str);
        //检查扩容
        if(_size + len > _capacity)
        {
            reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
        }

        //尾插字符串
        strcpy(_str + _size, str);
        _size += len;
    }

    String& String::operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }

    String& String::operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    void String::insert(size_t pos, char ch)
    {
        assert(pos <= _size);

        //检查扩容
        if(_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }

        //插入字符
        size_t end = _size + 1;
        while(end > pos)
        {
            _str[end] = _str[end - 1];
            end--;
        }

        _str[pos] = ch;
        _size++;
    }

    void String::insert(size_t pos, const char* str)
    {
        size_t len = strlen(str);

        //检查扩容
        if(_size + len > _capacity)
        {
            reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
        }

        //插入字符
        size_t end = _size + len;
        while(end - len + 1 > pos)
        {
            _str[end] = _str[end - len];
            end--;
        }

        for(size_t i=0; i<len; i++)
        {
            _str[pos+i] = str[i];
        }
        //不能用strcpy因为会把\0拷贝进去

        _size += len;
    }

    //缺省值只能写在声明处
    void String::erase(size_t pos, size_t len)
    {
        assert(pos < _size);

        if(len > _size - pos)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            for(size_t i=pos+len; i<=_size; i++)
            {
                _str[i - len] = _str[i]; 
            }

            _size -= len;
        }
    }

    size_t String::find(char ch, size_t pos)
    {
        assert(pos < _size);

        for(size_t i=pos; i<_size; i++)
        {
            if(_str[i] == ch)
            {
                return i;
            }
        }

        return npos;
    }

    size_t String::find(const char* str, size_t pos)
    {
        assert(pos < _size);

        char* ppos = strstr(_str, str);
        if(ppos == nullptr)
        {
            return npos;
        }

        return ppos - _str;
    }

    String String::substr(size_t pos, size_t len)
    {
        assert(pos < _size);

        if(len > _size - pos)
        {
            len = _size - pos;
        }

        String ret;
        ret.reserve(len);
        for(size_t i=0; i<len; i++)
        {
            ret += _str[pos + i];
        }

        return ret;
    }

    String& String::operator=(const String& str)
    {
        if(this != &str)
        {
            delete[] _str;
            _str = new char[str._capacity + 1];
            strcpy(_str, str._str);
            _size = str._size;
            _capacity = str._capacity;
        }

        return *this;
    }

    bool operator<(const String& s1, const String& s2)
    {
        return strcmp(s1.c_str(), s2.c_str()) < 0;
    }

    bool operator>(const String& s1, const String& s2)
    {
        return !(s1 < s2 || s1 == s2);
    }

    bool operator<=(const String& s1, const String& s2)
    {
        return !(s1 > s2);
    }

    bool operator>=(const String& s1, const String& s2)
    {
        return !(s1 < s2);
    }

    bool operator==(const String& s1, const String& s2)
    {
        return strcmp(s1.c_str(), s2.c_str()) == 0;
    }

    bool operator!=(const String& s1, const String& s2)
    {
        return !(s1 == s2);
    }

    ostream& operator<<(ostream& out, const String& s)
    {
        for(const auto ch : s)
        {
            out << ch;
        }

        return out;
    }

    //单字符输入：一个个字符尾插，效率低
    // istream& operator>>(istream& in, String& s)
    // {
    //     char ch;
    //     ch = in.get();
    //     while(ch != ' ' && ch != '\n')
    //     {
    //         s.push_back(ch);
    //         ch = in.get();
    //     }

    //     return in;
    // }

    //缓冲数组输入
    istream& operator>>(istream& in, String& s)
    {
        int N = 256;
        char buff[N];
        int i = 0;
        char ch = in.get();
        while(ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;

            if(i == N - 1)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = in.get();
        }

        if(i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }

}
