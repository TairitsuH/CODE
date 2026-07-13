#include <iostream>
using namespace std;
 
int FindArrayMax( int a[], int n )
{
    int max = *a;
    int * p = a;
    for(int i=0; i<n; i++)
    {
        if(*a > max)
        {
            max = *a;
        }
        a ++;
    }
    return max;
}
 
int main()
{
    const int MAXN=10;
    int i, n;
    int a[MAXN];
 
    cin>>n;
    for( i=0; i<n; i++ ){
        cin>>a[i];
    }
 
    cout<<FindArrayMax(a, n)<<endl;
 
    return 0;
}