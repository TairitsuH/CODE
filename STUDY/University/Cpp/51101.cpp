#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int cnt = 0;

class robot
{
private:
    string _name;
    string _type;
    string _level;
    string _chlev;

public:
    robot(string name, string type, string level, string chlev)
    {
        _name = name;
        _type = type;
        _level = level;
        _chlev = chlev;
    }

    void print_robot()
    {
        cout << _name << "--" << _chlev << "--"<< _level << "--";
        if(_type == "N")
        {
            int all = stoi(_level) * 5;
            cout << all << "--" << all << "--" << all << endl;
        }
        else if(_type == "A")
        {
            int all = stoi(_level) * 5;
            cout << all << "--" << all*2 << "--" << all << endl;
        }
        else if(_type == "D")
        {
            int all = stoi(_level) * 5;
            cout << all << "--" << all << "--" << all*2 << endl;
        }
        else
        {
            int all = stoi(_level) * 5;
            cout << all*10 << "--" << all << "--" << all << endl;
        }
    }

    string get_name()
    {
        return _name;
    }
    
    string get_type()
    {
        return _type;
    }
    
    string get_level()
    {
        return _level;
    }
    
    string get_chlev()
    {
        return _chlev;
    }

    void set_type(string type)
    {
        _type = type;
    }

    void set_name(string name)
    {
        _name = name;
    }

    void set_level(string level)
    {
        _level = level;
    }

    void set_chlev(string chlev)
    {
        _chlev = chlev;
    }
};

bool ChangeRobot(robot* r, string after_type)
{
    if(r->get_type() == after_type)
    {
        return false;
    }

    r->set_type(after_type);
    cnt++;
    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string name, type, level, chlev;
        cin >> name >> type >> level >> chlev;
        robot r1(name, type, level, chlev);

        ChangeRobot(&r1, r1.get_chlev());
        r1.print_robot();
    }

    cout << "The number of robot transform is " << cnt << endl;

    return 0;
}