// c++ level1 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <exception>
#include <iostream>
using namespace std;
template <typename T>
class ArrayList
{
	vector<T> vec;
public:
	template<class>
	class Ref {
		ArrayList<T> *array;
		int position;
	public:
		Ref(ArrayList<T> *a, int pos) :array(a), position(pos) {};
		T operator=(T v) {
			if (array->vec.size() <= position)
				array->vec.resize(position + 1);
			array->vec[position] = v;
			return array->vec[position];
		}		 
		operator T() const {
			if (array->vec.size() <= position)
				throw exception();
			return array->vec[position];
		}
		T operator =(Ref<T> v)
		{
			 if (array->vec.size() <=v.position)
				 throw exception();
			 return array->vec[position];
		}
	};
	Ref<T> operator[](int p) { return Ref<T>(this, p); };
};


int main()
{
	ArrayList<int> array;
	int num = 5;
	array[1] = num;
	cout << array[1] << endl;
	try {
		num = array[3];
	}	
	catch (std::exception &e) {
		cout << "array bounds" <<endl;
	}

	try {
		array[1] = array[4];
	}
	catch (std::exception &e) {
		cout << "array bounds" << endl;
	}
}