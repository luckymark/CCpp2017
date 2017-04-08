#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

typedef struct GOOD{
	char *name;
	int num;
}GOOD;

typedef struct Node{
	GOOD good;
	struct Node *pre,*next;
}Node;

Node *head,*tail;

void NewNode();

int main(){
	char name_of_good[101];
	int num_of_good;
	printf("///////////////\n");
	printf("请输入相应数字，并按下回车键来获取您想要的功能！\n");
	printf("1.显示存货列表\n");
	printf("2.入库\n");
	printf("3.出库\n");
	printf("4.退出程序\n");
	printf("//////////////\n");
	int op;
	FILE *fp=fopen("WAREHOUSE.txt","r");
	while(fscanf(fp,"%s%d",name_of_good,&num_of_good)!=EOF){
		NewNode();
		int len=strlen(name_of_good);
		(*tail).good.name=(char*)malloc(sizeof(char)*(len+1));
		strcpy((*tail).good.name,name_of_good);
		(*tail).good.num=num_of_good;
	}
	fclose(fp);
	while(1){
		scanf("%d",&op);
		if(op==1){
			for(Node* p=head;p!=NULL;p=(*p).next){
				printf("%s %d\n",(*p).good.name,(*p).good.num);
			}
		}
		else if(op==2){
			printf("入库,请输入:货物名称 货物数量\n");
			scanf("%s%d",name_of_good,&num_of_good);
			int isFind=0;
			for(Node* p=head;p!=NULL;p=(*p).next){
				if(strcmp((*p).good.name,name_of_good)==0){
					(*p).good.num+=num_of_good;
					isFind=1;
					break;
				}
			}
			if(!isFind){
				NewNode();
				int len=strlen(name_of_good);
				(*tail).good.name=(char*)malloc(sizeof(char)*(len+1));
				strcpy((*tail).good.name,name_of_good);
				(*tail).good.num=num_of_good;
			}
		}
		else if(op==3){
			printf("出库,请输入:货物名称 货物数量\n");
			scanf("%s%d",name_of_good,&num_of_good);
			for(Node* p=head;p!=NULL;p=(*p).next){
				if(strcmp((*p).good.name,name_of_good)==0){
					(*p).good.num-=num_of_good;
					if(!(*p).good.num){
						if((*p).pre!=NULL){
							(*((*p).pre)).next=(*p).next;
						}
						if((*p).next!=NULL){
							(*((*p).next)).pre=(*p).pre;
						}
						if(p==head){
							head=(*p).next;
						}
						if(p==tail){
							tail=(*p).pre;
						}
						free(p);
					}
					break;
				}
			}
		}
		else{
			break;
		}
	}
	fp=fopen("WAREHOUSE.txt","w");
	for(Node* p=head;p!=NULL;p=(*p).next){
		fprintf(fp,"%s %d\n",(*p).good.name,(*p).good.num);
	}
	fclose(fp);
	return 0;
}

void NewNode(){
	Node* Pretail=tail;
	if(tail==NULL){
		head=tail=(Node*)malloc(sizeof(Node));
	}
	else{
		(*tail).next=(Node*)malloc(sizeof(Node));
		tail=(*tail).next;
	}
	if(Pretail!=NULL){
		(*Pretail).next=tail;
	}
	(*tail).pre=Pretail;
	(*tail).next=NULL;
}
