#include<stdio.h>
#include<stdlib.h>

typedef struct link{
	int value;
	link *next=NULL;
}link;

int main(){
	link *head=NULL;
	link *r=NULL;
	link *pass=NULL;
	int i;
	for (int i=1;i<=100;i++){//创建链表长为100;
		r=new(link);
		r->next=head;
		head=r;
		r=NULL;
	}
	
	for (int i=1;i<=100;i++){//给链表的每一个节点赋值;
		if (i==1) {
			r=head;
		}
		else {
			r=r->next;
		}
		r->value=i;
	}
	r=NULL;
	
	pass=head;
	head=NULL;
	for (int i=1;i<=100;i++){//倒序
		r=pass;
		pass=pass->next;
		r->next=head;
		head=r;
	}
	pass=NULL;
	
	r=head;
	for (i=1;i<=100;i++){//寻找第一个5
		if (r!=NULL){
			if (r->value==5){
				break;
			}
			r=r->next;				
		}
		else{
			i=101;
			break;
		}
	}
	if (i<=100){//输出位置
		printf("%d\n",i);
	}
	else{
		printf("-1\n");
	}
	
	if (r!=NULL){//如果未遍历完全，则开始寻找第二个5
		r=r->next;
		for (;i<=100;i++){
			if (r!=NULL){
				if (r->value==5){
					break;
				}
				r=r->next;				
			}
			else{
				i=101;
				break;
			}
		}
		if (i<=100){//输出位置
			printf("%d\n",i);
		}
		else{
			printf("-1\n");
		}
	}
	
	for (int i=1;i<=100;i++){//释放
		pass=head->next;
		free(head);
		head=pass;
		pass=NULL;
	}
	head=pass=r=NULL;
	return 0;
}