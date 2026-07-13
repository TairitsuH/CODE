#include <iostream>
#include<iomanip>
using namespace std;
 
double d = 6.2619;
double e = 6.6744;
double y = 0.0516;
double h = 0.9200;
double *D = &d;
double *E = &e;
double *Y = &y;
double *H = &h;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        char s; cin >> s;
        double num; cin >> num;
        double ret = 0;

        if(s == 'D')
        {
            ret = num * (*D);
        }
        else if(s == 'E')
        {
            ret = num * (*E);

        }
        else if(s == 'Y')
        {
            ret = num * (*Y);
        }
        else
        {
            ret = num * (*H);
        }
        
        cout <<fixed<<setprecision(4) << ret << endl;
    }
    return 0;
}