#include<iostream>
#include<cstring>
using namespace std;

class CTelNumber
{
private:
    char* ptel;

public:
    CTelNumber(char* tel)
    {
        ptel = new char[10];
        ptel = tel;

    }

    void ModifyNum()
    {
        if(strlen(ptel) != 7)
        {
            cout << "Illegal phone number" << endl;
            return;
        }
        for(int i=0; i<7; i++)
        {
            if(!(ptel[i] >='0' && ptel[i] <= '9'))
            {
                cout << "Illegal phone number" << endl;                
                return;
            }
        }

        if(ptel[0] == '2' || ptel[0] == '3' || ptel[0] == '4')
        {
            for(int i=7; i>=0; i--)
            {
                ptel[i+1] = ptel[i];
            }
            ptel[0] = '8';
            cout << ptel << endl;
        }
        else if(ptel[0] == '5' || ptel[0] == '6' || ptel[0] == '7' || ptel[0] == '8')
        {
            for(int i=7; i>=0; i--)
            {
                ptel[i+1] = ptel[i];
            }
            ptel[0] = '2';
            cout << ptel << endl;
        }
        else
        {
            cout << "Illegal phone number" << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char tel[10];
        cin >> tel;
        CTelNumber num(tel);

        num.ModifyNum();
    }
    return 0;
}