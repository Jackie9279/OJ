#include <bits/stdc++.h>

using namespace std;


static int miny;

class Student {
private:
    int y, m, d;
    string name;
    int val = 0;

public:
    Student(int y, int m, int d, const string &name) : y(y), m(m), d(d), name(name) {}

    Student() {}

    void init(int y, int m, int d, const string &name);

    int operator-(Student &s);


    const string &getName() const;
};

void Student::init(int y, int m, int d, const string &name) {
    Student::y = y;
    Student::m = m;
    Student::d = d;
    Student::name = name;
}


const string &Student::getName() const {
    return name;
}

int Student::operator-(Student &s) {
    int t1 = 0, t2 = 0;
    int mon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int non[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        for (int i = 0; i < m - 1; i++) {
            t1 += mon[i];
        }
        t1 += d;
    } else {
        for (int i = 0; i < m - 1; i++) {
            t1 += non[i];
        }
        t1 += d;
    }

    if ((s.y % 4 == 0 && s.y % 100 != 0) || (s.y % 400 == 0)) {
        for (int i = 0; i < s.m - 1; i++) {
            t2 += mon[i];
        }
        t2 += s.d;
    } else {
        for (int i = 0; i < s.m - 1; i++) {
            t2 += non[i];
        }
        t2 += s.d;
    }


    if (y == s.y) {
        t1 -= t2;
        return t1 > 0 ? t1 : -t1;
    } else {
        int max, min;
        if (y > s.y) {
            max = y;
            min = s.y;
            while (max - min) {
                if ((min % 4 == 0 && min % 100 != 0) || (min % 400 == 0)) {
                    t1 += 366;
                } else {
                    t1 += 365;
                }
                min++;
            }
            return t1 - t2;
        } else {
            max = s.y;
            min = y;
            while (max - min) {
                if ((min % 4 == 0 && min % 100 != 0) || (min % 400 == 0)) {
                    t2 += 366;
                } else {
                    t2 += 365;
                }
                min++;
            }
            return t2 - t1;
        }
    }
}


int main() {
    int t;
    cin >> t;
    Student a[t];
    string name;
    int y, m, d;
    int day = 0;
    int max = 0;
    int maxx = 1;
    int minn = 0;
    for (int i = 0; i < t; ++i) {
        cin >> name >> y >> m >> d;
        a[i].init(y, m, d, name);
    }

    for (int i = 0; i < t - 1; i++) {
        for (int j = 1; j < t; j++) {
            day = a[i] - a[j];
            if (day > max) {
                max = day;
                maxx = i;
                minn = j;
            }
        }
    }
    cout << a[maxx].getName() << " and " << a[minn].getName() << " have the biggest age difference, which is " << max
         << " days.";
    return 0;
}
