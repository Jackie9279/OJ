#include <bits/stdc++.h>
 
using namespace std;
 
class Account {
private:
    static int count;
    static float InterestRate;
    string _accno, _accname;
    float _balance;
 
public:
    Account(string accno, string name, float balance);
 
    ~Account();
 
    void Deposit(float amount);//存款
    void Withdraw(float amount);//取款
    float GetBalance();//获取账户余额
    void show(float deamount, float wiamount);//显示账户所有基本信息
    static int GetCount();//获取账户数
    static float GetInterestRate();//获取利率
    friend void Update(Account &a);
 
    static void SetInterestRate(float rate);
 
};
 
int Account::count=0;
float Account::InterestRate = 0;
 
Account::Account(string accno, string name, float balance) {
    _accno = accno;
    _accname = name;
    _balance = balance;
    count++;
 
}
 
Account::~Account() {
    count--;
}
 
void Account::Deposit(float amount) {
    _balance += amount;
}
 
void Account::Withdraw(float amount) {
    _balance -= amount;
}
 
float Account::GetBalance() {
    return _balance;
}
 
int Account::GetCount() {
    return count;
}
 
float Account::GetInterestRate() {
    return InterestRate;
}
 
void Update(Account &a) {
    a._balance += a._balance * Account::InterestRate;
}
 
void Account::SetInterestRate(float rate) {
    Account::InterestRate = rate;
}
 
void Account::show(float deamount, float wiamount) {
    Deposit(deamount);
    cout << _accno << " " << _accname << " " << _balance << " ";
    Update(*this);
    cout << _balance << " ";
    Withdraw(wiamount);
    cout << _balance << endl;
}
 
int main() {
    int t;
    string accno, accname;
    float interestrate, balance, withdraw, deposit;
    float sum = 0;
    cin >> interestrate;
    Account::SetInterestRate(interestrate);
    Account **a = new Account *[100];
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> accno >> accname >> balance >> deposit >> withdraw;
        a[i] = new Account(accno, accname, balance);
        a[i]->show(deposit, withdraw);
        sum += a[i]->GetBalance();
        delete a[i];
    }
    cout << sum << endl;
    delete[]a;
    return 0;
}