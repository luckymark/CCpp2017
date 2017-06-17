	#include <iostream>
	using namespace std;
	#include <stdlib.h>
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	struct node 
	{
		int data;
		int position;
		int book;
		struct node *next;
	 };
	
	int find_five(struct node *head1)
	{
		struct node *t1=head1;
		while(t1!=NULL)
		{
		if(t1->data==5 && t1->book==0)
		{
		t1->book = 1;
		return t1->position;
		}
		t1=t1->next;
	 	}
	return -1;
	}
	int main() 
	{   
	    struct node *head,*head_new,*p,*m,*q,*t,*t1,*t2,*t3;    
	    //×¢ÒâheadÊÇ¿ÕÖ¸Õë 
	    head=NULL;
	     int a,n,mi;
	     cout<<"n is:";
	     cin>>n;
	     cout<<"please input "<<n<<" numbers"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			q=(struct node *)malloc(sizeof(struct node));
			q->book=0;
			q->position=0; 
			q->data=a;
			q->next=NULL;
			if(NULL==head)
			head=q;
			else
			p->next=q;
			p=q;
		}
		 
		t=head;
		cout<<"in order:"; 
	      while(NULL!=t) 
	     {
		 printf(" %d   ",t->data);
		 t=t->next; 
		 }
		 printf("\n");
		 t1=head;
		 t2=t1->next;
		while(NULL!=t2)
		 {
	     t3=t2->next;
		 t2->next=t1;
		 t1=t2;
		 t2=t3; 
		 }
		 head->next=NULL;
		 head_new=t1; 
		 t=head_new;
		 cout<<"out of order:"; 
	      while(t!=NULL) 
	     {
		 printf(" %d   ",t->data);
		 t=t->next; 
		 }
		  t=head_new;
		  
		for(int i=1;i<=n;i++)
		{
		t->position=i;
		 t=t->next; 
		}
		 t=head_new;
		 	for(int i=0;i<=1;i++)
		{
		mi=find_five(t);
		goto mn;
		}
		mn:
		{
		if(mi!=-1)
		cout<<endl<<"the position of five is:"<<mi<<endl;
		else
		cout<<"there is no five"<<endl;
		}
	
	     getchar();getchar();
		return 0;
	}
