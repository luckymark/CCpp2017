#include "stdafx.h"
#include "stack.h"


template <class T> stack<T>::stack(int n)
{
	elems.resize(n);
	this->n = n;
}


template <class T> stack<T>::~stack()
{
}

template<class T> void stack<T>::push(T const &a)
{
	elems.push_back(a);
}

template<class T> void stack<T>::pop() 
{
	if (elems.empty())
	{
		cout << "empty!";
	}
	else
	{
		elems.pop_back();
	}
	return 0;
}


template<class T>T stack<T>::top() const
{
	if (elems.empty())
	{
		cout << "empty!";
		return 0;
	}
	return elems.back();
}


template<class T>
bool stack<T>::isEmp()
{
	if (elems.empty())
	{
		return true;
	}
	return false;
}


template<class T>
bool stack<T>::isFull()
{
	if (elems.size == n)
	{
		return true;
	}
	return false;
}







