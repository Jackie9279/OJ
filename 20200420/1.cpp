#include <bits/stdc++.h>

using namespace std;

class CTelNumber {
private:
    char *p;

public:
    CTelNumber(/* args */);

    CTelNumber(char *a);

    CTelNumber(CTelNumber &a);

    void print();

    ~CTelNumber();
};

CTelNumber::CTelNumber(/* args */) {
    p = new char[8];
}

CTelNumber::CTelNumber(char *a) {
    p = new char[8];
    strcpy(p, a);
}


CTelNumber::CTelNumber(CTelNumber &a) {
    p = new char[9];
    if (a.p[0] == '2' || a.p[0] == '3' || a.p[0] == '4') {
        p[0] = '8';
    } else {
        p[0] = '2';
    }
    for (size_t i = 0; i < 7; i++) {
        p[i + 1] = a.p[i];
    }
}

void CTelNumber::print() {
    for (size_t i = 0; i < 8; i++) {
        cout << p[i];
    }
    cout << endl;
}

CTelNumber::~CTelNumber() {
    delete p;
}

bool check(char *p) {
    for (size_t i = 1; i < 7; i++) {
        if (p[i] > '9' || p[i] < '0') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    char *a;
    for (size_t i = 0; i < t; i++) {
        a = new char[8];
        cin >> a;
        if (check(a)) {
            if (strlen(a) == 7) {
                if (a[0] >= '2' && a[0] <= '8') {
                    CTelNumber c1(a);
                    CTelNumber c2(c1);
                    c2.print();
                } else {
                    cout << "Illegal phone number" << endl;
                }
            }

        } else {
            cout << "Illegal phone number" << endl;
        }
    }
    return 0;
}