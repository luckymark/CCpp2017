#include<iostream>
using namespace std;

class queue {
private:
	struct node {
		int num;
		struct node* next;
	};
	int len, count;
	struct node *head, *p, *p_new, *temp;
public:
	queue();
	void append();
	void pop();
	bool if_full();
	bool if_empty();
}Queue;

queue::queue()
{
	int n;
	cin >> n;
	head = NULL;
	len = n;
	count = 0;
}
void queue::append()
{
	head = p = new(struct node);
	p->next=NULL;
	int i = 1;
	p->num = i;
	while (count != len-1) {
		i++;
		p_new = new(struct node);
		p_new->num = i;
		p_new->next=
			head;
		head=p_new;
		count++;
	}
	p = head;
	while (p != NULL) {
		cout << p->num << endl;
		p = p->next;
	}
	cout << "it's full now" << endl;
}
void queue::pop()
{
	while (count != 0) {
		temp = head->next;
		head->next =
			temp->next;
		free(temp);
		count--;
	}
}
bool queue::if_full()
{
	if (count == len) {
		return true;
	}
	else {
		return false;
	}
}
bool queue::if_empty()
{
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}
void main()
{
	queue();
	if (Queue.if_empty()) {
		Queue.append();
	}
	if (Queue.if_full()) {
		Queue.pop();
	}
	else {
		cout << "it's empty now"<< endl;
	}
}
