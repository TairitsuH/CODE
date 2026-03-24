#include <stdio.h>
#include <string.h>

const char* digits[10][5] = {
    {"XXX", "X.X", "X.X", "X.X", "XXX"},  // 0
    {"..X", "..X", "..X", "..X", "..X"},  // 1
    {"XXX", "..X", "XXX", "X..", "XXX"},  // 2
    {"XXX", "..X", "XXX", "..X", "XXX"},  // 3
    {"X.X", "X.X", "XXX", "..X", "..X"},  // 4
    {"XXX", "X..", "XXX", "..X", "XXX"},  // 5
    {"XXX", "X..", "XXX", "X.X", "XXX"},  // 6
    {"XXX", "..X", "..X", "..X", "..X"},  // 7
    {"XXX", "X.X", "XXX", "X.X", "XXX"},  // 8
    {"XXX", "X.X", "XXX", "..X", "XXX"}   // 9
};

int main() {
    int n;
    char num[101];
    scanf("%d%s", &n, num);

    // 逐行处理（共5行）
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            printf("%s", digits[d][row]);
            if (i != n - 1) {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}