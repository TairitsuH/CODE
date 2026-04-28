#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n, 0);

    int t;
    cin >> t;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }

    while(t--)
    {
        int key;
        cin >> key;

        int left = 0;
        int right = n-1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(key > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        if(nums[left] == key)
        {
            cout << left+1 << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}