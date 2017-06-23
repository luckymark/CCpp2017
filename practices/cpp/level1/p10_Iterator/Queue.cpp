#include "Queue.h"

Queue::Queue(){
	l = r = size = 0;
}

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

Queue_iterator Queue::begin(){
	return Queue_iterator((*this),(l+1) % MAX_SIZE);
}

Queue_iterator Queue::end(){
	return Queue_iterator((*this),(r+1) % MAX_SIZE);
}

Queue_iterator::Queue_iterator(Queue &a,int whe):tar(a),whe(whe){ }

void Queue_iterator::operator ++ (){
	whe = (whe+1) % MAX_SIZE;
}

void Queue_iterator::operator ++ (int){
	whe = (whe+1) % MAX_SIZE;
}

bool Queue_iterator::operator != (const Queue_iterator & other){
	return whe != other.whe;
}

int Queue_iterator::operator * (){
	return tar.w[whe];
}

void Queue_iterator::set_tar(Queue &a){
	tar = a;
}
