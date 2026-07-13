#include <iostream>
#include <string>
using namespace std;

// 旅程会员卡类
class TravelCard {
protected:
    int travelId;      
    int travelPoints;  
public:
    TravelCard(int id = 0) : travelId(id), travelPoints(0) {}
    
    void addTravelPoints(int points) {
        travelPoints += points;
    }
    
    int getTravelId() const { return travelId; }
    int getTravelPoints() const { return travelPoints; }
};

// 信用卡类
class CreditCard {
protected:
    int cardId;           
    string name;          
    int limit;            // 额度（int）
    float bill;           // 账单金额（float）
    int creditPoints;     // 信用卡积分（int）
public:
    CreditCard(int id = 0, string n = "", int lim = 0) 
        : cardId(id), name(n), limit(lim), bill(0), creditPoints(0) {}
    
    // 信用卡消费
    bool consume(float money) {
        if (money > limit) return false;
        bill += money;
        limit -= money;
        creditPoints += (int)money;  // 转int
        return true;
    }
    
    // 信用卡退款
    void refund(float money) {
        bill -= money;
        creditPoints -= (int)money;   // 转int
    }
    
    // 旅程网下单（由派生类调用这些方法来更新）
    void addBill(float money) {
        bill += money;
    }
    
    void subLimit(float money) {
        limit -= money;
    }
    
    void addCreditPoints(int points) {
        creditPoints += points;
    }
    
    // 积分兑换
    void exchangePoints(int points) {
        if (points <= creditPoints) {
            creditPoints -= points;
        }
    }
    
    int getCardId() const { return cardId; }
    string getName() const { return name; }
    float getBill() const { return bill; }
    int getCreditPoints() const { return creditPoints; }
    int getLimit() const { return limit; }
};

// 旅程信用卡类（多重继承）
class TravelCreditCard : public TravelCard, public CreditCard {
public:
    TravelCreditCard(int tId, int cId, string n, int lim) 
        : TravelCard(tId), CreditCard(cId, n, lim) {}
    
    // 旅程网下订单
    void order(float money) {
        // 旅程积分增加
        addTravelPoints((int)money);
        // 信用卡积分增加
        addCreditPoints((int)money);
        // 账单金额增加
        addBill(money);
        // 额度减少
        subLimit(money);
    }
    
    // 信用卡消费
    void consume(float money) {
        CreditCard::consume(money);
    }
    
    // 信用卡退款
    void refund(float money) {
        CreditCard::refund(money);
    }
    
    // 积分兑换：将信用卡积分兑换为旅程积分（1:2比例）
    void exchange(int points) {
        if (points <= getCreditPoints()) {
            // 减少信用卡积分
            exchangePoints(points);
            // 增加旅程积分（1:2比例，所以乘以2）
            addTravelPoints(points * 2);
        }
    }
    
    void print() {
        cout << getTravelId() << " " << getTravelPoints() << endl;
        cout << getCardId() << " " << getName() << " ";
        printf("%.1f", getBill());  // 保留一位小数
        cout << " " << getCreditPoints() << endl;
    }
};

int main() {
    int travelId, cardId, limit;
    string name;
    cin >> travelId >> cardId >> name >> limit;
    
    TravelCreditCard tcc(travelId, cardId, name, limit);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char op;
        float money;
        cin >> op >> money;
        
        switch(op) {
            case 'o':  // 下单
                tcc.order(money);
                break;
            case 'c':  // 消费
                tcc.consume(money);
                break;
            case 'q':  // 退款
                tcc.refund(money);
                break;
            case 't':  // 积分兑换
                tcc.exchange((int)money);
                break;
        }
    }
    
    tcc.print();
    
    return 0;
}