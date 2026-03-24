//用vector数组存储树
// #include<iostream>
// #include<vector>
// using namespace std;

// const int N = 1e5 + 10;

// vector <int> edges[N];
// int n; //结点个数

// int main()
// {
//     cin >> n;
//     for(int i=1; i<n; i++) //n-1条边，i从1开始循环
//     {
//         int a, b;
//         cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }
//     return 0;
// }

//用vector数组深度优先遍历（DFS）树
// #include<iostream>
// #include<vector>
// using namespace std;

// const int N = 1e5 + 10;
// vector<int> edges[N];
// int n;

// bool st[N];


// void dfs(int u)
// {
//     cout << u << " ";
//     st[u] = true;
//     for(auto v : edges[u])
//     {
//         if(!st[v])
//         {
//             dfs(v);
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<n; i++)
//     {
//         int a, b; cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }

//     dfs(1);

//     return 0;
// }

// #include<iostream>
// #include<queue>
// #include<vector>
// using namespace std;

// const int N = 1e5 + 10;
// vector<int> edges[N];
// bool st[N];

// int n;

// void bfs()
// {
//     queue<int> q;
//     q.push(1); //传入头结点
//     st[1] = true;
    
//     while(q.size())
//     {
//         int u = q.front(); q.pop();
//         cout << u << " ";

//         for(auto v : edges[u])
//         {
//             if(!st[v])
//             {
//                 q.push(v);
//                 st[v] = true;
//             }
//         }
//     }

// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<n; i++)
//     {
//         int a,b; cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }

//     bfs();

//     return 0;
// }


// //复盘：vector模拟DFS
// #include<iostream>
// #include<vector>
// using namespace std;

// const int N = 1e5 + 10;
// int n;
// vector<int> edges[N];
// bool st[N];

// void dfs(int u) //遍历，bool
// {
//     cout << u << " ";
//     st[u] = true;
//     for(auto v : edges[u])
//     {
//         if(!st[v])
//         {
//             dfs(v);
//         }
//     }

// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<n; i++)
//     {
//         int a, b; cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }

//     dfs(1);

//     return 0;
// }

// //复盘：vector模拟BFS
// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// const int N = 1e5 + 10;
// vector<int> edges[N];
// bool st[N];
// int n;

// void bfs()
// {
//     queue<int> q;
//     q.push(1);
//     st[1] = true;
//     while(q.size())
//     {
//         int u = q.front();
//         q.pop();
//         cout << u << " ";

//         for(auto v : edges[u])
//         {
//             if(!st[v])
//             {
//                 q.push(v);
//                 st[v] = true;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<n; i++)
//     {
//         int a, b; cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }

//     bfs();

//     return 0;
// }