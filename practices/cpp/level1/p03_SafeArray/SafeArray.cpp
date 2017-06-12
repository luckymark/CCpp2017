#include "SafeArray.h"
using namespace std;

template<class T>SafeArray<T>::SafeArray(int size)
{
	pr=new T[size];
}

template<class T>SafeArray<T>::SafeArray(T x, int size)
{
	pr = new T[size];
	for (int i = 0; i < size; i++)
	{
		pr[i] = x;
	}
}


template<class T>SafeArray<T>::~SafeArray()
{
	delete [] pr;
}


template<typename T>T SafeArray<T>::operator[](int n)
{
	if (n > size - 1)
	{
		cout << "wrong!" << endl;
		return 0;
	}
	return pr[n];
}

