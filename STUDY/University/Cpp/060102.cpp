#include<iostream>
using namespace std;

class Vehicle
{ 
protected:
     string no; //编号
public:
    Vehicle(string no1)
    :no(no1)
    {}

    virtual void display()=0; //应收费用
};

class Car: public Vehicle
{
    int s;
    int w;

public:
    Car(string no1, int s1, int w1)
    :s(s1)
    ,w(w1)
    ,Vehicle(no1)
    {}

    virtual void display()
    {
        cout << no << " " << s*8+w*2 << endl;
    }

};

class Truck: public Vehicle
{
    int w;
public:
    Truck(string no1, int w1)
    :w(w1)
    ,Vehicle(no1)
    {}

    virtual void display()
    {
        cout << no << " " << w*5 << endl;
    }
};

class Bus: public Vehicle
{
    int s;
public:
    Bus(string no1, int s1)
    :s(s1)
    ,Vehicle(no1)
    {}

    virtual void display()
    {
        cout << no << " " << s*30 << endl;
    }
};

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int type;
        string no;
        cin >> type >> no;
        if(type == 1)
        {
            int s, w;
            cin >> s >> w;
            Vehicle *pv = new Car(no, s, w);
            pv->display();
        }
        else if(type == 2)
        {
            int w;
            cin >> w;
            Vehicle *pv = new Truck(no, w);
            pv->display();
            
        }
        else
        {
            int s;
            cin >> s;
            Vehicle *pv = new Bus(no, s);
            pv->display();

        }

    }
    return 0;
}