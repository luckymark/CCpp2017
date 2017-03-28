#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 1005
class Queue{
		private:
				int w[MAX_SIZE];
				int l,r,size;
		public:
				void append(int x);
				void pop();
				bool is_empty();
				bool is_full();
};
#endif
