#include<iostream>
#include<cmath>
#include <cstring>

using namespace std;

class M {
private:
    int **data;
    int m;
    int n;
public:
    M(int **data, int m, int n) : data(nullptr), m(0), n(0) {}

    M(int m, int n) : m(m), n(n) {
        int i, j;
        data = new int *[m];
        for (i = 0; i < m; i++) {
            data[i] = new int[n];
        }
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> data[i][j];
    }

    M &operator+(M &aa) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                aa.data[i][j] = data[i][j] + aa.data[i][j];
            }
        return aa;
    }

    void show() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

};

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        M a(m, n);
        M b(m, n);
        (a + b).show();
    }
}
