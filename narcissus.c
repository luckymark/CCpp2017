#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char** argv) 
{
	for(int i=100;i<1000;i++)
	{
		if((pow(i/100,3)+pow(i%100/10,3)+pow(i%100%10,3)==i))
		cout<<i<<"为水仙花数"<<endl;
	}		
	return 0;
}
