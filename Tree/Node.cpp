#include "Node.h"

Node::Node(int value,Node* parent){
	this->value=value;
	this->parent=parent;
	childs.clear();
}

Node::~Node(){
	childs.clear();
}

Node* Node::append(Node* ch){
	childs.push_back(ch);
	return ch;
}

int Node::GetValue(){
	return value;
}

Node* Node::GetParent(){
	return parent;
}

int Node::GetSubtreeSize(){
	int size=1;
	for(int i=0;i<childs.size();++i){
		size+=childs[i]->GetSubtreeSize();
	}
	return size;
}
