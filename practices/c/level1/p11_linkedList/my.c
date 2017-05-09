#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node *next;
	int w;
}head;
struct Node* new_node(){
	struct Node *now = (struct Node*) malloc(sizeof(struct Node));
	now -> w = 0;
	now -> next = NULL;
	return now;
}
void build(){
	int n; scanf("%d",&n);
	struct Node *cur = &head;
	for(int i = 1; i <= n; i++){
		int now; scanf("%d",&now);
		struct Node *next = new_node();
		cur -> next = next;
		cur = cur -> next;
		cur -> w = now; 
	}
}
struct Node* reverse(struct Node *cur){
	if(cur -> next == NULL){
		head.next = cur;
		return cur;
	}
	struct Node *now = reverse(cur -> next);
	now -> next = cur;
	cur -> next = NULL;
	return cur;
}
int find(int x,int num){
	int cnt = 0;
	int flag = 0;
	struct Node *cur = head.next;
	while(cur != NULL){
		cnt++;
		if(cur -> w == 5) flag++;
		if(flag == num) break;
		cur = cur -> next;
	}
	if(cur != NULL) return cnt;
	return -1;
}
void show(){
	struct Node *cur = head.next;
	while(cur != NULL){
		printf("%d %p\n", cur -> w, cur);
		cur = cur -> next;
	}
	printf("\n");
}
int main(){
	build();
	struct Node *last = reverse(head.next);
	int ans1 = find(5,1);
	int ans2 = find(5,2);
	printf("%d\n",ans1);
	printf("%d\n",ans2);
	return 0;

}
