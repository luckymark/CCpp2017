#include <iostream>
using namespace std;
#include "student.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*todolist
1.name id score  
2.add , remove, find, exit 
3.menu a)add b)remove c)find d)exit
*/
int main(int argc, char** argv) {
	freopen("information.txt","r",stdin);
	student s1;
	freopen("con","r",stdin); 
	s1.menu();
	return 0;
}
