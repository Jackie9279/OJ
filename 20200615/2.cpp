#include <bits/stdc++.h>

using namespace std;

template<typename T>
int find(vector<T> a, T b) {
    int i = 1;
    for (T it:a) {
        if (it == b) {
            return i;
        }
        i++;
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        char A;
        cin >> A;
        int num;
        cin >> num;
        if (A == 'I') {
            int tar;
            vector<int> a;
            for (int j = 0; j < num; ++j) {
                int temp;
                cin >> temp;
                a.push_back(temp);
            }
            cin >> tar;
            cout << find(a, tar) << endl;
        } else if (A == 'D') {
            vector<double> b;
            double tar;
            for (int j = 0; j < num; ++j) {
                double temp;
                cin >> temp;
                b.push_back(temp);
            }
            cin >> tar;
            cout << find(b, tar) << endl;
        } else if (A == 'C') {
            vector<char> c;
            char tar;
            for (int j = 0; j < num; ++j) {
                char temp;
                cin >> temp;
                c.push_back(temp);
            }
            cin >> tar;
            cout << find(c, tar) << endl;
        } else if (A == 'S') {
            vector<string> d;
            string tar;
            for (int j = 0; j < num; ++j) {
                string temp;
                cin >> temp;
                d.push_back(temp);
            }
            cin >> tar;
            cout << find(d, tar) << endl;
        }
    }
    return 0;
}
