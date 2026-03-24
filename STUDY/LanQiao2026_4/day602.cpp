// //快速幂（倍增思想）
// //2026.3.17
// #include<iostream>
// using namespace std;

// typedef long long LL;

// LL qpow(LL a, LL b, LL p)
// {
//     LL ret = 1;
//     while(b)
//     {
//         if(b & 1) //如果b末尾为1
//         {
//             ret = ret * a % p; //取模规律
//         }
//         a = a * a % p; //取模规律
//         b >>= 1;
//     }
//     return ret;
// }

// int main()
// {
//     LL a, b, p; cin >> a >> b >> p;

//     printf("%lld^%lld mod %lld=%lld", a, b, p, qpow(a, b, p));
//     return 0;
// }

//2026.3.18 复盘
#include<iostream>
using namespace std;

typedef long long LL;
LL a, b, p;

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1)
        {
            ret = ret * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

int main()
{
    cin >> a >> b >> p;

    printf("%lld^%lld mod %lld=%lld", a, b, p, qpow(a, b, p));
    return 0;
}