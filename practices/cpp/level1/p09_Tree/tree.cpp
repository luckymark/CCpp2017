#include "tree.h"
Node::Node(int value)
{
	data = value;
}

void Node::append(Node *node)
{
	node->parent = this;
	childrenNodes.push_back(node);
	childCount ++;
}

int Node::count()
{
	return count;
}

Node* Node::getParent()
{
	return parent;
}

int Node::getValue()
{
	return data;
}
