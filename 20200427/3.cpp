
#include <iostream>
#include <string>

using namespace std;

class Hotel {
public:
    Hotel(string a_Customer);

    ~Hotel();

    void Display();

    static void setmoney(float money);

private:
    string m_CustomerName;
    static int m_CustomerID;
    static int m_TotalCustNum;
    static float m_Rent;
    static float m_TotalEarning;
};

Hotel::~Hotel() {

}

int Hotel::m_TotalCustNum = 0;
float Hotel::m_Rent = 0;
float Hotel::m_TotalEarning = 0;
int Hotel::m_CustomerID = 20150000;


Hotel::Hotel(string a_Customer) {
    m_CustomerName = a_Customer;
    m_TotalCustNum++;
    m_CustomerID++;
    m_TotalEarning += m_Rent;
}

void Hotel::Display() {
    cout << m_CustomerName << ' ' << m_CustomerID << ' ' << m_TotalCustNum << ' ' << m_TotalEarning << endl;
}

void Hotel::setmoney(float money) {
    m_Rent = money;
    m_TotalCustNum = 0;
    m_TotalEarning = 0;
}

int main() {
    float m;
    cin >> m;
    Hotel::setmoney(m);
    string a;
    while (cin >> a) {
        if (!a.compare("0")) {
            break;
        }
        Hotel b(a);
        b.Display();
    }
    return 0;
}





