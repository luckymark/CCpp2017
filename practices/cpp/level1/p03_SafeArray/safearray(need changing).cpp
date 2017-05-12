#include<iostream>
#include"SafeArray.h"

int main(void)
{
	safearray a =100,b=100;
	a[101] = 0;
	a[55] = 101;
	safearray c = a;
	b = a;
	std::cout << c[55] << std::endl;
	std::cout << a[55] << std::endl;
	std::cout << b[55] << std::endl;
	system("pause");
	return 0;
}