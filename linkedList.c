#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node *head,*tail;

void push_back(int val);
void reverse();
int find(int p,int val);//return the position of the pth time occurrence of val
void swap(Node **a,Node **b);

int main(){
	int n,x;
	//input
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		push_back(x);
	}
	reverse(NULL,head);
	swap(&head,&tail);
	printf("The Position of the First 5 is %d\n",find(1,5));
	printf("The Position of the Second 5 is %d\n",find(2,5));
	return 0;
}

void push_back(int val){
	if(tail==NULL){
		head=tail=(Node*)malloc(sizeof(Node));
	}
	else{
		(*tail).next=(Node*)malloc(sizeof(Node));
		tail=(*tail).next;
	}
	(*tail).value=val;
	(*tail).next=NULL;
}

void reverse(Node *pre,Node* cur){
	if(cur==NULL){
		return;
	}
	reverse(cur,(*cur).next);
	(*cur).next=pre;
}

int find(int p,int val){
	int j=1;
	int cnt=0;
	for(Node* i=head;i!=NULL;i=(*i).next,++j){
		if((*i).value==val){
			++cnt;
			if(cnt==p){
				return j;
			}
		}
	}
	return -1;
}

void swap(Node **a,Node **b){
	Node *t=*a;
	*a=*b;
	*b=t;
}
