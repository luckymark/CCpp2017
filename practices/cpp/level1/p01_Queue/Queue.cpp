#include "Queue.h"
void Queue::append(int x){
		r++;size++;
		r %= MAX_SIZE;
		w[r] = x;
}
void Queue::pop(){
		l++;size--;
		l %= MAX_SIZE;
}
bool Queue::is_empty(){
		return size == 0;
}
bool Queue::is_full(){
		return size == (MAX_SIZE - 1);
}
