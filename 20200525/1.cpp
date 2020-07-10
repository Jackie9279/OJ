#include <bits/stdc++.h>

using namespace std;

class CAccount {
protected:
    long id;
    string name;
    float balance;
public:
    CAccount(long id, const string &name, float balance) : id(id), name(name), balance(balance) {}

    void deposit(float money);

    virtual void withdraw(float money);

    void inquery();
};

void CAccount::deposit(float money) {
    balance += money;
    cout << "saving ok!" << endl;

}

void CAccount::withdraw(float money) {
    if (balance >= money) {
        balance -= money;
        cout << "withdraw ok!" << endl;
    } else {
        cout << "sorry! over balance!" << endl;
    }

}

void CAccount::inquery() {
    cout << "balance is " << balance << endl;
}


class CCreaditcard : public CAccount {
protected:
    float limit;
public:
    CCreaditcard(long id, const string &name, float balance, float limit) : CAccount(id, name, balance),
                                                                            limit(limit) {}

    void withdraw(float money);
};

void CCreaditcard::withdraw(float money) {
    if (balance + limit >= money) {
        balance -= money;
        cout << "withdraw ok!" << endl;
    } else
        cout << "sorry! over limit!" << endl;
}


int main() {
    long id;
    string name;
    float de1, with1, de2, with2;
    float balance;
    float limit;
    cin >> id >> name >> balance >> de1 >> with1;
    CAccount cc(id, name, balance);
    cc.inquery();
    cc.deposit(de1);
    cc.inquery();
    cc.withdraw(with1);
    cc.inquery();
    cin >> id >> name >> balance >> limit >> de2 >> with2;
    CCreaditcard ccc(id, name, balance, limit);
    ccc.inquery();
    ccc.deposit(de2);
    ccc.inquery();
    ccc.withdraw(with2);
    ccc.inquery();
    return 0;
}
