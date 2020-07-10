#include <bits/stdc++.h>

using namespace std;

template <typename T>
void sortt(vector<T> &a)
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[i] > a[j])
            {
                T t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        char A;
        cin >> A;
        int num;
        cin >> num;
        if (A == 'I')
        {
            vector<int> a;
            for (int j = 0; j < num; ++j)
            {
                int temp;
                cin >> temp;
                a.push_back(temp);
            }
            sortt(a);
        }
        else if (A == 'D')
        {
            vector<double> b;
            for (int j = 0; j < num; ++j)
            {
                double temp;
                cin >> temp;
                b.push_back(temp);
            }
            sortt(b);
        }
        else if (A == 'C')
        {
            vector<char> c;
            for (int j = 0; j < num; ++j)
            {
                char temp;
                cin >> temp;
                c.push_back(temp);
            }
            sortt(c);
        }
        else if (A == 'S')
        {
            vector<string> d;
            for (int j = 0; j < num; ++j)
            {
                string temp;
                cin >> temp;
                d.push_back(temp);
            }
            sortt(d);
        }
    }
    return 0;
}