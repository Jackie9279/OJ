#include <iostream>
#include <math.h>
#include <iomanip>

class Point
{
private:
    double x, y;

public:
    Point(); //Default constructor, assign 0 and x to 0

    Point(double x_value, double y_value); //A parameterized constructor that assigns parameter values to x and y

    double getX(); //Returns the value of x

    double getY(); //Returns the value of y

    void setX(double x_value); //Set the value of x

    void setY(double x_value); //Set the value of x

    double distanceToAnotherPoint(Point p); //Calculate the distance from the current point to the parameter point p
};

Point::Point()
{
    x = 0;
    y = 0;
}
Point::Point(double x_value, double y_value)
{
    x = x_value;
    y = y_value;
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x_value)
{
    x = x_value;
}
void Point::setY(double y_value)
{
    y = y_value;
}
double Point::distanceToAnotherPoint(Point p)
{
    return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
}

using namespace std;

int main()
{
    int t;
    cin >> t;
    Point a[100];
    for (size_t i = 0; i < 2 * t; i = i + 2)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i].setX(x1);
        a[i].setY(y1);
        a[i + 1].setX(x2);
        a[i + 1].setY(y2);
        cout << fixed << setprecision(2) << "Distance of Point(" << a[i].getX() << "," << a[i].getY() << ") to Point(" << a[i + 1].getX() << "," << a[i + 1].getY() << ")"
             << " is " << a[i].distanceToAnotherPoint(a[i + 1])<<endl;
    }
    return 0;
}