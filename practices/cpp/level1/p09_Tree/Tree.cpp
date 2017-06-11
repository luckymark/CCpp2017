#include "Tree.h"
#define NULL 0
Tree::Tree()
{
	sonNode = NULL;
	brotherNode = NULL;
}


Tree::Tree(int tvalue)
{
	value = tvalue;
	sonNode = NULL;
	brotherNode = NULL;
}

Tree::~Tree()
{
	if(this != NULL)
	{
		delete this;
	}
}
void Tree::appendSon(int tvalue)
{
	this->sonNode = new Tree;
	sonNode->value = tvalue;
	sonNode->brotherNode = NULL;
	sonNode->sonNode = NULL;
}

void Tree::appendBrother(int tvalue)
{
	this->brotherNode = new Tree;
	brotherNode->value = tvalue;
	brotherNode->brotherNode = NULL;
	brotherNode->sonNode = NULL;
}

int Tree::calculate()
{
	int sum = 0;
	Tree* tNode = this->sonNode;
	while(tNode)
	{
		sum++;
		tNode = tNode->sonNode;
	}
	return sum;
}

int Tree::getValue()
{
	return value;
}
