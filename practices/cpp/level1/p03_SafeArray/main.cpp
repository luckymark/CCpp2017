#include <iostream>
#include "SafeArray.h"

int main(int argc, char** argv) {
	SafeArray a(100);
	a[0] = 0;
	a[200] = 1;
	return 0;
}
