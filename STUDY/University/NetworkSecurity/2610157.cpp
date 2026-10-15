#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string str;
        getline(cin, str);

        int sum[6] = {0};
        for (int i = 0; i < (int)str.length(); i++) {
            sum[i % 6] += str[i];
        }

        for (int i = 0; i < 6; i++) {
            while (sum[i] >= 10) {
                int t = 0;
                while (sum[i] > 0) {
                    t += sum[i] % 10;
                    sum[i] /= 10;
                }
                sum[i] = t;
            }
            cout << sum[i];
        }
        cout << endl;
    }

    return 0;
}
