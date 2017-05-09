template<class T> class Stack
{
	private:
		T* s;
		int p,capability;
		
	public:
		Stack(int capability);
		~Stack();
		T pop();
		bool push(T x);
		bool isEmpty();
		bool isFull();
		void clear();
};

template<class T> Stack<T>::Stack(int capability){
	p=0;
	this->capability=capability;
	if(capability){
		s=new T[capability];
	}
}

template<class T> Stack<T>::~Stack(){
	if(capability){
		delete[] s;
	}
}

template<class T> T Stack<T>::pop(){
	return s[--p];
}

template<class T> bool Stack<T>::push(T x){
	if(p<capability){
		s[p++]=x;
		return 1;
	}
	else{
		return 0;
	}
}

template<class T> bool Stack<T>::isEmpty(){
	return p==0;
}

template<class T> bool Stack<T>::isFull(){
	return p==capability;
}

template<class T> void Stack<T>::clear(){
	while(p){
		pop();
	}
}
