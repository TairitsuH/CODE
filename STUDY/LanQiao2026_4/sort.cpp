// //插入排序
// #include<iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int arr[N];
// int n;

// void insert_sort()
// {
//     for(int j=2; j<=n; j++) //第一个位置默认有序
//     {
//         int key = arr[j];
//         int k = j-1;
//         while(k >= 1 && arr[k] > key) //前面比key大的，统一右移
//         {
//             arr[k+1] = arr[k];
//             k--;
//         }
 
//         arr[k+1] = key;
        
//     }
// }

// int main()
// {
//     cin >> n; //一共需要排序n个数
//     for(int i=1; i<=n; i++)
//     {
//         cin >> arr[i];
//     }

//     insert_sort();
    
//     for(int i=1; i<=n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// //堆排序
// #include<iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n;
// int a[N];

// void down(int parent, int len)
// {
//     int child = parent * 2;
    
//     while(child <= len) //如果还有孩子结点则循环继续
//     {
//         if(child+1 <= len && a[child+1] > a[child]) 
//         //如果有右孩子结点并且右孩子结点大于左孩子结点
//         {
//             child++;
//         }
//         if(a[parent] >= a[child]) return; //无需交换的情况
        
//         //需要交换的情况
//         swap(a[parent], a[child]);
//         parent = child; //将孩子结点作为新的父结点
//         child = parent * 2; //新孩子结点
//         //继续循环
//     }
// }

// void heap_sort()
// {
//     for(int i=n/2; i>=1; i--) //选取最后一个非叶结点
//     {
//         down(i, n);
//     }

//     for(int i=n; i>1; i--)
//     {
//         swap(a[1], a[i]);

//         down(1, i-1);
//     }
// }

// int main()
// {
//     cin >> n;

//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i];
//     }

//     heap_sort();

//     for(int i=1; i<= n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     return 0;
// }