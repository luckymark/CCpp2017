#include"tree.h"
int main()
{
	tree trie;
	trie.insert(-1);
	trie.setval(0, 5);
	cout<<trie.totSon(0);
}