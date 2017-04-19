#include <iostream>
#include "SafeArray.h"
using namespace std;
int main(){
	SafeArray a(10);
	for(int i = 0; i < 10; i++)
		a[i] = i;
	for(int i = 0; i < 10; i++)
		cout << a[i] << endl;
	a[10] = 1;
	return 0;
}
