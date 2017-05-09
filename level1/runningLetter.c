#include <stdio.h>
#include <unistd.h>
#define COLUMN 80 
#define PAUSE  100000

int main(){
	int blank,location=1,back=0;

	do
	{	for (blank=1; blank<location; blank++)
		{	printf(" "); }
		puts("A");
		usleep(PAUSE);
		system("clear");
		if (location==COLUMN) back=1;
		if (!back) location++;
		else location--;
	}
	while (location<=COLUMN && location>=1);	

	return 0;

}

		
		
