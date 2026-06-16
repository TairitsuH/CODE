class Solution {
public:
    void Quick_Sort_K(vector<int>& arr, int l, int r, int k)
    {
        if(l == r) return;

        int key = getRandom(arr, l, r);
        int left = l - 1;
        int right  = r + 1;
        int i = l;
        
        while(i < right)
        {
            if(arr[i] < key)
            {
                swap(arr[++left], arr[i++]);
            }
            else if(arr[i] > key)
            {
                swap(arr[--right], arr[i]);
            }
            else
            {
                i++;
            }
        }

        int a = left - l + 1;
        int b = right - left - 1;

        if(k < a) Quick_Sort_K(arr, l, left, k);
        else if(k <= a + b) return;
        else Quick_Sort_K(arr, right, r, k - a - b);
    }

    int getRandom(vector<int>& arr, int l, int r)
    {
        return arr[rand() % (r - l + 1) + l];
    }

    vector<int> inventoryManagement(vector<int>& stock, int cnt)
    {
        if(stock.size() == 0) return {};

        srand(time(NULL));
        Quick_Sort_K(stock, 0, stock.size()-1, cnt);

        return {stock.begin(), stock.begin() + cnt};
    }
};

//本题和17.19相同，都是返回前k小的数，不计顺序