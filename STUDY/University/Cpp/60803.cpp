#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
private:
    int vec[5];
public:
    Vector(int v[])
    {
        memcpy(vec, v, sizeof(int)*5);
    }

    Vector();
    
    // Vector(const Vector& obj);
    Vector operator+(const Vector& obj)
    {
        int arr[5];
        for(int i=0; i<5; i++)
        {
            arr[i] = vec[i] + obj.vec[i];
        }

        Vector ret(arr);
        return ret;
    }

    Vector operator -(const Vector& obj)
    {
        int arr[5];
        for(int i=0; i<5; i++)
        {
            arr[i] = vec[i] - obj.vec[i];
        }
        
        Vector ret(arr);
        return ret;
    }

    void print()
    {
        for(int i=0; i<5; i++)
        {
            cout << vec[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int arr1[5], arr2[5];
    for(int i=0; i<5; i++)
    {
        cin >> arr1[i];
    }
    
    for(int i=0; i<5; i++)
    {
        cin >> arr2[i];
    }

    Vector v1(arr1);
    Vector v2(arr2);

    Vector v3 = v1 + v2;
    v3.print();
    v3 = v1 - v2;
    v3.print();
    
    return 0;
}