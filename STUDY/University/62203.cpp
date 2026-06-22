#include<iostream>
#include<vector>
using namespace std;

template<class T>
void Test_Code(vector<T>& arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            cout << "Invalid" << endl;
            return;
        }
    }

    cout << "Valid" << endl;
 }

int main()
{
    char op;
    while(cin >> op && op != EOF)
    {
        if(op == 'c')
        {
            vector<char> arr(6);
            for(int i=0; i<6; i++)
            {
                cin >> arr[i];
            }
            Test_Code(arr);
        }
        else if(op == 'i')
        {
            vector<int> arr(6);
            for(int i=0; i<6; i++)
            {
                cin >> arr[i];
            }
            Test_Code(arr);
        }
        else
        {
            vector<float> arr(6);
            for(int i=0; i<6; i++)
            {
                cin >> arr[i];
            }
            Test_Code(arr);
        }
    }
    return 0;
}