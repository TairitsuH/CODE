#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
    int n,i,score;
    double sum = 0;
    cin >> n;
    int _max = 0;
    int _min = 10;
    for(i=0; i<n; i++)
    {
        cin >> score;
        _max = max(_max, score);
        _min = min(_min, score);
        sum += score;
    }
    double ave = (sum - _max - _min)/(n-2);
    cout << fixed << setprecision(2) << ave;
    return 0;
}