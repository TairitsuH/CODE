#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    int N; cin >> N;
    vector<int> a(N,1);

    for(int i=2; i<=N; i++)
    {
        int k,p; cin >> k >> p;
        if(p == 0) 
        {
            auto I = find(a.begin(), a.end(), k);
            a.insert(I-1, i);
            
        }
        else 
        {
            auto I = find(a.begin(), a.end(), k);
            a.insert(I-1, i);
        }
    }
    for(int i=0; i<a.size(); i++) cout << a[i] << " ";

    // int M; cin >> M;
    // while(M--)
    // {
    //     for(int i=0; i<a.size(); i++)
    //     {
    //         int p; cin >> p;
    //         if(a[i] == p)
    //         {
    //             a.erase(a.begin()+i);
    //             break;
    //         }
    //     }
    // }

    // for(int i=0; i<a.size(); i++) cout << a[i] << " ";

    return 0;
}

