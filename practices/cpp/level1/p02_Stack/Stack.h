#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//#define MAX_SIZE 100
template <class Type>
class Stack{
	private:
		Type *w;
		int top;
		int size;
	public:
		Stack(int _size = 100);
		void push(Type x);
		Type pop();
		bool is_full();
		bool is_empty();
		~Stack();
};

template <class Type>
Stack<Type>::Stack(int _size):size(_size){
	top = 0;
	w = new Type[size];
}

template <class Type>
Stack<Type>::~Stack(){
	delete [] w;
}

template <class Type>
void Stack<Type>::push(Type x){
	w[top++] = x;
}

template <class Type>
Type Stack<Type>::pop(){
	return w[--top];
}

template <class Type>
bool Stack<Type>::is_full(){
	return top == size;
}

template <class Type>
bool Stack<Type>::is_empty(){
	return top == 0;
}


#endif
