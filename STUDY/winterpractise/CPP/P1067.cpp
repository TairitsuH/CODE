// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int n; cin>> n;
//     for(int i=n; i>=0; i--)
//     {
//         int a; cin >> a;
//         if(a == 0) continue;

//         //符号
//         if(a < 0) cout << "-";
//         else
//         {
//             if(i != n) cout << "+";
//         }

//         //数字
//         a = abs(a);
//         if(a != 1 ||(a == 1 && i == 0)) cout << a;

//         //次数
//         if(i == 0) continue;
//         else if(i == 1) cout << "x";
//         else cout << "x^" << i;


//     }
//     return 0;
// }



// #include<iostream>
// using namespace std;

// int main()
// {
//     int n; cin >> n;

//     for(int i=n; i>=0; i--)
//     {
//         int a; cin >> a;
//         if(a == 0) continue;

//         if(a > 0 && i != n) cout << "+";
//         else if(a < 0) cout << "-";

//         a = abs(a);
//         if((a != 1 && i != 0) || i == 0) cout << a;

//         if(i == 1) cout << "x";
//         else if(i != 1 && i != 0) cout << "x^" << i;
//     }

//     return 0;
// }

// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int n; cin >> n;
//     for(int i=n; i>=0; i--)
//     {
//         int a; cin >> a;

//         if(a == 0) continue;

//         //符号
//         if(a > 0)
//         {
//             if(i != n) cout << "+";
//         } 
//         else if(a < 0) cout << "-";

//         //系数
//         a = abs(a);
//         if(a != 0 && a != 1) cout << a;
//         else if(a == 1 && i == 0) cout << a;

//         //次数
//         if(i == 1) cout << "x";
//         else if(i != 1 && i != 0) cout << "x^" << i;
        
//     }

//     return 0;
// }

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    for(int i=n; i>=0; i--)
    {
        int a; cin >> a;

        if(a == 0) continue;

        if(a < 0) cout << '-';
        else if(a > 0 && i != n) cout << '+';

        a = abs(a);
        if(a == 1 && i == 0) cout << a;
        if(a != 1 && a != 0) cout << a;

        if(i == 1) cout << 'x';
        else if(i != 0 && i != 1) cout << "x^" << i;
    }
    return 0;
}