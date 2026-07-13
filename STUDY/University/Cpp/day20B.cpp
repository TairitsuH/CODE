#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        int * pa = &a;
        int * pb = &b;
        int * pc = &c;

        if(*pa < *pb) swap(*pa, *pb);
        if(*pb < *pc) swap(*pc, *pb);
        if(*pa < *pb) swap(*pa, *pb);

        cout << a << " " << b << " " << c << endl;
    }


    return 0;
}