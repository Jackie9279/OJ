#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>

using namespace std;

class si
{
private:
    string value;

public:
    friend si operator+(si &a, si &b);

    si(const string &value);

    si();

    void show();

    void setValue(const string &value);

    int atoi(string s);

    string intToA(int n);
};

si operator+(si &a, si &b)
{
    si c;
    c.value = c.intToA(a.atoi(a.value) + b.atoi(b.value));
    return c;
}

int si::atoi(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t >= '0' && t <= '9')
            ans = ans * 4 + t - '0';
        else
            ans = ans * 4 + t - 'a' + 10;
    }
    return ans;
}

string si::intToA(int n)
{
    string ans = "";
    do
    {
        int t = n % 4;
        if (t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        n /= 4;
    } while (n != 0); //使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(), ans.end());
    return ans;
}

void si::show()
{
    cout << value;
}

void si::setValue(const string &value)
{
    si::value = value;
}

si::si()
{
}

int main()
{
    int t;
    cin >> t;
    si a[10];
    string b;
    for (int i = 0; i < t; ++i)
    {
        cin >> b;
        a[i].setValue(b);
    }
    for (int j = 1; j < t; ++j)
    {
        a[0] = a[j] + a[0];
    }
    a[0].show();
}
