#include <bits/stdc++.h>

using namespace std;

template<typename T>
void tongji(vector<T> a, unordered_map<T, int> b) {
    for (auto it:a) {
        b[it]++;
    }
    int maxx = 0;
    for (auto it:b) {
        maxx = max(it.second, maxx);
    }
    for (auto it:b) {
        if (it.second == maxx) {
            cout << it.first << " " << it.second << endl;
            break;
        }
    }
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
            vector<int> a;
            unordered_map<int, int> bb;
            for (int j = 0; j < num; ++j) {
                int temp;
                cin >> temp;
                a.push_back(temp);
            }
            tongji(a, bb);
        } else if (A == 'D') {
            vector<double> b;
            unordered_map<double, int> bb;
            for (int j = 0; j < num; ++j) {
                double temp;
                cin >> temp;
                b.push_back(temp);
            }
            tongji(b, bb);
        } else if (A == 'C') {
            vector<char> c;
            unordered_map<char, int> bb;
            for (int j = 0; j < num; ++j) {
                char temp;
                cin >> temp;
                c.push_back(temp);
            }
            tongji(c, bb);
        } else if (A == 'S') {
            vector<string> d;
            unordered_map<string, int> bb;
            for (int j = 0; j < num; ++j) {
                string temp;
                cin >> temp;
                d.push_back(temp);
            }
            tongji(d, bb);
        }
    }
    return 0;
}