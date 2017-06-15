#include <iostream>
using namespace std;
template <typename T>
class linear_list
{
private:
	int len;
	int room;
	T*v;
public:
	~linear_list();
	linear_list()
	{
		len = 0; room = 0; v = NULL;
	}
	linear_list(int mm);
	int check();
	void insert(int num, T b);
	void del(int num);
	void output();
};
template <typename T>
linear_list<T>::linear_list(int mm)
{
	room = mm;
	v = new T[mm];
	len = 0;
}

template <typename T>
linear_list<T>::~linear_list()
{
	if (v)
	{
		delete[]v;
		v = NULL;
	}
}

template <typename T>
int linear_list<T>::check()
{
	if (0 == len)
		return 0;
	if (0 < len && len < room)
		return 1;
	if (len = room)
		return -1;
}

template <typename T>
void linear_list<T>::output()
{
	cout << "The length is:" << len << " ";
	cout << "elements are:";
	for (int i = 0; i<len; i++)
		cout << v[i] << " ";
	cout << endl;
}

template <typename T>
void linear_list<T>::insert(int num, T b) 
{
	

	int tm = linear_list<T>::check();
	if (tm != -1)
	{
	
		if (num <= 0)
		{
			cout << "there is no such position";
			return;
		}
		else if (num == 1)
		{
			v[0] = b;
			len++;
			return;
		}
		else if (num <= len)
		{
			for (int j = num - 1; j <= len - 1; j++)
				v[j + 1] = v[j];
			v[num - 1] = b;
			len++;
			return;
		}
		else if (num>len)
		{
			v[len] = b;
			len++;
			return;
		}
	}
	else
		cout << "there is no room";
	return;
}

template <typename T>
void linear_list<T>::del(int num)
{
	int md = linear_list<T>::check();
	if (0 == md)
	{
		cout << "there is no elements in the linear list";
		return;
	}
	else 
	{
		
		if (num>len)
		{
			cout << "this position has no element to delete";
		}
		else
		{
			if (len == 1)
				v[0] = ' ';
			for (int k = num - 1; k <= len - 2; k++)
				v[k] = v[k + 1];
		}
		len--;
	}
	return;

}

int main()
{
	linear_list<float>aini(10);
	cout << "the first insert:";
	aini.insert(1, 6.0);
	aini.insert(2, 7.0);
	aini.output();
	cout << "The second insert:";
	aini.insert(3, 9.0);
	aini.output();
	cout << "del first positin:";
	aini.del(1);
	aini.output();
	cout << "del second position:";
	aini.del(2);
	aini.output();
	aini.~linear_list();
	return 0;
}




