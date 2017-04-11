class Stack
{
	private:
		int* s;
		int p,capability;
		
	public:
		Stack(int capability);
		~Stack();
		int pop();
		bool push(int x);
		bool isEmpty();
		bool isFull();
		void clear();
};
