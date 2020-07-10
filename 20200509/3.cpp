#include <bits/stdc++.h>

#include <utility>

using namespace std;

class CDate {

private:

    int year, month, day;

public:

    CDate(int year, int month, int day) : year(year), month(month), day(day) {}

    CDate();

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    bool check(); //检验日期是否合法


    bool isLeap(int year);

    int Dayofmonth(int year, int month);

};

bool CDate::check() {
    if (year >= 0 && year <= 2020) {
        if (month >= 1 && month <= 12) {
            if (day >= 1 && day <= Dayofmonth(year, month)) {
                return true;
            }
        }
    }
    return false;
}

bool CDate::isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int CDate::Dayofmonth(int year, int month) {
    return 31 - ((month == 2) ? (3 - isLeap(year)) : ((month - 1) % 7 % 2));
}

CDate::CDate() {}

class COldID {


public:
    string p_id15, p_name; //15位身份证号码，姓名
    CDate birthday; //出生日期
    COldID(string p_idval, string p_nameval, CDate &day);

    COldID();

    virtual bool check() = 0; //验证15位身份证是否合法
    virtual void print() = 0;


};

COldID::COldID(string p_idval, string p_nameval, CDate &day) {
    p_id15 = std::move(p_idval);
    p_name = std::move(p_nameval);
    birthday = day;
}

COldID::COldID() {}


class CNewID : public COldID {

public:
    string p_id18;
    CDate qianfa;
    int vaild;

    CNewID(const string &pIdval, const string &pNameval, CDate &day, const string &pId18, const CDate &qianfa,
           int vaild);

    bool check() override;

    bool checkk();      //有效期验证

    void print() override;

    bool birthdaycheck();


};

bool CNewID::check() {
    string newid18 = p_id15;
    if (p_id15.length() == 15) {
        newid18.insert(6, to_string(birthday.getYear() / 100 % 10));
        newid18.insert(6, to_string(birthday.getYear() / 1000 % 10));
        int sum = 0;
        int t = 0;
        int xishu[]{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        string jiaoyanma = "10X98765432";
        for (char i : newid18) {
            int num = i - '0';
            sum += num * xishu[t];
            t++;
        }
        char num18 = jiaoyanma[sum % 11];
        newid18 += num18;

    }
    for(auto j:p_id18)
    {
        if(!isdigit(j))
        {
            return false;
        }
    }
    return p_id18.length() == 18 && newid18 == p_id18 && checkk();
}

bool CNewID::checkk() {
    return qianfa.getYear() + vaild >= 2020;
}


void CNewID::print() {
    if (vaild == 100) {
        cout << p_name << endl << p_id18 << " "<<qianfa.getMonth()<<"/"<<qianfa.getDay()<<"/"<<qianfa.getYear()<<" Long-term"<< endl;
    } else {
        cout << p_name << endl << p_id18 << " "<<qianfa.getMonth()<<"/"<<qianfa.getDay()<<"/"<<qianfa.getYear()<<" "<<vaild<<"-year"<< endl;
    }
}

CNewID::CNewID(const string &pIdval, const string &pNameval, CDate &day, const string &pId18, const CDate &qianfa,
               int vaild) : COldID(pIdval, pNameval, day), p_id18(pId18), qianfa(qianfa), vaild(vaild) {}

bool CNewID::birthdaycheck() {
    return stoi(p_id18.substr(6, 4)) == birthday.getYear() &&
           stoi(p_id18.substr(10, 2)) == birthday.getMonth() &&
           stoi(p_id18.substr(12, 2)) == birthday.getDay();
}


int main() {
    int t;
    cin >> t;
    string name, id15, id18;
    int y1, m1, d1, y2, m2, d2, vaild;
    for (int i = 0; i < t; ++i) {
        cin >> name >> y1 >> m1 >> d1 >> id15 >> id18 >> y2 >> m2 >> d2 >> vaild;
        CDate dd1(y1, m1, d1);
        CDate dd2(y2, m2, d2);
        CNewID p(id15, name, dd1, id18, dd2, vaild);
        if (p.qianfa.check() && p.birthday.check() && p.check() && p.birthdaycheck()) {
            p.print();
        } else {
            cout << p.p_name << endl << "illegal id" << endl;
        }
    }
    return 0;
}