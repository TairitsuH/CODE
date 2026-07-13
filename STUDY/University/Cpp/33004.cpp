#include<iostream>
using namespace std;

class CAccont
{
private:
    string acc;
    string name;
    float bal;

public:
    CAccont(){}
    CAccont(string acc, string name, float bal)
    {
        acc = "";
        name = "";
        bal = 0;
    }

    void input()
    {
        cin >> acc >> name >> bal;
    }

    void check()
    {
        cout << name << "'s balance is " << bal << endl;
    }

    void deposit(float money)
    {
        bal += money;
        cout << "saving ok!" << endl;
    }

    void withdraw(float money)
    {
        if(money > bal)
        {
            cout << "sorry! over limit!" << endl;
        }
        else
        {
            bal -= money;
            cout << "withdraw ok!" << endl;
        }
    }

};

int main()
{
    for(int i=0; i<2; i++)
    {
        CAccont ca;
        ca.input();
        ca.check();

        float dep; cin >> dep;
        ca.deposit(dep);

        ca.check();

        float wit; cin >> wit;
        ca.withdraw(wit);

        ca.check();
    }
    return 0;
}