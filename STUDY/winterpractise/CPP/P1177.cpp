#include<iostream>
#include<algorithm>
using namespace std;

void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child + 1] > a[child])
        {
            child += 1;
        }

        if(a[parent] < a[child])
        {
            swap(a[parent], a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* a, int n)
{
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while(end > 0)
    {
        swap(a[0], a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n]{};

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    HeapSort(a, n);

    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}