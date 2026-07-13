//50min
//类型转换重载，string和char[]
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克

public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : virtual public Weight
{
private:
    int jin;
    int liang;
    int qian;

public:
    CN(int j, int l, int q, int g, char k[])
    :Weight(k, g)
    ,jin(j)
    ,liang(l)
    ,qian(q)
    {}

    void Convert(int g)
    {
        int j = g / 500;
        g -= j * 500;
        int l = g / 50;
        g -= l * 50;
        int q = g / 5;
        g -= q * 5;

        jin = j;
        liang = l;
        qian = q; 
        gram = g;
    }

	void print(ostream& out) // 输出不同类型的计重信息
    {
        out << "中国计重:" << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
    }
};

// 英国计重
class EN : virtual public Weight
{
private:
    int bang;
    int angs;
    int dalan;

public:
    EN(int b, int a, int d, int g, char k[])
    :Weight(k, g)
    ,bang(b)
    ,angs(a)
    ,dalan(d)
    {}

    void Convert(int g)
    {
        int j = g / 512;
        g -= j * 512;
        int l = g / 32;
        g -= l * 32;
        int q = g / 2;
        g -= q * 2;

        bang = j;
        angs = l;
        dalan = q; 
        gram = g;
    }

    void print(ostream& out) // 输出不同类型的计重信息
    {
        out << "英国计重:" << bang << "磅" << angs << "盎司" << dalan << "打兰" << gram << "克" << endl;
    }

    //类型转换函数：不能是全局函数！不能有返回值！不能有参数！不能是虚函数！
    //转为目标类
    operator CN() 
    {
        int g = bang * 512 + angs * 32 + dalan * 2 + gram;
        CN ret(0, 0, 0, 0, "中国计重");
        ret.Convert(g);
        return ret;
    }
};

// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法

void operator<<(ostream& out, Weight& w)
{
    w.print(out);
}

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}