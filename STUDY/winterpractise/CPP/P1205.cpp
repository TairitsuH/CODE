#include<iostream>
using namespace std;

const int N = 15;
int n;
char op[N][N], ed[N][N];

int cmp(char goal[N][N], char ed[N][N])
{ 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(goal[i][j] != ed[i][j]) return 0;
        }
    }
    return 1;
}

int one(char op[N][N], char ed[N][N])
{
    char goal[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            goal[j][n-i-1] = op[i][j];
        }
    }
    return(cmp(goal, ed));
}


int two(char op[N][N], char ed[N][N])
{
    char goal[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            goal[n-i-1][n-j-1] = op[i][j];
        }
    }
    return(cmp(goal, ed));
}

int three(char op[N][N], char ed[N][N])
{
    char goal[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            goal[n-j-1][i] = op[i][j];
        }
    }
    return(cmp(goal, ed));
}


int four(char op[N][N], char ed[N][N])
{
    char goal[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            goal[i][n-j-1] = op[i][j];
        }
    }
    return(cmp(goal, ed));
}

int five(char op[N][N], char ed[N][N])
{
    char goal[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            goal[i][n-j-1] = op[i][j];
        }
    }
    if(one(goal, ed)) return 1;
    if(two(goal, ed)) return 1;
    if(three(goal, ed)) return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> op[i][j];
        }
        getchar();
    }

        for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> ed[i][j];
        }
        getchar();
    }

    if(one(op,ed)) cout << "1";
    else if(two(op,ed)) cout << "2";
    else if(three(op,ed)) cout << "3";
    else if(four(op,ed)) cout << "4";
    else if(five(op,ed)) cout << "5";
    else if(cmp(op,ed)) cout << "6";
    else cout << "7";

    return 0;
}