#ifndef TREE_H_
#define TREE_H_

#include"Node.h"
#include<iostream>

class Tree
{
public:
	void append(int value);
	void countNode();
	Node* getParent(int value);
	Node* locate(int value);
	Tree();
private:
	Node* root;
	Node* pNode;
	int count;
};

#endif
