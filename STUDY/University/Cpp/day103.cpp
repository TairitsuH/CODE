#include<iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double score;
        cin >> score;
        if(score >= 85) cout << "A" << endl;
        else if(score >= 75 && score < 85) cout << "B" << endl;
        else if(score >= 65 && score < 75) cout << "C" << endl;
        else if(score >= 60 && score < 65) cout << "D" << endl;
        else  cout << "F" << endl;
    }

    return 0;
}