#include <iostream>
 
 
using namespace std;
 
class complex {
 
public:
 
    complex();
 
    complex(double r, double i);
 
    friend complex addCom(complex c1, complex c2);
 
    friend complex minusCom(complex c1, complex c2);
 
// Friend function, complex number c1 + c2 (addition of two parameter objects)
 
    friend void outcome(complex c);
 
// Friend function, output relevant data of class object c (c is parameter object 2)
 
private:
 
    double real; // Real part
 
    double imag; // imaginary part
 
};
 
complex::complex() {
 
}
 
complex::complex(double r, double i) {
    real = r;
    imag = i;
 
 
}
 
complex addCom(complex c1, complex c2) {
    complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}
 
complex minusCom(complex c1, complex c2) {
    complex c;
    c.real = c1.real - c2.real;
    c.imag = c1.imag - c2.imag;
    return c;
}
 
void outcome(complex c) {
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}
 
int main() {
    double x, y;
    cin >> x >> y;
    complex a(x, y);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        char o ;
        double rr, ii;
        cin >> o >> rr >> ii;
        complex b(rr, ii);
        if (o == '+') {
            a = addCom(a, b);
        } else{
            a = minusCom(a, b);
        }
        outcome(a);
    }
    return  0;
}
 