#include <bits/stdc++.h>

using namespace std;

class Employee
{
protected:
    string name;
    int level, age;

public:
    Employee();

    Employee(const string &name, int level, int age);

    virtual double salary();
};

class Teamleader : public Employee
{
public:
    Teamleader();

    Teamleader(const string &name, int level, int age) : Employee(name, level, age) {}

    double salary() override;
};

class Manager : public Employee
{
public:
    Manager() {}

    Manager(const string &name, int level, int age) : Employee(name, level, age) {}

    double salary() override;
};

double Manager::salary()
{
    return 5000 + 1000 * (level + age);
}

double Teamleader::salary()
{
    return 3000 + 800 * level + 100 * age;
}

Teamleader::Teamleader() {}

double Employee::salary()
{
    return 1000 + 500 * level + 50 * age;
}

Employee::Employee() {}

Employee::Employee(const string &name, int level, int age) : name(name), level(level), age(age) {}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string name, position;
        int level, age;
        cin >> name >> position >> level >> age;
        Employee *p;
        if (position != "Employee" && position != "Teamleader" && position != "Manager" && age < 0 && level < 0)
        {
            cout << "error position." << endl;
        }
        else if (age < 0 || level < 0)
        {
            cout << "error grade or year." << endl;
        }
        else if (position == "Employee")
        {
            Employee a(name, level, age);
            p = &a;
            cout << name << ":Employee,Salary:" << p->salary() << endl;
        }
        else if (position == "Teamleader")
        {
            Teamleader a(name, level, age);
            p = &a;
            cout << name << ":Teamleader,Salary:" << p->salary() << endl;
        }
        else if (position == "Manager")
        {
            Manager a(name, level, age);
            p = &a;
            cout << name << ":Manager,Salary:" << p->salary() << endl;
        }
        else
        {
            cout << "error position." << endl;
        }
    }
    return 0;
}