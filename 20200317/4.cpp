#include <iostream>

#define MAXSIZE 100
using namespace std;

int main() {
    int T;
    int num[MAXSIZE];
    int a[MAXSIZE][MAXSIZE];
    int len[MAXSIZE];
    int in[MAXSIZE];
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> num[i];
        for (int j = 0; j < num[i]; ++j) {
            cin >> a[i][j];
            len[i]++;
        }
        cin >> in[i];
    }


    for (int l = 0; l < T; ++l) {
        if (len[l] % 2 == 1) {
            int *p1 = &a[l][(len[l] - 1) / 2];
            cout << *(p1 - 1) << " " << *(p1 + 1) << endl;
            int re = (len[l] - 1) / 2 - in[l];
            cout << *(p1 - re - 1) << endl;
        } else {
            int *p1 = &a[l][len[l] / 2];
            cout << *(p1 - 1) << " " << *(p1 + 1) << endl;
            int re = len[l]  / 2 - in[l];
            cout << *(p1 - re - 1) << endl;
        }

    }
    return 0;

}
