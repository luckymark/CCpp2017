template <class T> class SafeArray{
	private:
		T* Array;
		T ERROR;
		int capability;
	public:
		SafeArray(int capability,T ERROR);
		~SafeArray();
		T& operator [](int i);//不太安全的随机访问，可以赋值
		bool set(int i,T x);//安全的赋值操作,true:赋值成功;false:赋值失败
		T at(int i);//安全的访问操作,访问非法内存时返回用户定义的一个 T 类型的 ERROR 值
};

template <class T> SafeArray<T>::SafeArray(int capability,T ERROR){
	this->capability=capability;
	this->ERROR=ERROR;
	if(capability){
		Array=new T[capability];
	}
}

template <class T> SafeArray<T>::~SafeArray(){
	if(capability){
		delete[] Array;
	}
}

template <class T> T& SafeArray<T>::operator [](int i){
	return Array[i];
}

template <class T> bool SafeArray<T>::set(int i,T x){
	if(i>=capability){
		return 0;
	}
	Array[i]=x;
	return 1;
}

template <class T> T SafeArray<T>::at(int i){
	if(i>=capability){
		return ERROR;
	}
	return Array[i];
}
