#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        char s; cin >> s;
        int n; cin >> n;

        if(s == 'I')
        {
            int * a = new int[n];
            int sum = 0;
            int * SUM = &sum;

            int * p = a;
            for(int i=0; i<n; i++) 
            {
                cin >> *p;
                *SUM += *p;
                p++;
            }
            int ave = *SUM / n;
            int *AVE = &ave;

            cout << *AVE << endl;
            delete[] a;
        }

        else if(s == 'C')
        {
            char * a = new char[n];
            char * max = a;

            char * p = a;
            for(int i=0; i<n; i++)
            {
                cin >> *p;
                if(*p > *max)
                {
                    *max = *p;
                }
                p++;
            }

            cout << *max << endl;
            delete[] a;
        }
        else
        {
            float * a = new float[n];

            float * min = a;

            float * p = a;
            for(int i=0; i<n; i++)
            {
                cin >> *p;
                if(*p < *min)
                {
                    *min = *p;
                }
                p++;
            }

            cout << *min << endl;
            delete[] a;
        }
    }
    return 0;
}