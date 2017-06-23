#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 1005
class Queue_iterator;
class Queue{
	private:
		int w[MAX_SIZE];
		int l,r,size;
	public:
		friend class Queue_iterator;
		Queue();
		void append(int x);
		void pop();
		bool is_empty();
		bool is_full();
		Queue_iterator begin();
		Queue_iterator end();
	
};

class Queue_iterator{
	private:
		Queue &tar;
		int whe;
	public:
		Queue_iterator(Queue &a, int whe);
		void set_tar(Queue &a);
		void operator ++ ();
		void operator ++ (int);
		bool operator != (const Queue_iterator &other);
		int operator *();
};
#endif
