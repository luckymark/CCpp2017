
class Queue
{
	private:
		int head = 0;
		int tail = 0;
		int data[100];
	public:
		bool isEmpty();
		bool isFull();
		int append(int x);
		int pop();
};

