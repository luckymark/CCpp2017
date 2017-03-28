struct Queue{
	int queue[1000];
	int head=0,tail=0;
	int length=0;
	bool isFull();
	bool isEmpty();
	void appand(int number);
	void pop();	
};

