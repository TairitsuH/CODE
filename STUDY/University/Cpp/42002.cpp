#include<iostream>
using namespace std;

class Construct
{
public:
    int _x;

    Construct(int x = 0)
    {
        _x = x;
        if(x == 0)
        cout << "Constructed by default, ";
        else
        cout << "Constructed using one argument constructor, ";
    }

    Construct(Construct& con)
    {
        _x = con._x;
        cout << "Constructed using copy constructor, ";
    }

};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int pos;
        cin >> pos;
        if(pos == 0)
        {
            Construct con;
            cout << "value = " << con._x << endl;
        }
        else if(pos == 1)
        {
            int x;
            cin >> x;
            Construct con(x);
            cout << "value = " << x << endl;
        }
        else
        {
            int x;
            cin >> x;
            Construct con1(x);
            cout << "value = " << x << endl;
            Construct con2 = con1;
            cout << "value = " << x << endl;
        }
    }
    return 0;
}