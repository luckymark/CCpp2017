#include<vector>
using namespace std;

class Node{
	private:
		int value;
		Node* parent;
		vector<Node*>childs;
	public:
		Node(int value,Node* parent);
		~Node();
		Node* append(Node* ch);
		int GetValue();
		Node* GetParent();
		int GetSubtreeSize();
};
