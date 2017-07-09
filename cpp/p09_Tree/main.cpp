#include"Node.h"
#include"Tree.h"

void main()
{
	Tree* tr = new Tree;
	tr->append(5);
	tr->append(7);
	tr->append(6);
	tr->append(1);
 	tr->append(9);

	tr->countNode();
	tr->getParent(5);

}