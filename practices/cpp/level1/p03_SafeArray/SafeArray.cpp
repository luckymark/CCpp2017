#include "SafeArray.h"
#include <iostream>
using namespace std;


void SafeArray::init(int number,int value)
{
    safearray[number]=value;
}

void SafeArray::see(int n)
{
    if(n>0&&n<k)
    {
        cout<<safearray[n]<<endl;
    }
    else
    {
        cout<<"error"<<endl;
    }
}
