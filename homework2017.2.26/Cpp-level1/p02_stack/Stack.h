class Stack{
	public:
		Stack();
		void sizable(int len);
		void pop();
		void push(int item); 
		bool isFull();
		bool isEmpty();

	
	private:
		int head;
		int *data;
		int length;
};
