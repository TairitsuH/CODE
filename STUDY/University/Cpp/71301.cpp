//22min
#include<iostream>
#include<string>
using namespace std;

// 普通会员类
class Member 
{  
protected: //不要设置成private，方便派生类访问
    int No;
    int score;
    string name;

public:
    Member(int no, string n, int s)
    :No(no)
    ,name(n)
    ,score(s)
    {}

    virtual void add(int m)
    {
        score += m;
    }

    virtual int exchange(int s)
    {
        int m = s / 100;
        score -= m * 100;
        return m;
    }

    virtual void print()
    {
        printf("普通会员%d--%s--%d\n", No, name.c_str(), score); //注意字符串的转换！
    }
};

// 贵宾会员类
class VIP: public Member
{
protected:
    int p;
    int q;

public:
    VIP(int no, string name, int score, int p1, int q1)
    :Member(no, name, score)
    ,p(p1)
    ,q(q1)
    {}

    void add(int m) override
    {
        score += m * p;
    }

    int exchange(int s) override
    {
        int m = s / q;
        score -= m * q;
        return m;
    }

    void print() override
    {
        printf("贵宾会员%d--%s--%d\n", No, name.c_str(), score); //注意字符串的转换！
    }
};

int main()
{
	// 创建一个基类对象指针
	Member* pm;

	// 输入数据，创建普通会员对象mm
	// 使用指针pm执行以下操作：
	// 1、pm指向普通会员对象mm
	// 2、输入数据，通过pm执行积分累加和积分兑换
	// 3、通过pm调用打印方法输出
    int no, s; string n; cin >> no >> n >> s;
    Member mm(no, n, s);
    pm = &mm;

    int money, sc; cin >> money >> sc;
    pm->add(money);
    pm->exchange(sc);
    pm->print();

	// 输入数据，创建贵宾会员对象vv
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
	// 2、输入数据，通过pm执行积分累加和积分兑换
	// 3、通过pm调用打印方法输出

    int p1, q1; cin >> no >> n >> s >> p1 >> q1; //注意不要重定义！
    VIP vv(no, n, s, p1, q1);
    pm = &vv;

    cin >> money >> sc; //注意不要重定义！
    pm->add(money);
    pm->exchange(sc);
    pm->print();

	return 0;
}