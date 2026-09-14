#include<iostream>
#include<thread>
using namespace std;

//异常
// double Divide(int a, int b)
// {
//     try
//     {
//         if (b == 0)
//         {
//             string s = "Divided by zero condition!" ;
//             throw s;
//         }
//         else
//         {
//             return (double)a / (double)b;
//         }
//     }
//     catch (const char& errmsg) //不同类型
//     {
//         cout << "Divide" << ":" << errmsg << endl;
//     }

//     return 0;
// }

// void Func(int a, int b)
// {
//     try
//     {
//         cout << Divide(a, b) << endl;
//     }
//     catch (const string& str) //同类型最近
//     {
//         cout << "Func" << ":" << str << endl;
//     }
// }

// int main()
// {
//     int x, y; cin >> x >> y;
//     Func(x, y);
//     return 0;
// }

// 基类&派生类查找匹配
class Exception
{
public:
    Exception(const string& errmsg, int id)
        : _errmsg(errmsg)
        , _id(id)
    {}

    virtual string what() const
    {
        return _errmsg;
    }

    int getid() const
    {
        return _id;
    }

protected:
    string _errmsg;
    int _id;
};

class SqlException : public Exception
{
public:
    SqlException(const string& errmsg, int id, const string& sql)
        : Exception(errmsg, id)
        , _sql(sql)
    {}

    virtual string what() const
    {
        string str = "SqlException:";
        str += _errmsg;
        str += "->";
        str += _sql;
        return str;
    }
private:
    const string _sql;
};

class CacheException : public Exception
{
public:
    CacheException(const string& errmsg, int id)
        : Exception(errmsg, id)
    {}

    virtual string what() const
    {
        string str = "CacheException:";
        str += _errmsg;
        return str;
    }
};

class HttpException : public Exception
{
public:
    HttpException(const string& errmsg, int id, const string& type)
        : Exception(errmsg, id)
        , _type(type)
    {}

    virtual string what() const
    {
        string str = "HttpException:";
        str += _type;
        str += ":";
        str += _errmsg;
        return str;
    }

private:
    const string _type;
};

void SQLMgr()
{
    if (rand() % 7 == 0)
    {
        throw SqlException("权限不⾜", 100, "select * from name = '张三'");
    }
    else
    {
        cout << "SQLMgr 调⽤成功" << endl;
    }
}

void CacheMgr()
{
    if (rand() % 5 == 0)
    {
        throw CacheException("权限不⾜", 100);
    }
    else if (rand() % 6 == 0)
    {
        throw CacheException("数据不存在", 101);
    }
    else
    {
        cout << "CacheMgr 调⽤成功" << endl;
    }

    SQLMgr();
}

void HttpServer()
{
    if (rand() % 3 == 0)
    {
        throw HttpException("请求资源不存在", 100, "get");
    }
    else if (rand() % 4 == 0)
    {
        throw HttpException("权限不⾜", 101, "post");
    }
    else
    {
        cout << "HttpServer调⽤成功" << endl;
    }

    CacheMgr();
}

// int main()
// {
//     srand(time(0));

//     while (1)
//     {
//         this_thread::sleep_for(chrono::seconds(1)); //每隔1秒执行一次循环体

//         try
//         {
//             HttpServer(); //网页端
//         }
//         catch (const Exception& e) // 参数接收基类，基类对象和派生类对象都可以被捕获
//         {
//             cout << e.what() << endl;
//         }
//         catch (...)
//         {
//             cout << "Unkown Exception" << endl;
//         }
//     }

//     return 0;
// }



//异常重新抛出
//因为网络异常发不出去则就需要捕获异常再重新抛出；错误并非源自网路差，也要重新抛出。
void _SeedMsg(const string& s)
{
    if (rand() % 2 == 0)
    {
        throw HttpException("⽹络不稳定，发送失败", 102, "put");
    }
    else if (rand() % 7 == 0)
    {
        throw HttpException("你已经不是对象的好友，发送失败", 103, "put");
    }
    else
    {
        cout << "发送成功" << endl;
    }
}

void SendMsg(const string& s)
{
    // 发送消息失败，则再重试3次
    for (size_t i = 0; i < 4; i++)
    {
        try
        {
            _SeedMsg(s);
            break;
        }
        catch (const Exception& e)
        {
            if (e.getid() == 102)
            {
                // 重试三次以后否失败了，则说明网络太差了，重新抛出异常
                if (i == 3)
                    throw;

                cout << "开始第" << i + 1 << "重试" << endl;
            }
            else //并非网络异常引起的错误，交由外层函数处理（main）
            {
                throw;
            }
        }
    }
}

int main()
{
    srand(time(0));

    string str;
    while (cin >> str)
    {
        try
        {
            SendMsg(str);
        }
        catch (const Exception& e)
        {
            cout << e.what() << endl << endl;
        }
        catch (...)
        {
            cout << "Unkown Exception" << endl;
        }
    }
    return 0;
}