#include <iostream>
#include "Sale.h"
using namespace std;
int main(){
	Saleman he("陈小羽",19,10);
	he.set_price(100);
	cout << he.get_salary() << endl;
	return 0;
}
