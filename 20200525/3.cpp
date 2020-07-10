#include <iostream>

using namespace std;

class Cpeople {
protected:
    string id, name;
public:
    Cpeople(const string &id, const string &name) : id(id), name(name) {}

    Cpeople() {}
};

class CInternetUser : virtual public Cpeople {
protected:
    string password;
public:
    CInternetUser();

    bool login(const string &id, const string &password);

    void registerUser(string i_xm, string i_id, string i_mm) {
        name = i_xm;
        id = i_id;
        password = i_mm;
    }
};

bool CInternetUser::login(const string &id, const string &password) {
    return CInternetUser::id == id && CInternetUser::password == password;
}

CInternetUser::CInternetUser() {}

class CBankCustomer : public virtual Cpeople {
protected:
    double balance;
public:
    CBankCustomer() : balance(0) {}

    void openAccount(string b_xm, string b_id) {
        name = b_xm;
        id = b_id;
    }

    void deposit(double money) {
        balance += money;
    }

    int withdraw(double money) {
        if (money > balance)
            return 0;
        else
            balance -= money;
        return balance;
    }
};

class CInternetBankCustomer : virtual public CInternetUser, virtual public CBankCustomer {
protected:
    double interbalance, prebalance, curinterest, preinterest, preincome;
public:
    void setInterest(double interest);

    void up();

    void print();

    int deposit(double money) {
        if (balance < money)
            return 0;
        else {
            interbalance += money;
            balance -= money;
            return 1;
        }
    }

    int withdraw(double money) {
        if (money > interbalance)
            return 0;
        else {
            interbalance -= money;
            balance += money;
            return 1;
        }
    }

    CInternetBankCustomer();

};

void CInternetBankCustomer::setInterest(double interest) {
    curinterest = interest / 10000;
}

void CInternetBankCustomer::up() {
    preincome = prebalance * preinterest;
    interbalance += preincome;
    prebalance = interbalance;
    preinterest = curinterest;
}

void CInternetBankCustomer::print() {
    cout << "Name: " << name << " ID: " << id << endl;
    cout << "Bank balance: " << balance << endl;
    cout << "Internet bank balance: " << CInternetBankCustomer::interbalance << endl << endl;
}


CInternetBankCustomer::CInternetBankCustomer() {
    interbalance = 0;
    prebalance = 0;
    preincome = 0;
}


int main() {
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;
    cin >> t;
    while (t--) {
        //输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;
        //输入银行开户用户名,id
        cin >> b_xm >> b_id;
        //输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++) {
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
                case 'S': //从银行向互联网金融账户存入
                case 's':
                    if (ib_user.deposit(money) == 0)
                    {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'T': //从互联网金融转入银行账户
                case 't':
                    if (ib_user.withdraw(money) == 0)
                    {
                        cout << "Internet bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'D': //直接向银行账户存款
                case 'd':
                    ib_user.CBankCustomer::deposit(money);
                    break;
                case 'W': //直接从银行账户取款
                case 'w':
                    if (ib_user.CBankCustomer::withdraw(money) == 0)
                    {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                default:
                    cout << "Illegal input" << endl;
                    continue;
            }
            ib_user.setInterest(interest);
            ib_user.up();
            ib_user.print();
        }
    }

}