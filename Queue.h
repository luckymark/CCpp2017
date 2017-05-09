template<class T,int SIZE> class Queue{
	private:
		T q[SIZE+1];
		int head=0,tail=0,cnt=0;
	
	public:
		bool append(T x);
		T pop();
		bool isEmpty();
		bool isFull();
		void clear();
};

template<class T,int SIZE> bool Queue<T,SIZE>::append(T x){
	if(cnt<SIZE){
		q[tail]=x;
		tail=(tail+1)%(SIZE+1);
		++cnt;
		return 1;
	}
	return 0;
}

template<class T,int SIZE> T Queue<T,SIZE>::pop(){
	int Prehead=head;
	head=(head+1)%(SIZE+1);
	--cnt;
	return q[Prehead];
}

template<class T,int SIZE> bool Queue<T,SIZE>::isEmpty(){
	return cnt==0;
}

template<class T,int SIZE> bool Queue<T,SIZE>::isFull(){
	return cnt==SIZE;
}

template<class T,int SIZE> void Queue<T,SIZE>::clear(){
	while(cnt){
		pop();
	}
}
