#include <bits/stdc++.h>

using namespace std;

class rmb {
private:
    int y, j, f;
public:
    rmb(int y, int j, int f) : y(y), j(j), f(f) {}

    rmb() {}

    void show();

};

void rmb::show() {
    cout << "yuan=" << y << " jiao=" << j << " fen=" << f << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        double q;
        cin >> q;
        q+=0.0004;
        int qq = (int)(q * 100);
        int y, j, f;
        y = qq / 100 % 10;
        j = qq / 10 % 10;
        f = qq % 10;
        rmb r(y, j, f);
        r.show();
    }
    return 0;
}