#include <iostream>
#include "Tree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tree tree(2);
	tree.addSonOf(0);
	tree.addSonOf(1,5);
	cout<<tree.getNumOfSonOf(0)<<endl;
	cout<<tree.getFatherOf(1)<<endl;
	return 0;
}
