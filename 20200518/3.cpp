#include <bits/stdc++.h>

using namespace std;


class account {
private:
    long long id;
    string type;
    double balance;
    double rate;
public:
    account(long long int id, const string &type, double balance) : id(id), type(type), balance(balance) {
        rate = 0.005;
    }

    account(account &a);

    long long int getId() const;

    void setId(long long int id);

    const string &getType() const;

    void setType(const string &type);

    double getBalance() const;

    void setBalance(double balance);

    double getRate() const;

    void setRate(double rate);

    void print();

    void query();

};

account::account(account &a) {
    id = a.getId() + 50000000;
    rate = 0.015;
    balance = a.balance;
    type = a.type;
}

long long int account::getId() const {
    return id;
}

void account::setId(long long int id) {
    account::id = id;
}

const string &account::getType() const {
    return type;
}

void account::setType(const string &type) {
    account::type = type;
}

double account::getBalance() const {
    return balance;
}

void account::setBalance(double balance) {
    account::balance = balance;
}

double account::getRate() const {
    return rate;
}

void account::setRate(double rate) {
    account::rate = rate;
}

void account::print() {
    balance += balance * rate;
    cout << "Account=" << id << "--sum=" << balance << endl;
}

void account::query() {
    if (type == "P")
        cout << "Account=" << id << "--Person--sum=" << balance << "--rate=" << rate << endl;
    else
        cout << "Account=" << id << "--Enterprise--sum=" << balance << "--rate=" << rate << endl;
}


int main() {
    int t;
    cin >> t;
    double balance;
    long long id;
    string type;
    string o1, o2;
    for (int i = 0; i < t; ++i) {
        cin >> id >> type >> balance;
        account a(id, type, balance);
        account b(a);
        cin >> o1 >> o2;
        if (o1 == "C") {
            a.print();
        } else {
            a.query();
        }
        if (o2 == "C") {
            b.print();
        } else {
            b.query();
        }

    }
    return 0;
}
