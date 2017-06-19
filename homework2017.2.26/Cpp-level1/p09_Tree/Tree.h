#ifndef TREE_H
#define TREE_H
#include <vector>
#include "Node.h"
using namespace std;
class Tree{
private:
	int numOfSon;
	vector<Node> node;
public:
	Tree(int num);
	void addSonOf(int index,int num=0);
	int getFatherOf(int index);
	int getNumOfSonOf(int index);
};

#endif
