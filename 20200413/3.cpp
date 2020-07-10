#include <bits/stdc++.h>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(/* args */);
    Point(double ax, double ay);
    void set_xy(double ax, double ay);
    double get_x();
    double get_y();

    ~Point();
};

Point::Point(double ax, double ay)
{
    x = ax;
    y = ay;
}

void Point::set_xy(double ax, double ay)
{
    x = ax;
    y = ay;
}
double Point::get_x()
{
    return x;
}
double Point::get_y()
{
    return y;
}
Point::Point(/* args */)
{
}

Point::~Point()
{
    x = 0;
    y = 0;
    cout << "point clear" << endl;
}

class Circle
{
private:
    double x;
    double y;
    double r;

public:
    Circle(/* args */);
    Circle(double ax, double ay, double ar);
    bool check(Point &a);
    ~Circle();
};

Circle::Circle(double ax, double ay, double ar)
{
    x = ax;
    y = ay;
    r = ar;
}

bool Circle::check(Point &a)
{
    double dist;
    double px = a.get_x();
    double py = a.get_y();
    dist = sqrt((px - x) * (px - x) + (py - y) * (py - y));
    if (dist > r)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Circle::~Circle()
{
    x = 0;
    y = 0;
    r = 0;
    cout << "circle clear" << endl;
}

int main()
{
    double x, y;
    cin >> x >> y;
    Point a = Point(x, y);
    int n;
    cin >> n;
    Point *b = new Point[n];
    for (size_t i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        b[i].set_xy(x, y);
    }
    double cx, cy, cr;
    cin >> cx >> cy >> cr;
    Circle c = Circle(cx, cy, cr);
    if (c.check(a))
    {
        cout << "in" << endl;
    }
    else
    {
        cout << "out" << endl;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (c.check(b[i]))
        {
            cout << "in" << endl;
        }
        else
        {
            cout << "out" << endl;
        }
    }
    return 0;
}
