#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for (int i=1;i<=9;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=9;k++)
				if (i*100+j*10+k==i*i*i+j*j*j+k*k*k)
					printf("%d\n",i*100+j*10+k);
	system("pause");
	return 0;
}