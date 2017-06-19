#include "Node.h"

Node::Node(int _num,int _father){
	num=_num;
	father=_father;
	amountOfSons=0;
}

void Node::append(int indexOfSon){
	son.push_back(indexOfSon);
}

int Node::getFather(){
	return father;
}
