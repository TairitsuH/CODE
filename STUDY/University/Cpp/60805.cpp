#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// 判断闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 每个月的天数
int daysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

// 从公元1年1月1日到指定日期的总天数
long long totalDays(int year, int month, int day) {
    long long total = 0;
    // 加上整年的天数
    for (int y = 1; y < year; y++) {
        total += isLeapYear(y) ? 366 : 365;
    }
    // 加上整月的天数
    for (int m = 1; m < month; m++) {
        total += daysInMonth(year, m);
    }
    // 加上当月的天数
    total += day;
    return total;
}

class Student {
private:
    string name;
    int year, month, day;
    
public:
    Student(string n = "", int y = 0, int m = 0, int d = 0) 
        : name(n), year(y), month(m), day(d) {}
    
    // 重载 - 运算符，返回两个学生出生日期的差值（天数）
    long long operator-(const Student& other) const {
        long long d1 = totalDays(year, month, day);
        long long d2 = totalDays(other.year, other.month, other.day);
        return llabs(d1 - d2);  // 返回绝对值
    }
    
    string getName() const { return name; }
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students;
    
    // 读入学生信息
    for (int i = 0; i < n; i++) {
        string name;
        int y, m, d;
        cin >> name >> y >> m >> d;
        students.push_back(Student(name, y, m, d));
    }
    
    // 寻找年龄相差最小的两个人
    long long minDiff = LLONG_MAX;
    int idx1 = -1, idx2 = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = students[i] - students[j];
            if (diff < minDiff) {
                minDiff = diff;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    
    // 按输入顺序输出
    if (idx1 != -1 && idx2 != -1) {
        // 确保 idx1 是输入顺序中靠前的
        if (idx1 > idx2) {
            swap(idx1, idx2);
        }
        cout << students[idx1].getName() << "和" << students[idx2].getName() 
             << "年龄相差最小，为" << minDiff << "天。" << endl;
    }
    
    return 0;
}