#include <bits/stdc++.h>

using namespace std;

class Date {
private:
    int year, month, day;

public:
    Date(/* args */);

    Date(int y, int m, int d);

    void set(int y, int m, int d);

    int getYear();

    int getMonth();

    int getDay();

    ~Date();
};

Date::Date(/* args */) {
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

void Date::set(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

Date::~Date() {
}

class phone {
private:
    string type;
    string num;
    int state{};
    Date *stopdate{};
    unordered_map<string, string> T;
    unordered_map<int, string> S;

public:
    phone(/* args */);

    phone(string atype, string anum, int astate);

    phone(phone &p);

    void stop(Date &d);

    void print();

    ~phone();
};

phone::phone(/* args */) {
}

phone::phone(string atype, string anum, int astate) {
    type = atype;
    num = anum;
    state = astate;
    stopdate = nullptr;
    T.insert(pair<string, string>("A", "Type=Mechanism"));
    T.insert(pair<string, string>("B", "Type=Enterprise"));
    T.insert(pair<string, string>("C", "Type=Individual"));
    S.insert(pair<int, string>(1, "||State=In use"));
    S.insert(pair<int, string>(2, "||State=Unused"));
    S.insert(pair<int, string>(3, "||State=Discontinue use ||Downtime date="));
    cout << "Construct a new phone " << num << endl;
}

phone::phone(phone &p) {
    stopdate = nullptr;
    num = p.num;
    state = p.state;
    cout << "Construct a copy of phone " << num<<endl;
    num=num+"X";
    type="D";
    T.insert(pair<string, string>("D", "Type=Backups"));
    S.insert(pair<int, string>(1, "||State=In use"));
    S.insert(pair<int, string>(2, "||State=Unused"));
    S.insert(pair<int, string>(3, "||State=Discontinue use ||Downtime date="));
}

void phone::stop(Date &d) {
    state = 3;
    stopdate = new Date(d.getYear(), d.getMonth(), d.getDay());
    cout << "Stop the phone " << num << endl;
}

void phone::print() {
    if (state == 3) {
        cout << T[type] << "||Number=" << num << S[state] << stopdate->getYear() << "." << stopdate->getMonth() << "."
             << stopdate->getDay() << endl;
    } else{
        cout << T[type] << "||Number=" << num << S[state] << endl;
    }
}

phone::~phone() {
    delete stopdate;
}

int main() {
    int t;
    int y, m, d;
    int state;
    string num;
    string type;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        cin >> type >> num >> state >> y >> m >> d;
        phone a1(type, num, state);
        Date d1(y, m, d);
        a1.print();
        phone a2(a1);
        a2.print();
        a1.stop(d1);
        a1.print();
        cout << "----" << endl;
    }
    return 0;
}