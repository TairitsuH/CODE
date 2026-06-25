//一刷：二分查找算法，和下标一一比对，O(logN)
class Solution {
public:
    int takeAttendance(vector<int>& records)
    {
        int left = 0;
        int right = records.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(records[mid] == mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if(left == records[left]) return left + 1;
        return left;
    }
};

//二刷：试了下各种解法
// //求和相减
// class Solution {
// public:
//     int takeAttendance(vector<int>& records)
//     {
//         int n = records.size();
//         int ret = n * (n + 1) / 2; //注意计算公式！
//         for(auto x : records)
//         {
//             ret -= x;
//         }

//         if(ret == 0 && records[0] != 0) return 0;
//         return ret;
//     }
// };
//异或：相同为0，不同为1
// class Solution {
// public:
//     int takeAttendance(vector<int>& records)
//     {
//         int ret = 0;
//         int num = 0;
//         for(int i=0; i<records.size(); i++)
//         {
//             ret ^= records[i];
//             ret ^= num++;
//         }

//         return ret ^= num;
//     }
// };
// // 直接遍历找结果
// class Solution {
// public:
//     int takeAttendance(vector<int>& records)
//     {
//         int i;
//         for(i=0; i<records.size(); i++)
//         {
//             if(records[i] != i)
//             {
//                 return i;
//             }
//         }

//         return i; 
//     }
// };
// 哈希表
// class Solution {
// public:
//     int takeAttendance(vector<int>& records)
//     {
//         vector<int> hash(records.size() + 1, 0);

//         for(auto x : records)
//         {
//             hash[x]++;
//         }

//         for(int i=0; i<hash.size(); i++)
//         {
//             if(hash[i] == 0)
//             {
//                 return i;
//             }
//         }

//         return 0;
//     }
// };

