#include <iostream>
#include <iomanip>

bool isleap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int Dayofmonth(int year, int month)
{
    return 31 - ((month == 2) ? (3 - isleap(year)) : ((month - 1) % 7 % 2));
}

using namespace std;
class Date
{
private:
    int year, month, day;

public:
    Date(); //Default constructor, assign year, month, and day values to 1900, 1, and 1, respectively//

    Date(int y, int m, int d); //Constructor with parameters, assign values to year, month, and day, respectively//

    int getYear(); //Returns the year of the current date

    int getMonth(); //Returns the month of the current date

    int getDay(); //Returns the day of the current date

    void setDate(int y, int m, int d); //Reset date by parameter

    void print(); //Output year, month, and day of the current date in format

    void addOneDay(); //Add one day to the current date
};

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int y, int m, int d)
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

void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::print()
{
    cout << "Today is " << getYear() << "/" << setw(3) << setfill('0') << getMonth() << "/" << getDay() << endl;
    addOneDay();
    cout << "Tomorrow  is " << getYear() << "/" << setw(3) << setfill('0') << getMonth() << "/" << getDay() << endl;
}

void Date::addOneDay()
{
    day++;
    if (day > Dayofmonth(year, month))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

int main()
{
    int t;
    Date a[100];
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int y, m, d;
        cin >> y >> m >> d;
        a[i].setDate(y, m, d);
        a[i].print();
    }

    return 0;
}