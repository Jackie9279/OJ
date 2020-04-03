#include <iostream>
#include <vector>

#define MAXSIZE 100
using namespace std;


int main() {
    int T;
    double a[MAXSIZE][3];
    double t;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < T; ++k) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2-i; j++) {
                double *p1 = &a[k][j];
                double *p2 = &a[k][j+1];
                if (*p1 < *p2) {
                    t = *p1;
                    *p1 = *p2;
                    *p2 = t;
                }
            }
        }
    }

    double *p3 = &a[0][0];
    for (int l = 0; l < T * 3; ++l) {
        cout << *(p3 + l) << " ";
        if (l % 3 == 2 && l != 0) {
            cout <<" "<< endl;
        }
    }
    return 0;
}