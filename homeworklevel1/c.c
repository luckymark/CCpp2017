#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

const int MAXN=200005;
int n,m;
struct node{
        int x;
        node* next;
	node(int xx=0):x(xx){}
}stack[MAXN];
int main(){
	printf("Please input the total number of the link list you want to create!\n");
	n=read();
	node* head=NULL,tail=NULL;
	for (int i=1;i<=n;++i) {
		int k=read();
		node* p=new node(k);
		if (head==NULL) head=p;
		if (tail!=NULL) tail.next=p;
		tail=p;
	}
	printf("Thanks\nPlease input the operation number\n");
	printf("1. 继续加一个元素k\n");
	printf("2. 遍历该链表，依次现实各节点的value\n");
	printf("3. 将该链表所有节点反序\n");
	printf("4. 在该链表中查找第一个值为k的节点，如果找到则返回该节点的序号，否则返回-1\n");
	printf("5. 查找下一个值为k的节点，返回值同上\n");
	printf("6. 结束程序\n");
	node* q;
	while () {
		int k=read();
		switch (k) {
			case 1:{
				node* p=new node(read());
				if (head==NULL) head=p;
				if (tail!=NULL) tail.next=p;
				tail=p; n++;
				break;
			}
			case 2:{
				for (node* p=head;p!=NULL;p=(*p)->next) printf("%d ",(*p)->x);
				printf("\n%d\n",n);
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			case 6:return 0;
		}
	}
	
        return 0;
}

/*
### 题目：单向链表
### 功能要求：
1. 在main函数中创建一个单向链表；
2. 遍历该链表，依次现实各节点的value；
3. 将该链表所有节点反序；
4. 在该链表中查找第一个值为5的节点，如果找到则返回该节点的序号，否则返回－1；
5. 查找下一个值为5的节点，返回值同上；
*/
