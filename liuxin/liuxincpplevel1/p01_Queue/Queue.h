const int MAXQUEUE=200005;
class Queue{
private:	
	int head=0,tail=0,element[MAXQUEUE];
public:	
	void clear();
	void pop();
	void append(int x);
	int front();
	bool isfull();
	bool isempty();
};

