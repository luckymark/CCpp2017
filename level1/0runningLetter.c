#include <stdio.h>
#include <unistd.h>
#define COLUMN 80 

int main(){
	int blank,location;

	for (location = 1; location <=COLUMN ; location++){
		for (blank=1; blank < location; blank++){
			printf(" ");
		}
		putchar('A');
		usleep(2000000);
		system("clear");
	}
	for (location = location-1; location >=1; location--){
		for (blank=1; blank < location; blank++){
			printf(" ");
		}
		putchar('A');
		usleep(200000);
		system("clear");
	}
	return 0;
}

		
		
