#include <iostream>
#include "SafeArray.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    cout<<"how many numbers you want to save?"<<endl;
    cin>>n;
    SafeArray array(n);

    srand(time(0));
    for(int i=0;i<n;i++)
    {
        array.init(i,rand());
    }

    while(1){
    int m;
    cout<<"which number you want to see?"<<endl;
    cin>>m;
    array.see(m);
    }

}
