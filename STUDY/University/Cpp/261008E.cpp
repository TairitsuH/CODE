#include<iostream>
#include<string>
using namespace std;

class myString
{
private:
    string mainstr;
    int size;
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
};

myString::myString()  { size = 0; mainstr = ""; }
myString::~myString() { size = 0; mainstr = ""; }

void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}

void myString::GetNext(string p, int next[])
{
    int L = p.length();
    next[0] = -1;
    int i = 0, j = -1;
    while(i < L - 1)
    {
        if(j == -1 || p[i] == p[j])
        {
            ++i; ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int myString::KMPFind(string p, int pos, int next[])
{
    int i = pos, j = 0;
    int L = p.length();
    while(i < size && j < L)
    {
        if(j == -1 || mainstr[i] == p[j])
        {
            ++i; ++j;
        }
        else
            j = next[j];
    }
    if(j >= L)
        return i - L + 1;
    return 0;
}

int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    for(i = 0; i < L; i ++)
        cout << next[i] << ' ';
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete []next;
    return v;
}

int main()
{
    int t;
    string s, p;
    cin >> t;
    while(t--)
    {
        cin >> s >> p;
        myString ms;
        ms.SetVal(s);
        cout << ms.KMPFindSubstr(p, 0) << endl;
    }
    return 0;
}
