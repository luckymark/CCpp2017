#include "Tree.h"
#include <iostream>
using namespace std;

int main(){
	Tree tree;
	tree.insert(0,5);
	tree.insert(0,6);
	tree.insert(1,3);
	tree.insert(3,3);
	tree.insert(1,4);
	tree.insert(5,5);
	int num = tree.get_size(1);
	cout << num << endl;
	for(int i = 0; i <= 6; i++){
		cout << tree.get_val(i) << " ";
	}
	return 0;
}
