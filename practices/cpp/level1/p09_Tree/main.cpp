#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree root = Tree(0);
	root.appendSon(15);
	root.appendBrother(20);
	root.sonNode->appendSon(10);
	int sum = root.calculate();
	cout<<sum<<endl;
	return 0;
}
