#include"sarray.h"
#include<iostream>
sarrayi::sarrayi(int i = 1)
{
	if (i < 1)printf("The input is unavaliable.\nThe length of array will set to 1.\n");
	len = i > 0 ? i : 1;
	pt=new int[len];
}

sarrayi::~sarrayi()
{
	delete[]pt;
}

int & sarrayi::operator[](int i)
{
	if (i < 0) {
		printf("Index must be no less than 0\n");
		printf("Index set to 0\n");
		return pt[0];
	}
	else if (i >= len) {
		printf("Index must be less than %d\n", len - 1);
		printf("Index set to %d\n", len - 1);
		return pt[len - 1];
	}
	else return pt[i];
}