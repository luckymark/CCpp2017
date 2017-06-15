#include <cstdio>
#include "Node.h"

int main(){
	Node* root=new Node(1,NULL);
	Node* now=root;
	now=now->append(new Node(2,now));
	now=now->append(new Node(3,now));
	now=now->append(new Node(4,now));
	
	root->append(new Node(5,root));
	
	printf("%d\n",root->GetSubtreeSize());
	return 0;
}
