#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
#define V 10
int main()
{
	int cnt=0,flag=1;
	while(1)
	  {
	  	system("cls");
	  	for(int i=1;i<=cnt;++i) putchar(' ');
	  	putchar('R');
	  	cnt+=flag;
	  	if(cnt==0 || cnt==79) flag=-flag;
	  	while(clock()-V<10);
	  }
	return 0;
}
