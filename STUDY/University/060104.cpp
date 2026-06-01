#include<iostream>
using namespace std;

class BaseAccount
{
public:
    string name;
    string acc;
    int b;

    BaseAccount(string n, string a, int b1)
    :name(n)
    ,acc(a)
    ,b(b1)
    {}

    void Deposit(int m)
    {
        b += m;
    }

    virtual void Withdraw(int m)
    {
        if(m > b)
        {
            cout << "insufficient" << endl;
        }
        else
        {
            b -= m;
        }
    }

    virtual void Display()
    {
        cout << name << " " << acc << " " << "Balance:";
        cout << b << endl;
    }

};

class BasePlus: public BaseAccount
{
public:
    int limit = 5000;

    BasePlus(string n, string a, int b1)
    :BaseAccount(n, a, b1)
    {}

    virtual void Withdraw(int m)
    {
        if(b > m)
        {
            b -= m;
        }
        else
        {
            if(m > b + limit)
            {
                cout << "insufficient" << endl;
            }
            else
            {
                limit = limit - (m - b);
                b = 0;
            }
        }
    }

    virtual void Display()
    {
        cout << name << " " << acc << " " << "Balance:";
        cout << b << " limit:" << limit << endl;
    }
};



int main()
{
    int t; cin >> t;

    while(t--)
    {
        string name, acc;
        int b1;
        cin >> name >> acc >> b1;

        int d1, d2, w1, w2;
        cin >> d1 >> w1 >> d2 >> w2;

        if(acc[1] == 'A')
        {
            BaseAccount b(name, acc, b1);

            b.Deposit(d1);
            b.Withdraw(w1);
            b.Deposit(d2);
            b.Withdraw(w2);
            b.Display();
        }
        else
        {
            BaseAccount *b = new BasePlus(name, acc, b1);
            b->Deposit(d1);
            b->Withdraw(w1);
            b->Deposit(d2);
            b->Withdraw(w2);  
            b->Display();          
        }

    }
    return 0;
}