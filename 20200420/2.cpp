#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class CDate
{
private:
    int year{}, month{}, day{};

public:
    CDate();
    CDate(CDate &a)
    {
        year = a.year;
        month = a.month;
        day = a.day;
    }
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear() // Calculate the number of days from January 1 of the year
    {
        int i, sum = day;
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear())
            for (i = 0; i < month; i++)
                sum += b[i];
        else
            for (i = 0; i < month; i++)
                sum += a[i];
        return sum;
    }
    void set(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
};

CDate::CDate() {

}

class software
{
private:
    string name;
    string type;
    CDate date;
    string media;
    unordered_map<string, string> T;
    unordered_map<string, string> M;

public:
    software(/* args */);
    software(string aname, string atype, string amedia, int ayear, int amonth, int aday);
    software(software &s);
    void print();
    ~software();
};

software::software(/* args */)
{
}
software::software(string aname, string atype, string amedia, int ayear, int amonth, int aday)
{
    name = aname;
    type = atype;
    media = amedia;
    date.set(ayear, amonth, aday);
    T.insert(pair<string, string>("O", "type:original"));
    T.insert(pair<string, string>("T", "type:trial"));
    T.insert(pair<string, string>("B", "type:backup"));
    M.insert(pair<string, string>("D", "media:optical disk"));
    M.insert(pair<string, string>("H", "media:hard disk"));
    M.insert(pair<string, string>("U", "media:USB disk"));
}

software::~software()
{
}

void software::print()
{
    cout << "name:" << name << endl;
    cout << T[type] << endl;
    cout << M[media] << endl;
    if (date.getDay() == 0 && date.getMonth() == 0 && date.getYear() == 0)
    {
        cout << "this software has unlimited use" << endl;
    }
    else if ((date.getYear() >= 2015 && date.getMonth() >= 4 && date.getDay() >= 7) || (date.getYear() >= 2015 && date.getMonth() > 4))
    {
        cout << "this software is going to be expired in " << date.getDayofYear() - 97 << " days" << endl;
    }
    else
    {
        cout << "this software has expired" << endl;
    }
}

software::software(software &s)
{
    name = s.name;
    type = "B";
    media = "H";
    CDate cd(s.date);
    date = cd;
    T.insert(pair<string, string>("O", "type:original"));
    T.insert(pair<string, string>("T", "type:trial"));
    T.insert(pair<string, string>("B", "type:backup"));
    M.insert(pair<string, string>("D", "media:optical disk"));
    M.insert(pair<string, string>("H", "media:hard disk"));
    M.insert(pair<string, string>("U", "media:USB disk"));

}
int main()
{
    int t;
    cin >> t;
    int y, d, m;
    string name, type, media;
    for (size_t i = 0; i < t; i++)
    {
        cin >> name >> type >> media >> y >> m >> d;
        software a1(name, type, media, y, m, d);
        a1.print();
        cout << endl;
        software a2(a1);
        a2.print();
        cout << endl;
    }
    return 0;
}