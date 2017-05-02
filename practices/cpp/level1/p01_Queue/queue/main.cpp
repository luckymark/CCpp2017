#ifndef CL_QUEUE_H
#define CL_QUEUE_H
class queue
{
    private:
        struct node
        {
            int value=0;
            node* next=NULL;
        };
        int len,count=0;
        node *tail,*head,*n;
    public:
        queue(int a)
        {
            n=new node;
            head=tail=n;
            len=a;
        }
        ~queue()
        {
            while(count!=0) pop();
            delete n;
        }
        void append(int a)
        {
            if(isFull()) return;
            tail->next=new node;
            tail=tail->next;
            tail->value=a;
            count++;
        }
        int pop()
        {
            if(isEmpty()) return NULL;
            node* temp=new node;
            temp=head->next;
            head->next=temp->next;
            int a=temp->value;
            delete temp;
            count--;
            return a;
        }
        bool isFull()
        {
            if(count==len) return true;
            return false;
        }
        bool isEmpty()
        {
            if(count==0) return true;
            return false;
        }
};
#endif //CL_QUEUE_H
