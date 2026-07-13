//45min
#include<iostream>
using namespace std;

class Fur
{
protected:
    int No;
    int P;

public:
    Fur(int n, int p)
    :No(n)
    ,P(p)
    {}
};

class Fan: virtual public Fur //虚继承加在基类前！
{
protected:
    int dir;
    int pow;

public:
    Fan(int n, int p, int d, int po)
    :Fur(n, p)
    ,dir(d)
    ,pow(po)
    {}
    
    void dir_ctrl(int n)
    {
        dir = n;
    }

    void pow_ctrl(int n)
    {
        pow = n;
    }
};

class Wet: virtual public Fur //虚继承加在基类前！
{
protected:
    double V;
    double maxV;

public:
    Wet(int n, int p, double v, double mv)
    :Fur(n, p)
    ,V(v)
    ,maxV(mv)
    {}

    int alarm()
    {
        if(V >= 0.5 * maxV)
        {
            return 1;
        }
        else if(V < 0.1 * maxV)
        {
            return 3;
        }
        
        return 2;
    }
};

class WetFan: public Fan, public Wet
{
protected:
    int op;

public:
    WetFan(int n, int p, int d, int po, double v, double mv, int o)
    :Fur(n, p) //必须对基类初始化,因为中间类(fan,wet)对虚基类的初始化会被忽略
    ,Fan(n, p, d, po)
    ,Wet(n, p, v, mv)
    ,op(o)
    {}

    void set_op(int n)
    {
        op = n;
        if(n == 1)
        {
            dir = 0;
            pow = 1;
        }
        else if(n == 2)
        {
            dir = 1;
            pow = 2;
        }
        else if(n == 3)
        {
            dir = 1;
            pow = 3;
        }
    }

void print()
    {
        printf("加湿风扇--档位%d\n", op);
        printf("编号%d--功率%dW\n", No, P);
        if(dir == 0)
        {
            printf("定向吹风--风力%d级\n", pow);
        }
        else
        {
            printf("旋转吹风--风力%d级\n", pow);
        }
        
        int n = alarm();
        if(n == 1) //注意不能用%d输出double!必须显式转换!
        {
            printf("实际水容量%d升--水量正常\n", (int)V);
        }
        else if(n == 2)
        {
            printf("实际水容量%d升--水量偏低\n", (int)V);
        }
        else
        {
            printf("实际水容量%d升--水量不足\n", (int)V);
        }
    }
};

// 加湿风扇--档位1\n
// 编号1001--功率1000W\n
// 定向吹风--风力1级\n
// 实际水容量3升--水量正常\n

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, p, d, po, o; double v, mv;
        cin >> n >> p >> d >> po >> v >> mv >> o;
        int set; cin >> set;

        WetFan wf(n, p, d, po, v, mv, o);
        wf.set_op(set);
        wf.print();
    }
    return 0;
}