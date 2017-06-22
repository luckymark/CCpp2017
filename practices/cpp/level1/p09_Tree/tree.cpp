#include"tree.h"
tree::tree()
{
	list.clear();
	set.clear();
}

void tree::insert(int i)
{
	Node temp;
	temp.parent = i;
	temp.val = -1;
	list.push_back(temp);
	set.push_back(i);
}

int tree::totSon(int j) {
	int tot = 0;
	for (int i = 0; i < list.size(); i++) {
		if (set[i] == j) {
			tot += totSon(i);
			tot++;
		}
	}
	return tot;
}

void tree::setval(int i,int val)
{
	list[i].val = val;
}

int tree::getparent(int i)
{
	return list[i].parent;
}