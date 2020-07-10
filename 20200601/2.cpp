#include <bits/stdc++.h>

using namespace std;

class Complex {
private:
    float r, i;
public:
    Complex(float r, float i) : r(r), i(i) {}

    Complex() {}

    friend Complex operator+(Complex &a, Complex &b);

    friend Complex operator-(Complex &a, Complex &b);

    friend Complex operator*(Complex &a, Complex &b);

    void show();
};

Complex operator+(Complex &a, Complex &b) {
    Complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
}

Complex operator-(Complex &a, Complex &b) {
    Complex c;
    c.r = a.r - b.r;
    c.i = a.i - b.i;
    return c;
}

Complex operator*(Complex &a, Complex &b) {
    Complex c;
    c.r = a.r * b.r - a.i * b.i;
    c.i = a.i * b.r + a.r * b.i;
    return c;
}

void Complex::show() {
    cout << "Real=" << r << " " << "Image=" << i << endl;

}


int main() {
    float q, p, a, l;
    cin >> q >> p >> a >> l;
    Complex aa(q, p);
    Complex bb(a, l);
    (aa + bb).show();
    (aa - bb).show();
    (aa * bb).show();
    return 0;


}

