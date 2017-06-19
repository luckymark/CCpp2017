#include<iostream>
#include"emploee.h"
using namespace std ;

int main()
{
    Saleman Wang("wang",28,2);
    
    Wang.set(2);

    cout<<"Wang ' slary is  "<<Wang.evalueslary();

}
