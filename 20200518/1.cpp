#include <bits/stdc++.h>

#include <utility>

using namespace std;

int ccount=0;
class robot {
private:
    string name;
    double health;
    double damage;
    double defense;
    string TYPE;
    string nextTYPE;
    int level;
    static int count;


public:
    robot() {}

    robot(const string &name, const string &type, const string &nextType, int level);


    void setType(const string &type) {
        TYPE = type;
    }

    const string &getName() const {
        return name;
    }

    int getLevel() const {
        return level;
    }
    void print();

    const string &getType() const;

};

void robot::print() {
    cout<<name<<"--"<<nextTYPE<<"--"<<level<<"--"<<health<<"--"<<damage<<"--"<<defense<<endl;
}

const string &robot::getType() const {
    return TYPE;
}

robot::robot(const string &name, const string &type, const string &nextType, int level) : name(name), TYPE(type),
                                                                                          nextTYPE(nextType),
                                                                                          level(level) {
    if(TYPE=="N")
    {
        health=level*5;
        damage=level*5;
        defense=level*5;
    }
    if(TYPE=="A")
    {
        health=level*5;
        damage=level*5;
        defense=level*5;
    }
    if(TYPE=="D")
    {
        health=level*5;
        damage=level*5;
        defense=level*10;
    }
    if(TYPE=="H")
    {
        health=level*50;
        damage=level*5;
        defense=level*5;
    }
}

robot upgrade(robot* a,const string& TTYPE)
{
    if(a->getType()==TTYPE)
    {
        return *a;
    } else{
        ccount++;
        robot b(a->getName(),TTYPE,TTYPE,a->getLevel());
        return b;
    }

}

int main()
{
    int t;
    cin>>t;
    string name,type,nexttype;
    int level;
    for (int i = 0; i < t; ++i) {
        cin>>name>>type>>level>>nexttype;
        robot a(name,type,nexttype,level);
        a=upgrade(&a,nexttype);
        a.print();
    }
    cout<<"The number of robot transform is "<<ccount;
}


