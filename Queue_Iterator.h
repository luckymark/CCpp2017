template<class T> class Queue_Iterator{
	private:
		T* p;
	public:
		Queue_Iterator(T* p);
		Queue_Iterator operator ++ ();
		Queue_Iterator operator ++ (int);
		Queue_Iterator operator -- ();
		Queue_Iterator operator -- (int);
		T operator * ();
		template <class TT> friend bool operator == (const Queue_Iterator<TT> &a,const Queue_Iterator<TT> &b);
		template <class TT> friend bool operator != (const Queue_Iterator<TT> &a,const Queue_Iterator<TT> &b);
};

template<class T> Queue_Iterator<T>::Queue_Iterator(T* p){
	this->p=p;
}

template<class T> Queue_Iterator<T> Queue_Iterator<T>::operator ++ (){
	return ++p;
}

template<class T> Queue_Iterator<T> Queue_Iterator<T>::operator ++ (int){
	return p++;
}

template<class T> Queue_Iterator<T> Queue_Iterator<T>::operator -- (){
	return --p;
}

template<class T> Queue_Iterator<T> Queue_Iterator<T>::operator -- (int){
	return p--;
}

template<class T> T Queue_Iterator<T>::operator * (){
	return *p;
}

template<class TT> bool operator == (const Queue_Iterator<TT> &a,const Queue_Iterator<TT> &b){
	return a.p==b.p;
}

template<class TT> bool operator != (const Queue_Iterator<TT> &a,const Queue_Iterator<TT> &b){
	return a.p!=b.p;
}
