/* author:	Kyrios0
 * date:	2017.02.23
 * version:	1.0.0
 * state:	finished
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
	system("chcp 437");
	system("cls");
	double age = 0.0, ans = 0.0;
	while(1)
	{
		ans = (1.0/6.0 + 1.0/12.0 + 1.0/7.0 + 1.0/2.0) * age + 9.0;
		if(ans - age < 0.1)
		{
			printf("He was %.0f years old at that time. \n", ans - 4);
			system("pause");
			return 0;
		}
		age += 1.0;
	 } 
	return 0;
}
