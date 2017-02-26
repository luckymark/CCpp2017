#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for (int i=30;i<=10000;i++)
		if (i%12==0)
			if (i%7==0)
				{
					int n=i;
					if ((n/6+n/12+n/7+5)+n/2+4==n)
						{
							printf("%d\n",i-4);
							break;
						}
				}
	return 0;
}