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
	printf("1. ������һ��Ԫ��k\n");
	printf("2. ����������������ʵ���ڵ��value\n");
	printf("3. �����������нڵ㷴��\n");
	printf("4. �ڸ������в��ҵ�һ��ֵΪk�Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻�-1\n");
	printf("5. ������һ��ֵΪk�Ľڵ㣬����ֵͬ��\n");
	printf("6. ��������\n");
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
### ��Ŀ����������
### ����Ҫ��
1. ��main�����д���һ����������
2. ����������������ʵ���ڵ��value��
3. �����������нڵ㷴��
4. �ڸ������в��ҵ�һ��ֵΪ5�Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻أ�1��
5. ������һ��ֵΪ5�Ľڵ㣬����ֵͬ�ϣ�
*/
