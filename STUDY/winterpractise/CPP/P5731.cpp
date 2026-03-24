// #include<iostream>
// using namespace std;

// const int N = 15;
// int dy[4] = {1, 0, -1, 0};
// int dx[4] = {0, 1, 0, -1};
// int arr[N][N];

// int main()
// {
//     int n; cin >> n;
    
//     int x = 1, y = 1;
//     int num = 1;
//     int p = 0; 
    
//     while(num <= n*n)
//     {
//         arr[x][y] = num;
//         int a = x + dx[p]; int b = y + dy[p];

//         if( a<1 || b<1 || a>n || b>n || arr[a][b]!=0 )
//         {
//             p = (p+1)%4;
//             a = x+dx[p]; b = y+dy[p];
//         }
//         x = a, y = b;
//         num++;
//     }

//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=n; j++)
//         {
//             printf("%3d",arr[i][j]);
//         }
//         cout << endl;
//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// const int N = 15;
// int arr[N][N];

// int main()
// {
//     int n; cin >> n;

//     int num = 1;
//     int x = 1, y = 1;
//     int p = 0;

//     while(num <= n*n)
//     {
//         arr[x][y] = num;
//         int a = x + dx[p];
//         int b = y + dy[p];
//         if(a<1 || b<1 || a>n || b>n || arr[a][b] != 0)
//         {
//             p = (p+1) % 4;
//             a = x + dx[p];
//             b = y + dy[p];
//         }
//         x = a;
//         y = b;
//         //p++;（不用写这一条！p只控制方向，当达到越界条件的时候才需要改变p的值！！）
//         num++;
//     }

//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=n; j++)
//         {
//             printf("%3d",arr[i][j]);
//         }
//         cout << endl;
//     }

//     return 0;
// }


// #include<iostream>
// #include<cstdio>
// using namespace std;

// const int N = 15;
// int arr[N][N];
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

// int main()
// {
//     int n; cin >> n;
//     int t = 1;
//     int pos = 0;
//     int x = 1, y = 1;
//     while(t <= n*n)
//     {
//         arr[x][y] = t;
//         int a = x + dx[pos];
//         int b = y + dy[pos];

//         if(a > n || b > n || b < 1 || arr[a][b] != 0) //越界
//         {
//             pos = (pos + 1) % 4;
//             a = x + dx[pos];
//             b = y + dy[pos];
//         }

//         x = a;
//         y = b;
//         t += 1;
//     }

//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=n; j++)
//         {
//             printf("%3d", arr[i][j]);
//         }
//         cout << endl;
//     }
//     return 0;
// }

