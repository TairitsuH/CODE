#include<iostream>
#include<cstring>
using namespace std;

struct stu
{
    long long num;
    char t1[20];
    char t2[20];
    char t3[20];
};

int anscmp(stu *a, stu *b)
{
        int x = min(strlen(a->t1), strlen(b->t1));
        int y = min(strlen(a->t2), strlen(b->t2));
        int z = min(strlen(a->t3), strlen(b->t3));
        double same = 0;
        double per1, per2, per3;
        for(int i=0; i<x; i++)
        {
            if(a->t1[i] == b->t1[i]) same++;
        }
        per1 = same / x;

        same = 0;
        for(int i=0; i<y; i++)
        {
            if(a->t2[i] == b->t2[i]) same++;
        }
        per2 = same / y;

        same = 0;
        for(int i=0; i<z; i++)
        {
            if(a->t3[i] == b->t3[i]) same++;
        }
        per3 = same / z;

        if(per1 >= 0.9) return 1;
        else if(per2 >= 0.9) return 2;
        else if(per3 >= 0.9) return 3;
        return 0;

}

int main()
{
    int t; cin >> t;
    stu* st = new stu[t];

    for(int i=0; i<t; i++)
    {
        cin >> st[i].num >> st[i].t1 >> st[i].t2
        >> st[i].t3;
    }

    for(int j=0; j<t-1; j++)
    {
        for(int k=j+1; k<t; k++)
        {
            int a = anscmp(&st[j], &st[k]);
            if(a != 0)
            {
                cout << st[j].num << " " 
                << st[k].num << " " << a << endl;
            }
        }
    }

    delete[] st;
    return 0;
}