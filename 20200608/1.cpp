#include <bits/stdc++.h>

using namespace std;

class point {
private:
    int x, y, z;
public:
    point(int x, int y, int z) : x(x), y(y), z(z) {}

    point() {
        x = 0;
        y = 0;
        z = 0;
    }

    void setX(int x);

    void setY(int y);

    void setZ(int z);

    friend point operator++(point &a);

    friend point operator++(point &a, int);

    friend point operator--(point &a);

    friend point operator--(point &a, int);

    void show();


};

void point::show() {
    cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
}

point operator++(point &a) {
    a.x++;
    a.y++;
    a.z++;
    return a;
}

point operator++(point &a, int) {
    point b(a);
    a.x++;
    a.y++;
    a.z++;
    return b;
}

point operator--(point &a) {
    a.x--;
    a.y--;
    a.z--;
    return a;
}

point operator--(point &a, int) {
    point b(a);
    a.x--;
    a.y--;
    a.z--;
    return b;
}


int main() {
    int x, y, z;
    cin >> x >> y >> z;

    point a(x, y, z);
    point aa(x, y, z);
    point aaa(x, y, z);
    point aaaa(x, y, z);
    point aaaaa(x, y, z);
    point b;
    a++;
    a.show();
    b = aa++;
    b.show();
    (++aaa).show();
    aaa.show();
    aaaa--;
    aaaa.show();
    aaaaa.show();
    (--aaaaa).show();
    aaaaa.show();

    return 0;


}
