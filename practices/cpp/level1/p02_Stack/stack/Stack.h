#ifndef CL_STACK_H
#define CL_STACK_H
class Stack
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
    Stack(int a)
    {
        n=new node;
        head=tail=n;
        len=a;
    }
    ~Stack()
    {
        while(count!=0) pop();
        delete n;
    }
    void append(int a)
    {
        if(isFull()) return;
        node* temp=new node;
        temp->next=head->next;
        temp->value=a;
        head->next=temp;
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
#endif //CL_STACK_H
