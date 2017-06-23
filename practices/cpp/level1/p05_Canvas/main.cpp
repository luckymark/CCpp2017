/*
* Author:	Kyrios0
* Date:	2016.04
* To-Do List:
* 			~~Circle&Rectan~~
*			~~paint~~
* 			~~add~~
	*			addCir
	*			addRec
* 			~~del~~
	*			delCir
	*			delRec
*			~~help~~
*			Optimization
* 			and more?
* State:	Processing
*/
#include <iostream>
#include <string.h>
#include <conio.h>
#include "canvas.h"

void invalid(char *cm)
{
	cm[strlen(cm) - 1] = '\0';
	printf("\"%s\" isn't a valid command, Type \"help\" for more information.\n", cm);
}

void help()
{
	puts("\n\tGNU bash, Version 4.3.42(1)-release (x86_64-pc-kyanvas-gnu)\n\n\
			\tCommand\t\tInfo\n\
			\tadd\t\tAdd a circle or rectangle\n\
			\tdel\t\tDelete an item\n\
			\tpaint\t\tDisplay all items\n\
			\tquit\t\tQuit\n");
}

int main(int argc, char** argv) {
	char cm[128] = "Kyrios";
	puts("Kyanvas 1.0.0 (default, Apr 25 2017, 09:18:07) [MSC v.1500 64 bit (AMD64)] on win64");
	puts("Type \"help\" for more information.");
	Canvas canvas;
	while (1)
	{
		printf("root@user: ");
		fgets(cm, 128, stdin);
		if (!strcmp(cm, "help\n"))
		{
			help();
		}
		else if (!strcmp(cm, "paint\n"))
		{
			canvas.paint();
		}
		else if (!strcmp(cm, "add\n"))
		{
			canvas.add();
		}
		else if (!strcmp(cm, "del\n"))
		{
			canvas.del();
		}
		else if (!strcmp(cm, "quit\n"))
		{
			break;
		}
		else
		{
			invalid(cm);
		}

	}
	puts("Kyrios hope you'll have a nice day, bye.");
	puts("Press any key to quit...");
	_getch();
	return 0;
}