#include <iostream>


#define MAX_SIZE 10
using namespace std;

int main()
{
    int T;
    int n[MAX_SIZE];
    int a[MAX_SIZE][MAX_SIZE];
    int aver[MAX_SIZE]={};
    int flag[MAX_SIZE]={};
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>n[i];
        for (int j = 0; j < n[i]; ++j) {
            cin>> a[i][j];
        }
    }
    for (int k = 0; k < T; ++k) {
        for (int i = 0; i < n[k]; ++i) {
            aver[k]=a[k][i]+aver[k];
        }
        aver[k]=aver[k]/n[k];
    }

    for (int l = 0; l < T; ++l) {
        for (int i = 0; i < n[l]; ++i) {
            if(a[l][i]>aver[l])
            {
                flag[l]++;
            }
        }
    }

    for (int m = 0; m < T;  ++m) {
        cout<<flag[m]<<endl;
    }
    return 0;
}