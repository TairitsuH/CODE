#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Cat
{
private:
    string name;
    int weight;

public:
    Cat() {}

    Cat(string n, int w)
    {
        name = n;
        weight = w;
    }

    void strname(string n)
    {
        name = n;
    }

    string getname()
    {
        return name;
    }

    void setweight(int w)
    {
        weight = w;
    }

    int getweight()
    {
        return weight;
    }

    void input()
    {
        cin >> name >> weight;
    }
};

bool cmpbyw(Cat a, Cat b)
{
    return a.getweight() < b.getweight();
}

int main()
{
    vector<Cat> cats;
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        Cat c;
        c.input();
        cats.push_back(c);
    }

        sort(cats.begin(), cats.end(), cmpbyw);

        for(int i=0; i<n; i++)
        {
            cout << cats[i].getname() << " ";
        }
    return 0;
}