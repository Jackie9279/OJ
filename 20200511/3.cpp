#include<iostream>
#include<string>

using namespace std;

class Animal {
protected:
    string type, name;
    int age;
public:
    Animal (string type, string name, int age)
            :type(type), name(name), age(age) {}
    virtual void speak() = 0;
};

class Tiger: public Animal {
public:
    Tiger(string type, string name, int age): Animal(type, name, age) {}
    void speak() {
        cout << "Hello,I am " << name << ",AOOO." << endl;
    }
};

class Pig: public Animal{
public:
    Pig(string type,string name,int age): Animal(type, name, age) {}
    void speak() {
        cout << "Hello,I am " << name << ",HENGHENG." << endl;
    }
};

class Duck: public Animal {
public:
    Duck(string type,string name,int age): Animal(type, name, age) {}
    void speak() {
        cout << "Hello,I am " << name << ",GAGA." << endl;
    }
};

class Dog: public Animal {
public:
    Dog(string type,string name,int age): Animal(type, name, age) {}
    void speak() {
        cout << "Hello,I am " << name << ",WangWang." << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string type, name;
        int age;
        Animal *p;
        cin >> type >> name >> age;
        if (type == "Tiger") p = new Tiger(type, name, age);
        else if (type == "Pig") p = new Pig(type, name, age);
        else if (type == "Duck") p = new Duck(type, name, age);
        else if (type == "Dog") p = new Dog(type, name, age);
        else {
            cout << "There is no " << type << " in our Zoo." << endl;
            continue;
        }
        p->speak();
        delete p;
    }
    return 0;
}