#include <iostream>
#include <string>

using namespace std;

class Classroom
{
private:

public:
    Classroom(/* args */);
    ~Classroom();
};
class Student
{
private:
    int Id;
    string Name;
    string Gender;
    string College;
    string TelephoneNumber;

public:
    Student();
    ~Student();
    void setinfo(string Name, int Id, string Gender, string College, string TelephoneNumber);
    void printinfo();
};

Classroom::Classroom()
{
}
Classroom::~Classroom()
{
}
Student::Student()
{

}
void Student::setinfo(string aName, int aId, string aGender, string aCollege, string aTelephoneNumber)
{
    Name = aName;
    Id = aId;
    Gender = aGender;
    College = aCollege;
    TelephoneNumber = aTelephoneNumber;
}
Student::~Student()
{
}
void Student::printinfo()
{
    cout << Name << endl;
}

int main()
{
    int t;
    cin >> t;
    int Id;
    string Name;
    string Gender;
    string College;
    string TelephoneNumber;
    Classroom c1;
    Student stu[100];
    for (int i = 0; i < t; ++i)
    {
        cin >> Name >> Id >> Gender >> College >> TelephoneNumber;
        stu[i].setinfo(Name,Id,Gender,College,TelephoneNumber);
    }
    for (size_t i = 0; i < t; i++)
    {
        stu[i].printinfo();
    }
    return 0;
}