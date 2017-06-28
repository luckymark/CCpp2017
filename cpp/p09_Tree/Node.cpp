#include"Node.h"
#include<iostream>

Node::Node(Node* parent, int value)
{
	this->value = value;
	this->parent = parent;
	left = right = NULL;

}