#include <bits/stdc++.h>

using namespace std;

class Fraction {

    int numerator, denominator;

    int common_divisor(); // Calculate the greatest common divisor

    void contracted(); // Simplification of fractions

public:

    Fraction();

    Fraction(int numerator, int denominator);

    Fraction operator+(Fraction b);

    Fraction operator-(Fraction b);

    Fraction operator*(Fraction b);

    Fraction operator/(Fraction b);

    void Set(int = 0, int = 1);

    void disp();

};

Fraction Fraction::operator+(Fraction b) {
    Fraction a;
    a.denominator = b.denominator * denominator;
    a.numerator = numerator * b.denominator + b.numerator * denominator;
    return a;
}

Fraction Fraction::operator-(Fraction b) {
    Fraction a;
    a.denominator = b.denominator * denominator;
    a.numerator = numerator * b.denominator - b.numerator * denominator;
    return a;
}

Fraction Fraction::operator*(Fraction b) {
    Fraction a;
    a.denominator = b.denominator * denominator;
    a.numerator = numerator * b.numerator;
    return a;
}

Fraction Fraction::operator/(Fraction b) {
    Fraction a;
    a.denominator = b.numerator * denominator;
    a.numerator = b.denominator * numerator;
    return a;
}

void Fraction::disp() {
    cout << "fraction=" << numerator << "/" << denominator << endl;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

Fraction::Fraction() {}

int main() {
    int p, l, o, k;
    cin >> p >> l >> o >> k;
    Fraction a(p, l);
    Fraction b(o, k);
    (a + b).disp();
    (a - b).disp();
    (a * b).disp();
    (a / b).disp();
    return 0;
}




