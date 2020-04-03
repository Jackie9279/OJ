#include <iostream>

#define MAXSIZE 100
using namespace std;

int main()
{
    int t;
    cin >> t;
    char *month[] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"};
    for (int i = 0; i < t; ++i)
    {
        int num;
        cin>>num;
        if(num>0&&num<13)
        {
            cout<<*(month+num-1)<<endl;
        }
        else
        {
            cout<<"error"<<endl;
        }
        
    }
    return 0;
}