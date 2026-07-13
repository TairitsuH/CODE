#include<iostream>
using namespace std;

static int totalCustNum = 0; // 顾客总人数
static float totalEarning = 0; // 旅店总收入
static float rent = 0; // 每个顾客的房租

class Hotel
{
public:
    string customerName; // 顾客姓名

    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(string customer)
    {
        customerName = customer;
    }

    void Display() //相应输出顾客姓名、顾客编号、总人数、总收入
    {
        cout << customerName << " ";
        cout << 2015;

        int num = totalCustNum;
        int cnt = 4;
        while(num)
        {
            num /= 10;
            cnt--;
        }
        while(cnt--)
        {
            cout <<'0';
        }
        cout << totalCustNum << " " << totalCustNum << " ";
        cout << totalEarning << endl;


    }
};


int main()
{
    cin >> rent;

    string name = "";
    while(1)
    {
        cin >> name;
        if(name == "0")
        {
            break;
        }
        Hotel htl(name);
        ++totalCustNum;
        totalEarning += rent;

        htl.Display();

    }
    return 0;   
}