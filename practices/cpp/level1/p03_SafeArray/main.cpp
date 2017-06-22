#include<iostream>
#include"sarray.h"
int main()
{
	sarrayi p1(6);
	p1[3] = 5;
	sarrayi p2(-1);
	p1[7] = 5;
	printf("%d   %d", p1[3], p1[7]);
}