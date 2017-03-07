#include <stdio.h>

int main()
{
	int x;
	for(x=1; x<150; x++){
		if(x/6 + x/12 + x/7 + 5 + x/2 + 4 ==x)  
			break;
	}
	printf("The father had lived for %d years.\n",x);
	return 0;
}
