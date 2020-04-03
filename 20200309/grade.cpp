#include <iostream>

using namespace std;

int main()
{
    int T;
    double grade[100];
    char flag[100];
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>grade[i];
        if(grade[i]>=0&&grade[i]<=100)
        {
            if(grade[i]>=85)
            {
                flag[i]='A';
            }
            if(grade[i]>=75&&grade[i]<85)
            {
                flag[i]='B';
            }
            if(grade[i]>=65&&grade[i]<75)
            {
                flag[i]='C';
            }
            if(grade[i]>=60&&grade[i]<65)
            {
                flag[i]='B';
            }
            if(grade[i]>=0&&grade[i]<60)
            {
                flag[i]='F';
            }

        }
        }

    for (int j = 0; j <T; ++j) {
        cout<<flag[j]<<endl;
    }
    return 0;
}