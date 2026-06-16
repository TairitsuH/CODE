class Solution {
public:
    int getRandom(vector<int>& arr, int l, int r)
    {
        return arr[rand() % (r - l + 1) + l];
    }

    void Quick_Sort_K(vector<int>& arr, int l, int r, int k)
    {
        if(l == r) return;

        int key = getRandom(arr, l, r);
        int left = l - 1;
        int right = r + 1;
        int i = l;

        while(i < right)
        {
            if(arr[i] < key) swap(arr[++left], arr[i++]);
            else if(arr[i] > key) swap(arr[--right], arr[i]);
            else i++;
        }

            int a = left - l + 1;
            int b = right - left - 1;

            if(k <= a) Quick_Sort_K(arr, l, left, k);
            else if(k <= a + b) return;
            else Quick_Sort_K(arr, right, r, k - a - b);
        
    }

    vector<int> smallestK(vector<int>& arr, int k)
    {
        if(arr.size() == 0 || k == 0) return {};
        srand(time(NULL));

        Quick_Sort_K(arr, 0, arr.size() - 1, k);

        return {arr.begin(), arr.begin() + k};
    }
};

//二刷：注意作用域的范围不要搞错了
//一刷：随机选key + 数组分三块，需要注意数组为空的情况，这题和LCR159相同
// class Solution {
// public:
//     void Quick_Sort_K(vector<int>& arr, int l, int r, int k)
//     {
//         if(l == r) return;

//         int key = getRandom(arr, l, r);
//         int left = l - 1;
//         int right  = r + 1;
//         int i = l;
        
//         while(i < right)
//         {
//             if(arr[i] < key)
//             {
//                 swap(arr[++left], arr[i++]);
//             }
//             else if(arr[i] > key)
//             {
//                 swap(arr[--right], arr[i]);
//             }
//             else
//             {
//                 i++;
//             }
//         }

//         int a = left - l + 1;
//         int b = right - left - 1;

//         if(k < a) Quick_Sort_K(arr, l, left, k);
//         else if(k <= a + b) return;
//         else Quick_Sort_K(arr, right, r, k - a - b);
//     }

//     int getRandom(vector<int>& arr, int l, int r)
//     {
//         return arr[rand() % (r - l + 1) + l];
//     }

//     vector<int> smallestK(vector<int>& arr, int k)
//     {
//         if(arr.size() == 0) return {};

//         srand(time(NULL));
//         Quick_Sort_K(arr, 0, arr.size()-1, k);

//         return {arr.begin(), arr.begin() + k};
//     }
// };
