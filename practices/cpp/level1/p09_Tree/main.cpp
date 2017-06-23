#include <iostream>
#include "tree.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Node* root = new Node(1);
	Node* leftChild = new Node(2);
	Node* rightChild = new Node(3);
	root->append(leftChild);
    root->append(rightChild);
	return 0;
}
