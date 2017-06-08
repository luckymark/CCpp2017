const int MAXQUEUE=200005;
class Queue{
private:	
	int head,tail,len,*element;
public:
	Queue(int x=MAXQUEUE);
	~Queue();
	void clear();
	void pop();
	void append(int x);
	int front();
	bool IsFull();
	bool IsEmpty();
};

