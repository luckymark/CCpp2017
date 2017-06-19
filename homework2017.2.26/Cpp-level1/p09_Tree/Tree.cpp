#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int num){
	node.push_back(Node(num,-1));
}

void Tree::addSonOf(int index,int num){
	if (index>=node.size()){
		cout<<"Fail!Node[index] is not exist.";
		return;
	}
	node.push_back(Node(num,index));
	node[index].append(node.size()-1);
	while(index^-1){
		node[index].amountOfSons+=1;
		index=node[index].getFather();
	}
}

int Tree::getFatherOf(int index){
	return node[index].getFather();
}

int Tree::getNumOfSonOf(int index){
	return node[index].amountOfSons;
}
