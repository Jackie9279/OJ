#include <bits/stdc++.h>

using namespace std;

class Bankaacount
{
private:
    int id;
    string phone_number;
    int password;
    double balance;

public:
    Bankaacount(/* args */);
    void create(int aid, string phone_number, int password, double balance);
    int get_id();
    string get_phonenumber();
    double get_balance();
    bool checkpassword(int code);
    void withdrawal(double money);
    ~Bankaacount();
};
void Bankaacount::create(int aid, string aphone_number, int apassword, double abalance)
{
    id = aid;
    phone_number = aphone_number;
    password = apassword;
    balance = abalance;
}

int Bankaacount::get_id()
{
    return id;
}

string Bankaacount::get_phonenumber()
{
    return phone_number;
}

double Bankaacount::get_balance()
{
    return balance;
}

bool Bankaacount::checkpassword(int code)
{
    if (code == password)
    {
        return true;
    }
    return false;
}

void Bankaacount::withdrawal(double money)
{
    if (balance < money)
    {
        cout << "Card number" << id << "--Insufficient balance" << endl;
    }
    else
    {
        balance -= money;
        cout << "Card number" << id << "--Balance" << balance << endl;
    }
}

Bankaacount::Bankaacount()
{
}

Bankaacount::~Bankaacount()
{
}

int main()
{
    int t;
    cin >> t;
    Bankaacount a[100];
    for (size_t i = 0; i < t; i++)
    {
        int id;
        string phone_number;
        int password;
        double balance;
        cin >> id >> phone_number >> password >> balance;
        a[i].create(id, phone_number, password, balance);
    }

    int y;
    cin >> y;
    for (size_t i = 0; i < y; i++)
    {
        string phone_number;
        int password;
        double wananmoney;
        cin >> phone_number >> password >> wananmoney;
        int ok = 0;
        for (size_t i = 0; i < t; i++)
        {
            ok = 0;
            string aaphone_number = a[i].get_phonenumber();
            if (aaphone_number == phone_number)
            {
                ok = 1;
                if (a[i].checkpassword(password))
                {
                    a[i].withdrawal(wananmoney);
                    break;
                }
                else
                {
                    cout << "Password is wrong" << endl;
                    break;
                }
            }
        }
        if (ok == 0)
        {
            cout << "Mobile phone number does not exist" << endl;
        }
    }
}
