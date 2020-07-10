#include <bits/stdc++.h>

using namespace std;

class phonenumber {
private:
    string number;
    string type;
public:
    phonenumber(const string &number, const string &type) : number(number), type(type) {}

    phonenumber() {}

    const string &getNumber() const {
        return number;
    }

    void setNumber(const string &number) {
        phonenumber::number = number;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        phonenumber::type = type;
    }
};

class virtualphone {
private:
    phonenumber Phonenumber;
    bool status;
    string name;
public:
    virtualphone() {
        cout << Phonenumber.getNumber() << " constructed." << endl;
    }

    virtualphone(phonenumber phonenumber, bool status, string name) : Phonenumber(std::move(phonenumber)),
                                                                      status(status), name(std::move(name)) {
        cout << Phonenumber.getNumber() << " constructed." << endl;
    }

    virtual ~virtualphone() {
        cout << Phonenumber.getNumber() << " destructed." << endl;
    }

    void print();

    bool query(const string &querynumber);

};

bool virtualphone::query(const string &querynumber) {
    return Phonenumber.getNumber() == querynumber;
}

void virtualphone::print() {
    string a;
    if (status == 1) {
        a = "use";
    } else {
        a = "unuse";
    }
    cout << "Phone=" << Phonenumber.getNumber() << "--Type="<<Phonenumber.getType()<< "--State="<< a << "--Owner=" << name << endl;

}

int main() {
    int t;
    string number;
    bool used;
    string type;
    string name;
    virtualphone *p[3];
    for (int i = 0; i < 3; ++i) {
        cin >> number >> type >> used >> name;
        phonenumber Phonenumber(number, type);
        p[i] = new virtualphone (Phonenumber, used, name);
    }
    cin >> t;
    string querynumber;

    for (int j = 0; j < t; ++j) {
        cin >> querynumber;
        int ok = 0;
        for (int i = 0; i < 3; ++i) {
            if (p[i]->query(querynumber) == 1) {
                p[i]->print();
                ok = 1;
            }
        }
        if (ok == 0) {
            cout << "wrong number."<<endl;
        }
    }
    for (int k = 2; k >=0; k--) {
        delete(p[k]);
    }

    return 0;
}


