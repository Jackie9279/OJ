#include <iostream>
#include <cstring>
using namespace std;
class CTelNumber
{
private:
    char *p;

public:
    CTelNumber()
    {
        p = new char[8];
    }
    CTelNumber(char *q)
    {
        p = new char[8];
        strcpy(p, q);
    }
    CTelNumber(CTelNumber &q)
    { //拷贝构造函数同时满足了题目要求的升位运算
        p = new char[9];
        if (q.p[0] == '2' || q.p[0] == '3' || q.p[0] == '4')
        {
            p[0] = '8';
        }
        else
            p[0] = '2';
        for (int i = 0; i < 7; i++)
        {
            p[i + 1] = q.p[i];
        }
    }
    void print()
    {
        for (int i = 0; i < 8; i++)
            cout << p[i];
        cout << endl;
    }
    ~CTelNumber()
    { //析构函数
        delete p;
    }
};
int main()
{
    int t, i, is;
    cin >> t;
    char *q;
    while (t--)
    {
        is = 1;
        q = new char[8];
        cin >> q;
        for (i = 1; i < 7; i++)
        {
            if (q[i] > '9' || q[i] < '0')
            {
                is = 0; //判断输入是否符合要求
                break;
            }
        }
        if (is)
        {
            if (strlen(q) == 7)
            {
                if (q[0] >= '2' && q[0] <= '8')
                {
                    CTelNumber m(q);
                    CTelNumber n(m);
                    n.print();
                }
                else
                    cout << "Illegal phone number" << endl;
            }
        }
        else
            cout << "Illegal phone number" << endl;
    }
}
