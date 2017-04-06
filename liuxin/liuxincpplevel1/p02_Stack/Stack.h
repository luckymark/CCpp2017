const int MAXSTACK=200005;
class Stack{
private:
	int tot,*element;
public:
	Stack(int x=MAXSTACK);
	~Stack();
	void push(int x);
	void pop();
	int top();
	bool IsFull();
	bool IsEmpty();
};

