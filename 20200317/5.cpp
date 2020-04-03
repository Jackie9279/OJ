#include <iostream>
#include <string.h>

#define MAXSIZE 100
using namespace std;

int main() {
    int t;
    cin >> t;
    char text[MAXSIZE];
    char key[MAXSIZE];
    int cypher[MAXSIZE];
    int len_text = 0;
    for (int k = 0; k < t; ++k) {
        cin >> text >> key;
        char *p1 = &text[0];
        char *p2 = &key[0];
        for (int j = 0; j < strlen(text); ++j) {
            int num = int(*(p1 + j)) + (int(*p2 + j % strlen(key) - '0'));
            int *p3 = &num;
            if ((*p3 < 'a' && *p3 > 'Z') || *p3 > 'z') {
                cout << char(*p3 - 26);
            } else {
                cout << char(*p3);
            }
        }
        cout << endl;
    }
        return 0;
}