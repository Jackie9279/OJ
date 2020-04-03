//
// Created by pomelo on 2020/3/9.
//
#include <iostream>

#define MAXSIZE 100
using namespace std;
int main()
{
    int T;
    int x[MAXSIZE];
    int y[MAXSIZE];
    int z[MAXSIZE];
    int surface[MAXSIZE];
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>x[i]>>y[i]>>z[i];
        surface[i]=(x[i]*y[i]+y[i]*z[i]+x[i]*z[i])*2;
    }
    for (int j = 0; j < T; ++j) {
        cout<<surface[j]<<endl;
    }
    return 0;

}