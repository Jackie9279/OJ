#include <bits/stdc++.h>

using namespace std;

class c2d
{
protected:
    double x;
    double y;
public:
    c2d() {}
    c2d(double x, double y) : x(x), y(y) {}

    virtual double getDistance()
    {
        double dist=sqrt(x*x+y*y);
        return dist;
    }
};

class c3d:public c2d
{
private:
    double z;
public:
    c3d() {}
    c3d(double x, double y, double z) : c2d(x, y), z(z) {}
    double getDistance() override
    {
        double dist=sqrt(x*x+y*y+z*z);
        return dist;
    }
};


int main()
{
    double x,y,z;
    cin>>x>>y;
    c2d a(x,y);
    cout<<a.getDistance()<<endl;
    cin>>x>>y>>z;
    c3d b(x,y,z);
    cout<<b.getDistance()<<endl;
    cin>>x>>y>>z;
    c3d c(x,y,z);
    cout<<c.getDistance()<<endl;
    c2d d(x,y);
    cout<<d.getDistance();
    return 0;
}