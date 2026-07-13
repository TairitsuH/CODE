//20min
#include<iostream>
using namespace std;

class Metal
{
private:
    int C;
    int W;
    int V;

public:
    Metal(int c, int w, int v)
    :C(c)
    ,W(w)
    ,V(v)
    {}

    friend Metal operator+(Metal& m1, Metal& m2);
    friend Metal operator*(Metal& m1, int n);

    Metal operator++()
    {
        C++;
        W *= 1.1;
        V *= 1.1;
        return *this;
    }

    Metal operator--(int) //占位符！放在后置中，与前置区分
    {
        Metal tmp = *this;
        C--;
        W *= 0.9;
        V *= 0.9;
        return tmp;
    }

    void print()
    {
        printf("硬度%d--重量%d--体积%d\n", C, W, V);
    }
};

Metal operator+(Metal& m1, Metal& m2)
{
    Metal m(0, 0, 0);
    m.C = m1.C + m2.C;
    m.W = m1.W + m2.W;
    m.V = m1.V + m2.V;

    return m;
}

Metal operator*(Metal& m1, int n)
{
    Metal m(m1.C, m1.W, m1.V);
    m.V = m1.V * n;
    return m;
}

int main()
{
    int c, w, v; cin >> c >> w >> v;
    int c1, w1, v1; cin >> c1 >> w1 >> v1;
    int n; cin >> n;

    Metal m1(c, w, v);
    Metal m2(c1, w1, v1);
    
    Metal m = m1 + m2;
    m.print();
    
    Metal m11 = m1 * n;
    m11.print();

    ++m1;
    m2--;

    m1.print();
    m2.print();

    return 0;
}