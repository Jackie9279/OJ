#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

int findsec(vector<int> a)
{
    sort(a.begin(), a.end());
    return a[1];
}
int main()
{
    int t;
    Date stu[100];
    vector<int> days;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> stu[i].year >> stu[i].month >> stu[i].day;
        days.push_back(stu[i].year * 365 + stu[i].month * 30 + stu[i].day);
    }
    if (t == 1)
    {
        cout << stu[0].year << "-" << stu[0].month << "-" << stu[0].day;
        return 0;
    }
    vector<int>::iterator it;
    it = find(days.begin(), days.end(), findsec(days));
    int res = it - days.begin();
    cout << stu[res].year << "-" << stu[res].month << "-" << stu[res].day;
    return 0;
}