#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LEN 1*sizeof(Node)
#define MALLOC (Node *)malloc(1*sizeof(Node))
struct Node
{
	int val,position;
	Node *next;
}*head,*last,*node;
int cnt=1,vis[100000];
void Add(int x)
{
	node=MALLOC;
	node->val=x;
	node->position=cnt++;
	node->next=NULL;
	if(last==NULL)
	{
		head=node;last=node;
	}else
	{
		last->next=node;
		last=node;
	}
}
void Reverse()
{
    Node *rev=head;
    Node *t=NULL,*p=NULL;
    t=rev->next;
    while(t->next!=NULL)
    {
        p=t->next;
        t->next=p->next;
        p->next=rev->next;
        rev->next=p;
    }
    Node *pos=rev->next;
    for(;pos!=NULL;pos=pos->next)
    {
        printf("%d ",pos->val);
    }
    printf("%d\n",rev->val);
    return;
}
int Find(int x)
{
    for(Node *pos=head;pos!=NULL;pos=pos->next)
    {
        if(pos->val==x&&(!vis[pos->position]))
        {
            vis[pos->position]=1;
            return pos->position;
        }
    }
    return -1;
}
int main()
{
    memset(vis,0,sizeof(vis));
	head=last=node=NULL;
	for(int i=1;i<=10;i++)Add(i);
	Node *pos=head;
	for(;pos!=NULL;pos=pos->next)
    {
        printf("%d ",pos->val);
    }
    printf("\n");
    Reverse();
    printf("%d\n",Find(5));
    printf("%d\n",Find(5));
	return 0;
}
