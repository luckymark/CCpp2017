#include <stdio.h>
#define AGE 200
int main(void)
{
	float young,single,child,son;
	float i;
	for (i=1.0;i<AGE;i++){
		child=i/6;
		young=i/12;
		single=i/7;
		son=child+young+single+5.0+4.0;
		if (son==i/2){
		printf("The age is %d.",(int)i);
		break;
		}
	}
}
