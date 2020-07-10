#include <bits/stdc++.h>

using namespace std;

class CVehicle
{
public:
    double max_speed;
    double speed;
    double weight;
    CVehicle() {}


    CVehicle(double maxSpeed, double speed, double weight) : max_speed(maxSpeed), speed(speed), weight(weight) {
    }
    virtual void display();
};

void CVehicle::display() {
    cout<<"Vehicle:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<endl;
}

class CBicycle:public CVehicle
{
public:
    double height;

    CBicycle() {}

    CBicycle(double maxSpeed, double speed, double weight, double height) : CVehicle(maxSpeed, speed, weight),
                                                                            height(height) {}
    void display() override;

};

void CBicycle::display() {
    cout<<"Bicycle:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"height:"<<height<<endl<<endl;

}

class CMotocar:public CVehicle
{
public:
    int seat_num;

    CMotocar() {}

    CMotocar(int seatNum);

    CMotocar(double maxSpeed, double speed, double weight, int seatNum) : CVehicle(maxSpeed, speed, weight),
                                                                          seat_num(seatNum) {}
    void display() override ;

};

void CMotocar::display() {
    cout<<"Motocar:"<<endl<<"max_speed:"<<max_speed<<endl<<"speed:"<<speed<<endl<<"weight:"<<weight<<endl<<"seat_num:"<<seat_num<<endl<<endl;
}

CMotocar::CMotocar(int seatNum) : seat_num(seatNum) {}

class CMotocycle :public CBicycle,CMotocar
{
public:
    CMotocycle();

    CMotocycle(double maxSpeed, double speed, double weight, double height, int seatNum);

public:
    void display() override;

};

void CMotocycle::display() {
    cout<<"Motocycle:"<<endl<<"max_speed:"<< CBicycle::max_speed<<endl<<"speed:"<<CBicycle::speed<<endl<<"weight:"<<CBicycle::weight<<endl<<"height:"<<height<<endl<<"seat_num:"<<seat_num;

}

CMotocycle::CMotocycle() {}

CMotocycle::CMotocycle(double maxSpeed, double speed, double weight, double height, int seatNum) : CBicycle(maxSpeed,
                                                                                                            speed,
                                                                                                            weight,
                                                                                                            height),
                                                                                                   CMotocar(seatNum) {}


int main()
{
    double max_speed;
    double speed;
    double weight;
    double height;
    int seat_num;
    cin>>max_speed>>speed>>weight>>height>>seat_num;
    CVehicle a(max_speed,speed,weight);
    CBicycle b(max_speed,speed,weight,height);
    CMotocar c(max_speed,speed,weight,seat_num);
    CMotocycle d(max_speed,speed,weight,height,seat_num);
    a.display();
    b.display();
    c.display();
    d.display();
    return 0;
}