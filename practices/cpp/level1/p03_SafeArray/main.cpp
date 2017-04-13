//SafeArray

#include <iostream>
#include<stdlib.h>
#include"SafeArray.h"
using namespace std;

int main()
{	
	int number;
	int value;

	cout<<"How many numbers do you want to save?"<<endl;
	cin>>number;
	
	SafeArray a(number); 

	for(int i=0;i<number;++i)
	{
		cin>>value;
		a.put(i,value);
	}
	
	while(1)
	{
		cout<<"Which number do you want to visit?" <<endl;
		int m;
		cin>>m;
		if(m==-1)
		{
			break;
		}
		cout<<a.get(m)<<endl;
	}
}


