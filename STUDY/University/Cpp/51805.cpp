#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class CDate {
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}
    
    bool check() {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap()) daysInMonth[1] = 29;
        return day <= daysInMonth[month - 1];
    }
    
    bool isLeap() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    void print() {
        cout << year << "年" << month << "月" << day << "日";
    }
    
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

class COldId {
protected:
    char* pId15, * pName;
    CDate birthday;
public:
    COldId(char* pIdVal, char* pNameVal, CDate& day) : birthday(day) {
        pId15 = new char[strlen(pIdVal) + 1];
        strcpy(pId15, pIdVal);
        pName = new char[strlen(pNameVal) + 1];
        strcpy(pName, pNameVal);
    }
    
    virtual bool check() {
        if (!pId15 || strlen(pId15) != 15) return false;
        for (int i = 0; i < 15; i++) {
            if (!isdigit(pId15[i])) return false;
        }
        // 检查15位中的出生日期（6位：yymmdd）是否与输入的birthday一致
        int yy = (pId15[6] - '0') * 10 + (pId15[7] - '0');
        int mm = (pId15[8] - '0') * 10 + (pId15[9] - '0');
        int dd = (pId15[10] - '0') * 10 + (pId15[11] - '0');
        // 年份：1900 + yy（15位身份证都是19xx年出生）
        int birthYearFrom15 = 1900 + yy;
        
        // 与输入的birthday比对
        if (birthYearFrom15 != birthday.getYear() || mm != birthday.getMonth() || dd != birthday.getDay()) {
            return false;
        }
        
        CDate birth15(birthYearFrom15, mm, dd);
        if (!birth15.check()) return false;
        
        return true;
    }
    
    virtual void print() {
        cout << pName << endl;
        cout << pId15 << " ";
        birthday.print();
        cout << endl;
    }
    
    virtual ~COldId() {
        delete[] pId15;
        delete[] pName;
    }
    
    char* getName() { return pName; }
    char* getPId15() { return pId15; }
    CDate& getBirthday() { return birthday; }
};

class CNewId : public COldId {
private:
    char* pId18;
    CDate issueDay;
    int validYear;
    
    static char calcCheckCode(const char* id17) {
        int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        char checkCode[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        int sum = 0;
        for (int i = 0; i < 17; i++) {
            sum += (id17[i] - '0') * weight[i];
        }
        return checkCode[sum % 11];
    }
    
    // 从15位生成18位（用于校验）
    void generateId18(char* output) const {
        output[0] = pId15[0];
        output[1] = pId15[1];
        output[2] = pId15[2];
        output[3] = pId15[3];
        output[4] = pId15[4];
        output[5] = pId15[5];
        output[6] = '1';
        output[7] = '9';
        output[8] = pId15[6];
        output[9] = pId15[7];
        output[10] = pId15[8];
        output[11] = pId15[9];
        output[12] = pId15[10];
        output[13] = pId15[11];
        output[14] = pId15[12];
        output[15] = pId15[13];
        output[16] = pId15[14];
        output[17] = calcCheckCode(output);
        output[18] = '\0';
    }
    
public:
    CNewId(char* pIdVal, char* pNameVal, CDate& day, char* pId18Val, CDate& issue, int valid)
        : COldId(pIdVal, pNameVal, day), issueDay(issue), validYear(valid) {
        pId18 = new char[strlen(pId18Val) + 1];
        strcpy(pId18, pId18Val);
    }
    
    bool check() override {
        // 1. 首先检查基类（15位身份证与出生日期是否匹配）
        if (!COldId::check()) return false;
        
        // 2. 长度检查
        if (strlen(pId18) != 18) return false;
        
        // 3. 检查18位是否从15位扩展而来
        char generated[19];
        generateId18(generated);
        for (int i = 0; i < 18; i++) {
            if (generated[i] != pId18[i]) return false;
        }
        
        // 4. 检查第18位校验码（再次确认）
        char id17[18];
        strncpy(id17, pId18, 17);
        id17[17] = '\0';
        if (pId18[17] != calcCheckCode(id17)) return false;
        
        // 5. 检查非法字符
        for (int i = 0; i < 17; i++) {
            if (!isdigit(pId18[i])) return false;
        }
        char last = pId18[17];
        if (!isdigit(last) && last != 'X' && last != 'x') return false;
        
        // 6. 检查出生日期（从18位中提取）
        int year = (pId18[6] - '0') * 1000 + (pId18[7] - '0') * 100 +
                   (pId18[8] - '0') * 10 + (pId18[9] - '0');
        int month = (pId18[10] - '0') * 10 + (pId18[11] - '0');
        int day = (pId18[12] - '0') * 10 + (pId18[13] - '0');
        CDate birth18(year, month, day);
        if (!birth18.check()) return false;
        
        // 7. 检查输入的出生日期是否与18位中的一致
        CDate& birth = getBirthday();
        if (birth.getYear() != year || birth.getMonth() != month || birth.getDay() != day) return false;
        
        // 8. 检查签发日期
        if (!issueDay.check()) return false;
        
        // 9. 检查有效期（当前日期2021年11月9日）
        CDate current(2021, 11, 9);
        
        // 签发日期不能晚于当前日期
        if (issueDay.getYear() > current.getYear()) return false;
        if (issueDay.getYear() == current.getYear()) {
            if (issueDay.getMonth() > current.getMonth()) return false;
            if (issueDay.getMonth() == current.getMonth() && issueDay.getDay() > current.getDay()) return false;
        }
        
        // 有效期判断
        if (validYear == 100) {
            return true;
        } else {
            int expireYear = issueDay.getYear() + validYear;
            int expireMonth = issueDay.getMonth();
            int expireDay = issueDay.getDay();
            
            if (current.getYear() > expireYear) return false;
            if (current.getYear() == expireYear) {
                if (current.getMonth() > expireMonth) return false;
                if (current.getMonth() == expireMonth && current.getDay() > expireDay) return false;
            }
            return true;
        }
    }
    
    void print() override {
        cout << pName << endl;
        cout << pId18 << " ";
        issueDay.print();
        cout << " ";
        if (validYear == 100) {
            cout << "长期";
        } else {
            cout << validYear << "年";
        }
        cout << endl;
    }
    
    ~CNewId() {
        delete[] pId18;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char name[21];
        int birthYear, birthMonth, birthDay;
        char id15[16];
        char id18[19];
        int issueYear, issueMonth, issueDay;
        int validYear;
        
        cin >> name >> birthYear >> birthMonth >> birthDay >> id15 
            >> id18 >> issueYear >> issueMonth >> issueDay >> validYear;
        
        CDate birth(birthYear, birthMonth, birthDay);
        CDate issue(issueYear, issueMonth, issueDay);
        
        CNewId person(id15, name, birth, id18, issue, validYear);
        
        if (person.check()) {
            person.print();
        } else {
            cout << name << endl;
            cout << "illegal id" << endl;
        }
    }
    
    return 0;
}