#include<iostream>
#include"SafeArray.h"
using namespace std;
int main()
{
    SafeArray a(10);
    for(int i=0;i<10;i++)
    {
        a.value(i,i);
    }
    for(int i=0;i<11;i++)
    {
        cout<<a.get(i)<<endl;
    }
    return 0;
}
