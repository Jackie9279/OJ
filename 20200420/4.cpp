#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;
class Date
{
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

Date::Date(/* args */)
{
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::set(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

Date::~Date()
{
}

class IDCard
{
private:
    int type;
    string id;
    Date birth;

public:
    IDCard(/* args */);
    IDCard(int atype, string aid, int y, int m, int d);
    IDCard(IDCard &i);
    void print();
    void gradeup();
    ~IDCard();
};

IDCard::IDCard(/* args */)
{
}

IDCard::IDCard(int atype, string aid, int y, int m, int d)
{
    type = atype;
    id = aid;
    birth.set(y, m, d);
}
IDCard::IDCard(IDCard &i)
{
    type = 2;
    id = i.id;
    birth = i.birth;
    gradeup();
}

void IDCard::print()
{
    cout << "type=" << type << " "
         << "birth=" << birth.getYear() << "." << setw(2) << setfill('0')<< birth.getMonth() << "." << setw(2) << setfill('0')<< birth.getDay() << endl;
    cout << "ID=" << id << endl;
}

void IDCard::gradeup()
{
    if (id.length() == 15)
    {

        id.insert(6, to_string(birth.getYear() / 100 % 10));
        id.insert(6, to_string(birth.getYear() / 1000 % 10));

        int sum = 0;
        for (char i : id)
        {
            int num = i - '0';
            sum += num;
        }
        if (sum % 10 == 0)
        {
            id = id + "X";
        }
        else
        {
            id = id + to_string(sum % 10);
        }
    }
}

IDCard::~IDCard()
{
}

int main()
{
    int t;
    cin >> t;
    int type, y, m, d;
    string id;
    for (size_t i = 0; i < t; i++)
    {
        cin >> type >> id >> y >> m >> d;
        IDCard i1(type, id, y, m, d);
        IDCard i2(i1);
        i2.print();
    }

    return 0;
}