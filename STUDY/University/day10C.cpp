#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    char arr[80];
    cin >> arr;
    int sz = strlen(arr);
    vector <char> ARR(0);

    int flag = 0;
    for(int i=0; i<sz; i++)
    {
        if(arr[i] >= 'A' && arr[i] <= 'Z')
        {
            flag = 1;
            int flag1 = 1;
            for(int j=0; j<ARR.size(); j++)
            {
                if(arr[i] == ARR[j])
                {
                    flag1 = 0;
                    break;
                }
            }
            if(flag1 == 1)
            {
                cout << arr[i];
                ARR.push_back(arr[i]);
            }
        }
    }

 if(flag == 0) cout << "Not Found";

    return 0;
}