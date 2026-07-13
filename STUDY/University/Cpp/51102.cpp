#include<iostream>
#include<string>
using namespace std;

class Num
{
    long long _number;
    char _type;

public:

    friend class Tel;

    Num()
    {}

    Num(long long number, char type)
        :_number(number)
        ,_type(type)
    {}

    void set_number(long long number)
    {
        _number = number;
    }
    
    void set_type(char type)
    {
        _type = type;
    }
    
    void print_number()
    {
        cout << _number;
    }

    void print_type()
    {
        cout << _type;
    }

};

class Tel
{
private:
    Num _num;
    int _set;
    string _name;

public:

    friend class Num;

    Tel()
    {}

    Tel(long long num, char type, int set, string name)
        :_num(num, type)
        ,_set(set)
        ,_name(name)
        {
            _num.print_number(); 
            cout << " constructed." << endl;
        }
    

    ~Tel()
    {
        cout << _num._number << " destructed." << endl;
    }

    void print_tel()
    {
        cout << "Phone="; _num.print_number();
        cout << "--" << "Type="; _num.print_type();
        cout << "--" << "State=";
        if(_set == 1)
        cout << "use" ;
        else
        cout << "unuse";
        cout << "--" << "Owner=" << _name << endl;
    }

    bool find_number(long long number)
    {
        if(_num._number != number) return false;
        return true;
    }
};

int main()
{
    string name1, name2, name3;
    char type1, type2, type3;
    int set1, set2, set3;
    long long n1, n2, n3;
    cin >> n1 >> type1 >> set1 >> name1;
    cin >> n2 >> type2 >> set2 >> name2;
    cin >> n3 >> type3 >> set3 >> name3;

    Tel t1(n1, type1, set1, name1);
    Tel t2(n2, type2, set2, name2);
    Tel t3(n3, type3, set3, name3);
    
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;

        if(t1.find_number(n))
        {
            t1.print_tel();
        }
        else if(t2.find_number(n))
        {
            t2.print_tel();
        }
        else if(t3.find_number(n))
        {
            t3.print_tel();
        }
        else
        {
            cout << "wrong number." << endl;
        }
    }

    return 0;
}