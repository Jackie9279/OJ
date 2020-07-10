#include <vector>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class m {
private:
    vector<vector<T>> max;
public:
    m(const vector<vector<T>> &max) : max(max) {}

    m() {}

    void transport();

};

template<class T>
void m<T>::transport() {
    vector<vector<T>> v(max[0].size(), vector<T>());
    for (int i = 0; i < max.size(); i++) {
        for (int j = 0; j < max[0].size(); j++) {
            v[j].push_back(max[i][j]);
        }
    }
    for (auto it:v) {
        for (T itt:it) {
            cout << itt << " ";
        }
        cout << endl;
    }
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        int r, c;
        cin >> s;
        if (s == "I") {
            vector<vector<int>> v;
            vector<int> vv;
            int temp;
            cin >> r >> c;
            for (int j = 0; j < r; ++j) {
                vv.clear();
                for (int k = 0; k < c; ++k) {
                    cin >> temp;
                    vv.push_back(temp);
                }
                v.push_back(vv);
            }
            m<int> a(v);
            a.transport();
        } else if (s == "C") {
            vector<vector<char>> v;
            vector<char> vv;
            char temp;
            cin >> r >> c;
            for (int j = 0; j < r; ++j) {
                vv.clear();
                for (int k = 0; k < c; ++k) {
                    cin >> temp;
                    vv.push_back(temp);
                }
                v.push_back(vv);
            }
            m<char> a(v);
            a.transport();
        } else if (s == "D") {
            vector<vector<double>> v;
            vector<double> vv;
            double temp;
            cin >> r >> c;
            for (int j = 0; j < r; ++j) {
                vv.clear();
                for (int k = 0; k < c; ++k) {
                    cin >> temp;
                    vv.push_back(temp);
                }
                v.push_back(vv);
            }
            m<double> a(v);
            a.transport();
        }
    }
    return 0;
}