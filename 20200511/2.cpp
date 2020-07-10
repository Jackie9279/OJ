#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class BaseAccount {
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount() {}

    BaseAccount(const string &name, const string &account, double balance) : name(name), account(account),
                                                                             balance(balance) {}

    virtual void deposit(double x);

    virtual void withdraw(double x);

    virtual void display();

};

void BaseAccount::deposit(double x) {
    balance += x;
}

void BaseAccount::withdraw(double x) {
    if (balance < x) {
        cout << "insufficient" << endl;
    } else {
        balance -= x;
    }
}

void BaseAccount::display() {
    cout << name << " " << account << " " << "Balance:" << balance << endl;

}

class BasePuls : public BaseAccount {
private:
    double limit;
    double limit_sum;
public:
    BasePuls() {
        limit = 5000;
        limit_sum = 0;
    }

    BasePuls(const string &name, const string &account, double balance) : BaseAccount(name, account, balance) {
        limit = 5000;
        limit_sum = 0;
    }

    void deposit(double x) override;

    void withdraw(double x) override;

    void display() override;

};

void BasePuls::deposit(double x) {
    if (limit_sum > 0) {
        if (limit_sum >= x) {
            limit_sum -= x;
            x = 0;
        } else {
            x -= limit_sum;
            limit_sum = 0;
        }
    }
    balance += x;
}

void BasePuls::withdraw(double x) {
    if (balance >= x) {
        balance -= x;
    } else if (balance + limit - limit_sum >= x) {
        limit_sum += x - balance;
        balance = 0;
    } else {
        cout << "insufficient" << endl;
    }
}

void BasePuls::display() {
    cout << name << " " << account << " " << "Balance:" << balance << " limit:" << limit - limit_sum << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string name, account;
        double balance;
        double d1, w1, d2, w2;
        cin >> name >> account >> balance >> d1 >> w1 >> d2 >> w2;
        BaseAccount *p;
        if (account[1] == 'A') {
            BaseAccount a(name, account, balance);
            p = &a;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->display();
        } else {
            BasePuls a(name, account, balance);
            p = &a;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->display();
        }
    }
    return 0;
}

