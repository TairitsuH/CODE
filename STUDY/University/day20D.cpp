#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int num; cin >> num;

        int * a = new int[num];
        for(int i=0; i<num; i++)
        {
            cin >> a[i];
        }

        int find; cin >> find;
        find--;

        int * pmid = a + num/2;

        cout << *(pmid - 1) << " " << *(pmid + 1) << endl << a[find] << endl;

        delete[] a;
    }
    return 0;
}