#include<iostream>
#include<vector>
using namespace std;


int n;
vector<int> a(0);

int main()
{
    cin >> n;
    int capacity = 0;
    while(n--)
    {
        int ith, x;
        cin >> ith >> x;
        if(ith > capacity) cout << "error";
        else
        {
            capacity++;
            a.resize(capacity);
            a.insert(a.begin()+ith, x);
            for(int i=0; i<capacity; i++)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}