#include <bits/stdc++.h>

using namespace std;
#define PI 3.14

class Shape
{
public:
    virtual double Area() = 0;
    Shape() {}

};

class Circle:public Shape
{
private:
    double r;
public:
    Circle() {}

    Circle(double r) : r(r) {}

    double Area() override ;

};

double Circle::Area() {
    return r*r*PI;
}

class Square:public Shape
{
private:
    double x;
public:
    Square() {}

    Square(double x);

    double Area() override ;

};

double Square::Area() {
    return x*x;
}

Square::Square(double x) : x(x) {}

class Rectangle:public Shape
{
private:
    double x,y;
public:
    Rectangle() {}

    Rectangle(double x, double y);

    double Area() override ;

};

double Rectangle::Area() {
    return x*y;
}

Rectangle::Rectangle(double x, double y) : x(x), y(y) {}


int main()
{
    int t;
    cin>> t;
    double r,x,y,xx;
    for (int i = 0; i < t; ++i) {
        cin>>r>>xx>>x>>y;
        Circle c(r);
        Square s(xx);
        Rectangle re(x,y);
        cout<<fixed<<setprecision(2)<<c.Area()<<endl<<fixed<<setprecision(2)<<s.Area()<<endl<<fixed<<setprecision(2)<<re.Area();
        if(i!=t-1)
        {
            cout<<endl;
        }
    }
    return 0;
}

