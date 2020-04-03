#include <iostream>
#include <iomanip>

#define MAXSIZE 100
using namespace std;
int main()
{
    double usa=6.2619;
    double euroa=6.6744;
    double yena=0.0516;
    double hka=0.8065;
    const double *us =&usa;
    const double *euro=&euroa;
    const double *yen=&yena;
    const double *hk=&hka;
    char y[MAXSIZE];
    double a[MAXSIZE];
    double b[MAXSIZE];
    char c;
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>y[i]>>a[i];
        }
    for (int j = 0; j < T; ++j) {
        if(y[j]=='D')
        {
            b[j]=a[j]*(*us);
        }
        if(y[j]=='E')
        {
            b[j]=a[j]*(*euro);
        }
        if(y[j]=='Y')
        {
            b[j]=a[j]*(*yen);

        }
        if(y[j]=='H')
        {
            b[j]=a[j]*(*hk);
        }
    }
    for (int k = 0; k < T; ++k) {
        cout<<fixed<<setprecision(4)<<b[k]<<endl;
    }
    return 0;
}