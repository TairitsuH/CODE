// // #include<iostream>
// // using namespace std;

// // const int N = 1e6 + 10;
// // int a[N], b[N], c[N];
// // int la, lb, lc;

// // void add(int c[], int a[], int b[])
// // {
// //     for(int i=0; i<lc; i++)
// //     {
// //         c[i] += a[i] + b[i];
// //         c[i+1] += c[i] / 10;
// //         c[i] %= 10;
// //     }

// //     if(c[lc]) lc++;
// // }

// // int main()
// // {
// //     string x,y; cin >> x >> y;

// //     la = x.size(); lb = y.size(); lc = max(la, lb);
// //     for(int i=0; i<la; i++) a[la - 1 - i] = x[i]  - '0';
// //     for(int i=0; i<lb; i++) b[lb - 1 - i] = y[i]  - '0';

// //     add(c,a,b);

// //     for(int i=lc-1; i>=0; i--) cout<< c[i];
// //     return 0;
// // }




// #include<iostream>
// #include<string>
// using namespace std;

// const int N = 1e6+10;
// int a[N],b[N],c[N];
// int la,lb,lc;
// string x,y;

// void add(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] + b[i];
//         c[i+1] += c[i] / 10;
//         c[i] %= 10;
//     }
//     if(c[lc]) lc++;
// }


// int main()
// {
//     cin >> x >> y;

//     la = x.size(), lb = y.size(), lc = max(la, lb);
//     for(int i=0; i<la; i++) a[i] = x[la-i-1] - '0';
//     for(int i=0; i<lb; i++) b[i] = y[lb-i-1] - '0'; //逆序存储

//     add(a,b,c); //高精度加法

//     for(int i=lc-1; i>=0; i--) cout << c[i]; //逆序输出结果

//     return 0;
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 1e5;
// string x,y;
// int la,lb,lc;
// int a[N], b[N], c[N];

// void add(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] + b[i];
//         c[i+1] += c[i] / 10;
//         c[i] %= 10;
//     }
//     if(c[lc]) lc++;

// }

// int main()
// {
//     cin >> x >> y;
//     la = x.size(), lb = y.size(), lc = max(la, lb);
//     for(int i=0; i<la; i++) a[i] = x[la-i-1]-'0';
//     for(int i=0; i<lb; i++) b[i] = y[lb-i-1]-'0';

//     add(a, b, c);

//     for(int i=lc-1; i>=0; i--)
//     {
//         cout << c[i];
//     }

//     return 0;
// }

// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// const int N = 1e6 + 10;
// string x, y;
// int a[N], b[N], c[N];
// int la, lb, lc;

// void add(int a[], int b[], int c[])
// {
//     for(int i=0; i<lc; i++)
//     {
//         c[i] += a[i] + b[i];
//         c[i+1] += c[i] / 10;
//         c[i] %= 10;
//     }
//     if(c[lc]) lc++;
// }

// int main()
// {
//     cin >> x >> y;
    
//     la = x.size(), lb = y.size(), lc = max(la, lb);
//     for(int i=0; i<la; i++) a[la-i-1] = x[i] - '0';
//     for(int i=0; i<lb; i++) b[lb-i-1] = y[i] - '0';

//     add(a, b, c);

//     for(int i = lc-1; i>=0; i--) cout << c[i];
//     return 0;
// }