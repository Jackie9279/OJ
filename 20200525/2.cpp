#include <bits/stdc++.h>

using namespace std;

class counter {
protected:
    int value;
public:
    counter(int value) : value(value) {}

    counter() {
        value = 0;
    }

    int getValue() const;

    virtual int increment();
};

int counter::increment() {
    return value++;
}

int counter::getValue() const {
    return value;
}

class loopcounter : public counter {
protected:
    int min;
    int max;
public:
    loopcounter() {}

    loopcounter(int value, int min, int max) : counter(value), min(min), max(max) {}

    int increment();

};

int loopcounter::increment() {
    if (++value >= max) {
        value -= max - min;
    }
    return value;
}


class Clock {
private:
    loopcounter h, m, s;
public:
    Clock() {}

    Clock(const loopcounter &h, const loopcounter &m, const loopcounter &s) : h(h), m(m), s(s) {}

    void time(int s);

};

void Clock::time(int x) {
    while (x--) {
        if (s.increment() == 0) {
            if (m.increment() == 0) {
                h.increment();
            }
        }
    }
    cout << h.getValue() << ':' << m.getValue() << ':' << s.getValue() << endl;
}




int main() {
    int t,h,m,s,second;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        cin>>h>>m>>s>>second;
        loopcounter hh(h,0,24);
        loopcounter mm(m,0,60);
        loopcounter ss(s,0,60);
        Clock c(hh,mm,ss);
        c.time(second);
    }
    return 0;
}
