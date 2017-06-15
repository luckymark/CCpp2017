template <class T> class SafeArray{
	private:
		T* Array;
		T ERROR;
		int capability;
	public:
		SafeArray(int capability,T ERROR);
		~SafeArray();
		T& operator [](int i);//��̫��ȫ��������ʣ����Ը�ֵ
		bool set(int i,T x);//��ȫ�ĸ�ֵ����,true:��ֵ�ɹ�;false:��ֵʧ��
		T at(int i);//��ȫ�ķ��ʲ���,���ʷǷ��ڴ�ʱ�����û������һ�� T ���͵� ERROR ֵ
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
