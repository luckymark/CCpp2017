#include "Tree.h"

Node::Node(){
	father = NULL;
	val = 0;
	size = 1;
	sons.clear();
}
Node::Node(Node *father, int val):father(father),val(val){ 
	size = 1;
	sons.clear();
}

void Node::push_up(){
	size = 0;
	for(int i = 0; i < sons.size(); i++){
		size += sons[i] -> size;
	}
	size++;
}

Node* Node::append(int val){
	Node *tmp = new Node(this, val);
	sons.push_back(tmp);
	return tmp;
}

Tree::Tree(){
	access.clear();
	access.push_back(new Node(NULL, 0));
}

void Tree::insert(int a,int val){
	if(a >= access.size()) {
		cerr << "error with node number" << endl;
		return;
	}
	access.push_back(access[a] -> append(val));
	Node *tmp = access[a];
	while(tmp != NULL){
		tmp -> push_up();
		tmp = tmp -> father;
	}
}

int Tree::get_size(int x){
	if(x >= access.size()){
		cerr << "error with node number" << endl;
		return 0;
	}
	return access[x] -> size;
}

int Tree::get_val(int x){
	if(x >= access.size()){
		cerr << "error with node number" << endl;
		return 0;
	}
	return access[x] -> val;
}

void Tree::set_val(int a,int x){
	if(a >= access.size()){
		cerr << "error with node number" << endl;
		return;
	}
	access[a] -> val = x;
}

Tree::~Tree(){
	for(int i = 0; i < access.size(); i++){
		delete access[i];
	}
}
