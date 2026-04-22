#include"String.h"

using namespace tairitsu_h;

void String::reserve(size_t n)
{
    char* tmp = new char[n];
    strcpy(tmp, _str);
    _str = tmp;
}

void String::push_back(char ch)
{
    //检查扩容
    if(_size == _capacity)
    {
        _capacity = _capacity == 0 ? 4 : _capacity * 2;
        reserve(_capacity);
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
        _capacity = _size + len > 2 * _capacity ? _size + len : 2 * _capacity;
        reserve(_capacity);
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
        _capacity = _capacity == 0 ? 4 : _capacity * 2;
        reserve(_capacity);       
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
        _capacity = _size + len > 2 * _capacity ? _size + len : 2 * _capacity;
        reserve(_capacity);
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
    }

    _size -= len;
}

