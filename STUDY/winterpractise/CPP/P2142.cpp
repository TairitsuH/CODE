// #include<iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int a[N], b[N], c[N];
// int la, lb, lc;

// bool cmp(string& x, string& y) //传引用避免拷贝大字符串
// {
//     if(x.size() != y.size()) return x.size() < y.size(); //ture则进if条件
    
//     return x<y; //直接比较x，y的最高位
// }

// void sub(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] - b[i];
//         if(c[i] < 0)
//         {
//             c[i+1] -= 1;
//             c[i] += 10;
//         }

//     }
    
//     while(lc > 1 && c[lc-1] == 0) lc--;
// }

// int main()
// {
//     string x,y; cin >> x >> y;
//     if(cmp(x,y))
//     {
//         swap(x,y);
//         cout << "-";
//     }

//     la = x.size(); lb = y.size(); lc = max(la, lb);

//     for(int i=0; i<la; i++) a[la-i-1] = x[i] - '0';
//     for(int i=0; i<lb; i++) b[lb-i-1] = y[i] - '0';

//     sub(a, b, c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];

//     return 0;
// }


//相比于高精度加法，减法在此基础上还需要判断两个字符串所对应的数的大小，
//并且需要在保证长度至少为1的同时删除前导0

// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// const int N = 1e6+10;
// string x,y;
// int la,lb,lc;
// int a[N], b[N], c[N];

// bool cmp(string& x, string& y) //传引用提高效率
// {
//     if(x.size() != y.size()) return x.size() < y.size();

//     return x < y;
// }

// void sub(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] - b[i];
//         if(c[i] < 0)
//         {
//             c[i+1]--;
//             c[i] += 10;
//         }
//     }

//     while(lc > 1 && c[lc-1] == 0) lc--;
// }

// int main()
// {
//     cin >> x >> y;

//     if(cmp(x, y)) 
//     {
//         swap(x, y);
//         cout << "-";
//     }

//     la = x.size(); lb = y.size(); lc = max(la, lb);
//     for(int i=0; i<la; i++) a[i] = x[la-i-1]-'0';
//     for(int i=0; i<lb; i++) b[i] = y[lb-i-1]-'0';

//     sub(a,b,c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];

//     return 0;
// }

// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// const int N = 1e6 + 10;
// int a[N], b[N], c[N];
// int la, lb, lc;

// bool cmp(string &x, string &y)
// {
//     if(x.size() != y.size()) return x.size() < y.size();
//     else return x < y;
//     return 0;
// }

// void sub(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] - b[i];
//         if(c[i] < 0)
//         {
//             c[i+1] -= 1;
//             c[i] += 10;
//         }
//     }
//     while(lc > 1 && c[lc-1] == 0) lc--;
// }

// int main()
// {
//     string x, y; cin >> x >> y;
//     if(cmp(x, y))
//     {
//         swap(x, y);
//         cout << "-";
//     }
//     la = x.size(), lb = y.size(), lc = max(la, lb);
//     for(int i=0; i<la; i++) a[la-i-1] = x[i] - '0';
//     for(int i=0; i<lb; i++) b[lb-i-1] = y[i] - '0';

//     sub(a, b, c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];

//     return 0;
// }