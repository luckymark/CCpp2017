#include <iostream>
#include "safearray.h"
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	SafeArray a(100);
	a.write(10,20);
	cout<<a.read(101);
	return 0;
}
