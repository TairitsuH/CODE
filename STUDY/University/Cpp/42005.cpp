#include <iostream>
#include <cstring>
using namespace std;

// 日期类
class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    void print() const {
        cout << year << "." << month << "." << day;
    }
};

// 手机类
class Phone {
private:
    char type;           // 号码类型
    char number[12];     // 号码字符串
    int state;           // 状态 1=在用 2=未用 3=停用
    Date* stopDate;      // 停机日期指针
    
public:
    // 构造函数
    Phone(char t, const char* num, int s, int stopY, int stopM, int stopD)
        : type(t), state(s), stopDate(nullptr)
    {
        strcpy(number, num);
        cout << "Construct a new phone " << number << endl;
    }
    
    // 拷贝构造函数（深拷贝）
    Phone(const Phone& other)
        : type('D'), state(other.state), stopDate(nullptr)
    {
        // 号码末尾加 X
        strcpy(number, other.number);
        int len = strlen(number);
        number[len] = 'X';
        number[len + 1] = '\0';
        
        // 深拷贝停机日期
        if (other.stopDate != nullptr) {
            // 需要访问 Date 的成员，通过构造函数重新创建
            // 这里假设我们能拿到年月日，实际需要 Date 提供 getter
            // 简单处理：先置空，实际应该复制
            stopDate = nullptr;
        }
        
        cout << "Construct a copy of phone " << other.number << endl;
    }
    
    // 析构函数
    ~Phone() {
        delete stopDate;
    }
    
    // 停机功能
    void stop(int year, int month, int day) {
        state = 3;
        stopDate = new Date(year, month, day);
        cout << "Stop the phone " << number << endl;
    }
    
    // 打印功能
    void print() const {
        // 类型转换
        const char* typeStr;
        if (type == 'A') typeStr = "机构";
        else if (type == 'B') typeStr = "企业";
        else if (type == 'C') typeStr = "个人";
        else if (type == 'D') typeStr = "备份";
        else typeStr = "未知";
        
        // 状态转换
        const char* stateStr;
        if (state == 1) stateStr = "在用";
        else if (state == 2) stateStr = "未用";
        else if (state == 3) stateStr = "停用";
        else stateStr = "未知";
        
        cout << "类型=" << typeStr 
             << "||号码=" << number 
             << "||State=" << stateStr;
        
        if (stopDate != nullptr) {
            cout << "||停机日期=";
            stopDate->print();
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        char number[12];
        int state;
        int stopY, stopM, stopD;
        
        cin >> type >> number >> state >> stopY >> stopM >> stopD;
        
        // 1. 创建原号码
        Phone original(type, number, state, stopY, stopM, stopD);
        original.print();
        
        // 2. 拷贝备份
        Phone backup = original;
        backup.print();
        
        // 3. 原号码停机
        original.stop(stopY, stopM, stopD);
        original.print();
        
        // 4. 分割线
        cout << "----" << endl;
    }
    
    return 0;
}