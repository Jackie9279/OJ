#include <bits/stdc++.h>

using namespace std;


class Clock {
private:
    int h, m, s;
public:
    Clock(int h, int m, int s) : h(h), m(m), s(s) {}

    Clock() {}

    friend Clock operator++(Clock &a);

    friend Clock operator--(Clock &a, int);

    void update();

    void show();

};

Clock operator++(Clock &a) {
    a.s += 1;
    a.update();
    return a;
}

void Clock::update() {
    if (s >= 60) {
        s -= 60;
        m++;
        if (m >= 60) {
            m -= 60;
            h++;
            if (h >= 12) {
                h -= 12;
            }
        }
    }

    if (s < 0) {
        s += 60;
        m--;
        if (m < 0) {
            m += 60;
            h--;
            if (h < 0) {
                h += 12;
            }
        }
    }
}

void Clock::show() {
    cout << h << ":" << m << ":" << s << endl;
}

Clock operator--(Clock &a, int) {
    Clock b=a;
    a.s -= 1;
    a.update();
    return b;
}

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    Clock c(h, m, s);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        if (n > 0) {
            for (int j = 0; j < n; ++j) {
                c = ++c;
            }
            c.show();
        } else {
            for (int j = 0; j < -n; ++j) {
                c--;
            }
            c.show();
        }
    }
}



