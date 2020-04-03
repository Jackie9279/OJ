#include <iostream>
#include <string.h>

#define MAXSIZE 100
using namespace std;

int judge(char *S, char *T) {
    int s_len, t_len;
    int a = 0, b = 0;
    s_len = strlen(S);
    t_len = strlen(T);
    if (s_len > t_len) {
        return 1;
    } else if (s_len < t_len) {
        return -1;
    } else {
        for (int i = 0; i < *(S + i) != '\0'; ++i) {
            if (*(S + i) > *(T + i)) {
                a++;
            } else {
                b++;
            }
        }
        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main()
{
    char s[MAXSIZE],t[MAXSIZE];
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>s>>t;
        cout<<judge(s,t)<<endl;
    }
    return 0;
}