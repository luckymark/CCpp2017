#ifndef NODE_H_
#define NODE_H_


class Node
{
public:
	Node(Node* parent, int value = 0);
	friend class Tree;
private:
	Node* left;
	Node* right;
	Node* parent;
	int value;

};

#endif
