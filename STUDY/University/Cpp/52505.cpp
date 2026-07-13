#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CPeople {
protected:
    char id[20];
    char name[10];
public:
    CPeople() {
        id[0] = '\0';
        name[0] = '\0';
    }
    
    void setId(const char* i) { strcpy(id, i); }
    void setName(const char* n) { strcpy(name, n); }
    char* getId() { return id; }
    char* getName() { return name; }
};

class CInternetUser : virtual public CPeople {
protected:
    char password[20];
public:
    CInternetUser() { password[0] = '\0'; }
    
    void registerUser(const char* n, const char* i, const char* pwd) {
        setName(n);
        setId(i);
        strcpy(password, pwd);
    }
    
    int login(const char* i, const char* pwd) {
        return (strcmp(id, i) == 0 && strcmp(password, pwd) == 0);
    }
};

class CBankCustomer : virtual public CPeople {
protected:
    double balance;
public:
    CBankCustomer() : balance(0) {}
    
    void openAccount(const char* n, const char* i) {
        setName(n);
        setId(i);
    }
    
    int deposit(double money) {
        balance += money;
        return 1;
    }
    
    int withdraw(double money) {
        if (money > balance) return 0;
        balance -= money;
        return 1;
    }
    
    double getBalance() { return balance; }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer {
private:
    double internetBalance;
    double yesterdayInterest;
    
public:
    CInternetBankCustomer() : internetBalance(0), yesterdayInterest(0) {}
    
    int depositToInternet(double money) {
        if (money > getBalance()) return 0;
        CBankCustomer::withdraw(money);
        internetBalance += money;
        return 1;
    }
    
    int withdrawFromInternet(double money) {
        if (money > internetBalance) return 0;
        internetBalance -= money;
        CBankCustomer::deposit(money);
        return 1;
    }
    
    int bankDeposit(double money) { return CBankCustomer::deposit(money); }
    int bankWithdraw(double money) { return CBankCustomer::withdraw(money); }
    
    void setInterest(double interest) {
        yesterdayInterest = interest;
    }
    
    void addProfit() {
        double profit = internetBalance * (yesterdayInterest / 10000.0);
        internetBalance += profit;
    }
    
    void print() {
        cout << "Name: " << getName() << " ID: " << getId() << endl;
        
        // 银行余额输出
        double bankBal = getBalance();
        if (bankBal == (int)bankBal) {
            cout << "Bank balance: " << (int)bankBal << endl;
        } else {
            cout << "Bank balance: " << bankBal << endl;
        }
        
        // 互金余额输出
        if (internetBalance == (int)internetBalance) {
            cout << "Internet bank balance: " << (int)internetBalance << endl;
        } else {
            cout << "Internet bank balance: " << internetBalance << endl;
        }
        cout << endl;
    }
};

int main() {
    int t, no_of_days;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;
    
    cin >> t;
    while (t--) {
        cin >> i_xm >> i_id >> i_mm;
        cin >> b_xm >> b_id;
        cin >> ib_id >> ib_mm;
        
        CInternetBankCustomer ib_user;
        
        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);
        
        if (ib_user.login(ib_id, ib_mm) == 0 ||
            strcmp(ib_user.CBankCustomer::getId(), ib_user.CInternetUser::getId()) != 0 ||
            strcmp(ib_user.CBankCustomer::getName(), ib_user.CInternetUser::getName()) != 0) {
            cout << "Password or ID incorrect" << endl;
            continue;
        }
        
        cin >> no_of_days;
        for (int i = 0; i < no_of_days; i++) {
            cin >> op_code >> money >> interest;
            
            ib_user.addProfit();
            
            switch (op_code) {
                case 'S': case 's':
                    if (ib_user.depositToInternet(money) == 0) {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'T': case 't':
                    if (ib_user.withdrawFromInternet(money) == 0) {
                        cout << "Internet bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'D': case 'd':
                    ib_user.bankDeposit(money);
                    break;
                case 'W': case 'w':
                    if (ib_user.bankWithdraw(money) == 0) {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                default:
                    cout << "Illegal input" << endl;
                    continue;
            }
            
            ib_user.setInterest(interest);
            ib_user.print();
        }
    }
    
    return 0;
}