#include<iostream>
using namespace std;

class Account
{
public:
    float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance;

    Account(string ac, string na, float ba)
    {
        accno = ac;
        accname = na;
        count = ba;
    }

    void deposit(float amount) // 存款
    {
        count += amount;
    }

    void withdraw(float amount) // 取款
    {
        count -= amount;
    }
    void show() // 显示账户所有基本信息
    {
        cout << accno << " " << accname << " ";
        cout << count << " ";
    }
};

float Account::interestRate = 0;

int main()
{
    cin >> Account::interestRate;
    int t;
    cin >> t;
    int sum = 0;
    while(t--)
    {
        string ac1, na1;
        float ba1;
        cin >> ac1 >> na1 >> ba1;
        Account A1(ac1, na1, ba1);

        float amount1, amount2;
        cin >> amount1 >> amount2;
        A1.deposit(amount1);
        A1.show();
        A1.count *= (1 + Account::interestRate);
        cout << A1.count << " ";
        
        A1.withdraw(amount2);
        cout << A1.count << endl;

        sum += A1.count;
    }
    cout << sum;
    return 0;
}