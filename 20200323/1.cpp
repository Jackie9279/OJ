#include <iostream>
#include <string.h>
using namespace std;

int isnumber(char *s)
{
    int i,m=0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if(isdigit(s[i]))
        {
            m=m*10+s[i]-'0';
        }
        else
        {
            return -1;
        }
    }
    return m;
    
}
 
int main()
{
    int t;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        char a[100];
        char *s;
        s=a;
        cin>>s;
        cout<<isnumber(s)<<endl;
    }
    
}

