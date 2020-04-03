#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student
{
private:
    string name;
    long long id;
    string college;
    string profession;
    string sex;
    string address;
    string phone_number;
    double chinese;
    double math;
    double english;
    double biology;
    double history;

public:
    Student(string name, long long id, string college, string profession, string sex, string address, string phone_number);
    int do_homework(int id);
    ~Student();
};

Student::Student(string name, long long id, string college, string profession, string sex, string address, string phone_number)
{
    name = name;
    id = id;
    college = college;
    profession = profession;
    sex = sex;
    address = address;
    phone_number = phone_number;
}
int Student::do_homework(int id)
{
     return id * id;
}

Student::~Student()
{
}

class Teacher
{
private:
    string name;
    long long id;
    string job_title;
    string position;
    string education;
    string sex;
    string phone_number;

public:
    Teacher(string name, long long id, string job_title, string position, string education, string sex, string phone_number);
    int homework(map<string,int> b);
    void review(int id);
    ~Teacher();
};

Teacher::Teacher(string name, long long id, string job_title, string position, string education, string sex, string phone_number)
{
    name = name;
    id = id;
    job_title = job_title;
    position = position;
    education = education;
    sex = sex;
    phone_number = phone_number;
}

int Teacher::homework(map<string, int> sub)
{
    string subname;
    cin>>subname;
    return sub[subname];
}
void Teacher::review(int id)
{
    int a=id > 60 ? 88 : 44;
    cout<<a<<endl;
}

Teacher::~Teacher()
{
}

int main()
{
    int t;
    int id;
    cin >> t;
    map<string, int> sub;

    //课程输入
    for (size_t i = 0; i < t; i++)
    {
        int id;
        string subname;
        cin >> id >> subname;
        sub.insert(pair<string, int>(subname, id));
    }
    Student s1("Jack", 20183220, "大数据", "物联网", "男", "深圳市广东省", "13099999999");
    Teacher t1("Rose", 00000001, "教授", "教学", "博士", "女", "13022222222");

    //流程
    int y;
    cin >> y;
    for (size_t i = 0; i < y; i++)
    {
        int mark=t1.homework(sub);
        int socre=s1.do_homework(mark);
        t1.review(socre);
    }
}