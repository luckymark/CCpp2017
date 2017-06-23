#ifndef TREE_H_
#define TREE_H_
#include <vector>
#include <iostream>
using namespace std;

class Node{
	public:
		Node* father;
		vector<Node*> sons;
		int val;
		int size;
		Node();
		Node(Node* father, int val);
		void push_up();
		Node *append(int val);
};

/*使用索引访问树中的元素，添加元素时向上更新*/

class Tree{
	private:
		vector<Node*> access;
	public:
		Tree();
		void insert(int a,int val);
		int get_size(int a);
		int get_val(int a);
		void set_val(int a,int x);
		~Tree();
};

#endif
