const int MAXSTACK=200005;
class Stack{
public:
	Stack(int x=MAXSTACK);
	~Stack();
	void push(int x);
	void pop();
	int top();
	bool IsFull();
	bool IsEmpty();
private:
	int *a;
	int tot;
};

