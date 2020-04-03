#include <iostream>

#define MAXSIZE 100
using namespace std;


int main()
{
    int T;
    int a[MAXSIZE],b[MAXSIZE],c[MAXSIZE];
    int flag[MAXSIZE];
    cin>>T;
    for(int i = 0; i < T; ++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]+b[i]>c[i]&&b[i]==c[i])
        {
            flag[i]=1;
        }
        else
        {
            flag[i]=0;
        }
    }
    for(int i = 0; i < T; ++i)
    {
        cout<<flag[i]<<endl;
    }

    return 0;
}