#ifndef TREE_H
#define TREE_H


class Tree
{
	public:
		Tree();
		Tree(int tvalue);
		~Tree();
		Tree* sonNode;
		Tree* brotherNode;
		void appendSon(int tvalue);
		void appendBrother(int tvalue);
		int calculate();
		int getValue();
	private:
		int value;
};

#endif // TREE_H
