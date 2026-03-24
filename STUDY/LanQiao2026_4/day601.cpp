// //哈夫曼编码：贪心https://ac.nowcoder.com/acm/problem/233601
// //2026.3.17
// #include<iostream>
// #include<queue>
// #include<vector>
// using namespace std;

// typedef long long LL;
// priority_queue<LL, vector<LL>, greater<LL>> heap;
// //创建小根堆heap

// int main()
// {
//     LL n; cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         LL x; cin >> x;
//         heap.push(x);
//     }

//     LL ret = 0;
//     while(heap.size() > 1)
//     {
//         LL x = heap.top();
//         heap.pop();
//         LL y = heap.top();
//         heap.pop();
//         ret += x + y;
//         heap.push(x + y);
//         //不能写两次push，因为这样取出放回等价，总数量不变，会导致死循环！！！
//     }

//     cout << ret << endl;


//     return 0;
// }


//2026.3.18 复盘
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL>> heap;
LL n;

LL length()
{
    LL x, y;
    LL ret = 0;
    while(heap.size() > 1)
    {
        x = heap.top();
        heap.pop();
        y = heap.top();
        heap.pop();

        ret += x + y;
        heap.push(x + y);
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        LL x; cin >> x;
        heap.push(x);
    }

    cout << length();
    return 0;
}