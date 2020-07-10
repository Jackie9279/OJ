#include <bits/stdc++.h>

using namespace std;

class complex_number
{
private:
public:
    double real;
    double imagin;
    complex_number(/* args */);
    void set_val(double areal, double aimagin);
    complex_number plus(complex_number &a2);
    complex_number sub(complex_number &a2);
    void pprint();
    void sprint();
    ~complex_number();
};


void complex_number::sprint()
{
    if (real == 0 && imagin == 0)
    {
        cout << "0" << endl;
        return;
    }
    if (real == 0)
    {
        cout << imagin << "i" << endl;
    }
    else if (imagin == 0)
    {
        cout << real << endl;
    }
    else
    {
        if (imagin < 0 && imagin != -1)
        {
            cout << real << imagin << "i" << endl;
        }
        else if (imagin == 1)
        {
            cout << real << "+"
                 << "i" << endl;
        }
        else if (imagin == -1)
        {
            cout << real << "i" << endl;
        }
        else
        {
            cout << real << "+" << imagin << "i" << endl;
        }
    }
}

complex_number::complex_number(/* args */)
{
    real = 1;
    imagin = 1;
}

void complex_number::set_val(double areal, double aimagin)
{
    real = areal;
    imagin = aimagin;
}
complex_number complex_number::plus(complex_number &a2)
{
    complex_number a;
    a.real = real + a2.real;
    a.imagin = imagin + a2.imagin;
    return a;
}
complex_number complex_number::sub(complex_number &a2)
{
    complex_number a;
    a.real = real - a2.real;
    a.imagin = imagin - a2.imagin;
    return a;
}

complex_number::~complex_number()
{
}

int main()
{
    int t;
    cin >> t;
    complex_number c[100];
    for (size_t i = 0; i < 2 * t; i = i + 2)
    {
        double r1, r2, i1, i2;
        cin >> r1 >> i1 >> r2 >> i2;
        c[i].set_val(r1, i1);
        c[i + 1].set_val(r2, i2);

        complex_number p = c[i].plus(c[i + 1]);
        complex_number s = c[i].sub(c[i + 1]);
        cout << "sum:";
        p.sprint();
        cout << "remainder:";
        s.sprint();
    }
    return 0;
}