#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class solve {
private:
    double a, b, c, delta;
    double r1, r2;

public:
    solve();

    void set_abc(double a1, double b1, double c1);

    void getroot();

    ~solve();
};

solve::~solve() {

}

solve::solve(/* args */) {
    a = 1;
    b = 1;
    c = 0;
    delta = b * b - 4 * a * c;
}

void solve::set_abc(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
    delta = b * b - 4 * a * c;

}

void solve::getroot() {
    if (delta > 0) {
        r1 = (-b + sqrt(delta)) / (2 * a);
        r2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1=" << fixed << setprecision(2) << r1 << " x2=" << r2;
        return;
    } else if (delta == 0) {
        r1 = (-b + sqrt(delta)) / (2 * a);
        r2 = r1;
        cout << fixed << setprecision(2) << "x1=x2=" << r1;
        return;
    } else if (delta < 0) {
        double xu = sqrt(fabs(delta)) / (2 * a);
        cout << "x1=" << fixed << setprecision(2) << (-b) / (2 * a) << "+" << xu << "i" << " ";
        cout << "x2=" << fixed << setprecision(2) << (-b) / (2 * a) << "-" << xu << "i";
        return;
    }
}

int main() {
    int t;
    solve res[100];
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        res[i].set_abc(a, b, c);
        res[i].getroot();
        if (i != t - 1) {
            cout << endl;
        }
    }
    return 0;
}