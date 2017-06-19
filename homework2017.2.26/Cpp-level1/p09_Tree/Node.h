#ifndef NODE_H
#define NODE_H
#include <vector>
using namespace std;
class Node{
private:
	int num,father;
	vector<int> son;
public:
	int amountOfSons;
	Node(int _num,int _father);
	void append(int indexOfSon);
	int getFather();
};

#endif
