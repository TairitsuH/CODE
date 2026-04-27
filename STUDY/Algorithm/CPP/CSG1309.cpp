// #include<iostream>
// #include<string>
// using namespace std;

// int n;
// size_t M,N;
// char s;
// string x;

// int main()
// {

//     cin >> n >> s >> x;
//     x += s;

//     if(n == 0) 
//     {
//         N = x.find(s);
//         cout << x.substr(0,N);
//     }
//     else
//     {
//         N = -1;
//         while(n--)
//         {
//             N = x.find(s,N+1);
//         }
//         M = x.find(s, N+1);
//         cout<< x.substr(N+1, M-N-1);
//     }
//     return 0;
// }

#include<iostream>
#include<string>
using namespace std;

const int N = 1e5;
int n,i;
char s,ch;
string arr[N];
string current = "";

int main()
{
    cin >> n >> s;
    getchar();
    
    while(1)
    {
        ch = getchar();
        if(ch != s) break;
    }
    current += ch;

    while((ch = getchar()) != '\n')
    {
        if(ch == s && current != "")
        {
            arr[i] = current;
            current = "";
            i++;
        }
        else if(ch != s) current += ch;
    }
    arr[i] = current;
    cout << arr[n];
    return 0;
}