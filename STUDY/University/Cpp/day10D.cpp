#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// void bubble(char out[], int s)
// {
//     for(int i=0; i<s-1; i++)
//     {
//         for(int j=0; j<s-i-1; j++)
//         {
//             if(out[j+1] < out[j])
//             {
//                 swap(out[j+1], out[j]);
//             }
//         }
//     }
// }

int main()
{
    char arr[80];
    char out[80] = {'\0'};
    cin >> arr;

    int sz = strlen(arr);
    int p = 1;
    out[0] = arr[0];
    for(int i=1; i<sz; i++)
    {
        int flag = 1;
        for(int j=0; j<strlen(out); j++)
        {
            if(arr[i] == out[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            out[p] = arr[i];
            p++;
        }
    }

    int s = strlen(out);
    // bubble(out, s);

    sort(out, out+p);
    cout << out;

    return 0;
}