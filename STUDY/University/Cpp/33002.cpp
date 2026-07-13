#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

class Health
{
private:
    string name;
    double height;
    double weight;
    double rounda;

public:
    Health()
    {
        name = "";
        height = 0;
        weight = 0;
        rounda = 0;
    }

    void input()
    {
        cin >> name >> height >> weight >> rounda;
    }

    int BMI()
    {
        double bmi = weight / (height * height);
        return (int)floor(bmi+0.5);
    }

    double bodyfat()
    {
        double a = rounda * 0.74;
        double b = weight * 0.082 + 34.89;
        double fatweight = (a - b) / weight;
        return fatweight;
    }
    void printdata()
    {
        cout << name << "的BMI指数为" << BMI() << "--"
        << "体脂率为";
        printf("%.2lf\n", bodyfat());
    }

};

int main()
{
    int t; cin >> t;
    Health health[100];
    for(int i=0; i<t; i++)
    {
        health[i].input();
    }

    for(int i=0; i<t; i++)
    {
        health[i].printdata();

    }
    return 0;
}