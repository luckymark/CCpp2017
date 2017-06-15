
// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#define object_max 20
using namespace std;
template <class T>
class Sort//抽象成sort 类
{
public:
	virtual void input() = 0;
	virtual void sorting() = 0;
	virtual void output() = 0;
	virtual void sort_quick_sort(int left, int right) = 0;
	virtual int get_Len() = 0;
protected:
	T *v;
	int room;//总空间
	int length;//数据总量
};


template <class T>
class End      //end 函数用来统一操作
{
public:
	static Sort<T>* sort0[object_max];////定义抽象类的指针
	static int object_quantity;//静态变量，用作对象计数器
	void action();
};


template <class T>
int End<T>::object_quantity = 0;//初始化静态变量


template <class T>
Sort<T>*  End<T>::sort0[object_max] = { NULL };
	


template <class T>
void End<T>::action()
{
	for (int i = 0; i < object_quantity; i++)
	{
		sort0[i]->input();
		sort0[i]->sorting();
		sort0[i]->output();
		sort0[i]->sort_quick_sort(0, sort0[i]->get_Len() - 1);
	}
}



//冒泡排序
template <class T>
class MaoPao_Sort:public Sort<T>,public End<T>
{
public:
	MaoPao_Sort(int room);
	~MaoPao_Sort();
	void input();
	void sorting();
	 void output();
	 int get_Len();
	 void sort_quick_sort(int left, int right);
};


template <class T>
int MaoPao_Sort<T>::get_Len()
{
	return 0;
}


template <class T>
void MaoPao_Sort<T>::sort_quick_sort(int left, int right)
{
	return;
}

template <class T>
MaoPao_Sort<T>::MaoPao_Sort(int room)
{
	v = new T[room];  
	this->room = room;
	length = 0;
	sort0[object_quantity] = this;//使得基类指针指向当前建立的对象
	object_quantity++;//对象计数器加一
}


template <class T>
MaoPao_Sort<T>::~MaoPao_Sort()
{
	delete[] v;
	v = NULL;
}



template <class T>
void MaoPao_Sort<T>::input()
{
	int a;
	cout << "please input.if you have finished,please enter -1" << endl;
	while (1)
	{
		for (int i = 0; i < room; i++)
		{
			cin >> a;
			if (a == -1)
			{
				return;
			}
			v[i] = a;
			length++;
		}
	}
	cout << "there is no enough room";
}



template <class T>
void MaoPao_Sort<T>::sorting()
{
	if (length<2)
	{
		cout << "you should input 2 numbers at least!" << endl;
		return;
	}
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - i - 1;j++)
		{
			if (v[j] > v[j + 1])
			{
				int t = v[j];
				v[j] = v[j+1];
				v[j+1] = t;
			}
		}
	}
	return;
}


template <class T>
void MaoPao_Sort<T>::output()
{
	if (length<2)
	{
		return;
	}
	cout << "The result of MaoPao sort:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << v[i] << "    ";
	}
	cout << endl;
	return;
}



//选择排序
template <class T>
class Select_Sort:public Sort<T>,public End<T>
{
public:
	Select_Sort(int room);
	~Select_Sort();
	void input();
	void sort_quick_sort(int left, int right);
	void sorting();
	void output();
	int get_Len();
};




template <class T>
int Select_Sort<T>::get_Len()
{
	return 0;
}


template <class T>
void Select_Sort<T>::sort_quick_sort(int left, int right)
{
	return;
}

template <class T>
Select_Sort<T>::Select_Sort(int room)
{
	v = new T[room];
	this->room = room;
	length = 0;
	sort0[object_quantity]=this;//使得基类指针指向当前建立的对象
	object_quantity++;//对象计数器加一
}



template <class T>
Select_Sort<T>::~Select_Sort()
{
	delete[] v;
	v = NULL;
}



template <class T>
void Select_Sort<T>::input()
{
	int a;
	cout << "please input.if you have finished,please enter -1" << endl;
	while (1)
	{
		for (int i = 0; i < room; i++)
		{
			cin >> a;
			if (a == -1)
			{
				return;
			}
			v[i] = a;
			length++;
		}
	}
	cout << "there is no enough room";
}



template <class T>
void Select_Sort<T>::sorting()
{
	if (length < 2)
	{
		cout << "you should input 2 numbers at least!" << endl;
		return;
	}
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (v[j] >= v[min])
			{
				continue;
			}
			min = j;//最小值在min里面
		}
		int t = v[i];
		v[i] = v[min];
		v[min] = t;
	}
	return;
}





template <class T>
void Select_Sort<T>::output()
{
	if (length<2)
	{
		return;
	}
	cout << "The result of the Select_Sort:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << v[i] << "    ";
	}
	cout << endl;
	return;
}

//希尔插入排序
template <class T>
class XierInsert_Sort:public Sort<T>, public End<T>
{
public:
	XierInsert_Sort(int room);
	~XierInsert_Sort();
	void input();
	void sorting();
	void output();
	void sort_quick_sort(int left, int right);
	int get_Len();

private:
	T *v;
	int room;//总空间
	int length;//数据总量
	int begin;
};


template <class T>
int  XierInsert_Sort<T>::get_Len()
{
	return 0;
}



template <class T>
void XierInsert_Sort<T>::sort_quick_sort(int left, int right)
{
	return;
}


template <class T>
XierInsert_Sort<T>::XierInsert_Sort(int room)
{
	v = new T[room];
	this->room = room;
	length = 0;
	begin = 20;
	sort0[object_quantity] = this;//使得基类指针指向当前建立的对象
	object_quantity++;//对象计数器加一
}

template <class T>
XierInsert_Sort<T>::~XierInsert_Sort()
{
	delete[] v;
	v = NULL;
}

template <class T>
void XierInsert_Sort<T>::input()
{
	int a;
	cout << "please input.if you have finished,please enter -1" << endl;
	while (1)
	{
		for (int i = begin; i < room; i++)//预留空间,以防比第一个元素小的元素太多;
		{
			cin >> a;
			if (a == -1)
			{
				return;
			}
			v[begin + length] = a;
			length++;
		}
	}
	cout << "there is no enough room";
}



template <class T>
void XierInsert_Sort<T>::sorting()
{
	if (length< 2)
	{
		cout << "you should input 2 numbers at least!" << endl;
		return;
	}
	int left, mid, i, right;
	for (i = begin + 1; i < length + begin; i++)
	{
		int temp = v[i];
		left = begin;
		right = i;
		if (v[i] >= v[i - 1])
		{
			continue;
		}
		if (v[i] <= v[begin])
		{
			for (int j = i; j < length + begin - 1; j++)//前移，
			{
				v[j] = v[j + 1];
			}
			i--;//前移后后一个成了前一个
			v[--begin] = temp;
			continue;
		}
		int t;

		while (left < right)//找位置
		{
			t = 0;//用来标记
			mid = (right + left) / 2;
			if (v[i] == v[mid])
			{
				t = -1;
				break;
			}
			if (v[i] <v[mid])
			{
				right = mid;
				t = 1;
			}
			if (v[i] > v[mid])
			{
				if (right != left + 1)
				{
					t = -1;
					left = mid;
				}
				else
				{
					t = -1;
					break;
				}
			}
		}
		if (t == 1)
		{
			for (int k = i; k > mid; k--)
			{
				v[k] = v[k - 1];
			}
			v[mid] = temp;
			continue;
		}
		if (t == -1)
		{
			for (int m = i; m >= mid + 2; m--)
			{
				v[m] = v[m - 1];
			}
			v[mid + 1] = temp;
			continue;
		}
	}

	return;
}


template <class T>
void XierInsert_Sort<T>::output()
{
	if (length<2)
	{
		return;
	}
	cout << "The result of XierInsert_Sort:" << endl;
	for (int i = begin; i < begin + length; i++)
	{
		cout << v[i] << "    ";
	}
	cout << endl;
}





//快速排序
template <class T>
class Quick_Sort :public Sort<T>, public End<T>
{
public:
	Quick_Sort(int room);
	~Quick_Sort();
	void input();
	void sort_quick_sort(int left, int right);
	void output();
	void sorting();
	int get_Len();


private:
	T *v;
	int room;//总空间
	int length;//数据总量
};



template <class T>
void Quick_Sort<T>::sorting()
{
	return;
}


template <class T>
Quick_Sort<T>::Quick_Sort(int room)
{
	v = new T[room];
	this->room = room;
	length = 0;
	sort0[object_quantity] = this;//使得基类指针指向当前建立的对象
	object_quantity++;//对象计数器加一
}




template <class T>
int Quick_Sort<T> ::get_Len()
{
	return length;
}

template <class T>
Quick_Sort<T>::~Quick_Sort()
{
	delete[] v;
	v = NULL;
}




template <class T>
void Quick_Sort<T>::input()
{
	int a;
	cout << "please input.if you have finished,please enter -1" << endl;
	while (1)
	{
		for (int i = 0; i < room; i++)//预留空间,以防比第一个元素小的元素太多;
		{
			cin >> a;
			if (a == -1)
			{
				return;
			}
			v[i] = a;
			length++;
		}
	}
	cout << "there is no enough room";
}



template <class T>
void Quick_Sort<T>::sort_quick_sort(int left, int right)
{
	if (length< 2)
	{
		cout << "you should input 2 numbers at least!" << endl;
		return;
	}
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}
	temp = v[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (v[j] >= temp&&i < j)
		{
			j--;
		}
		while (v[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = v[i];
			v[i] = v[j];
			v[j] = t;
		}
	}
	v[left] = v[i];
	v[i] = temp;
	sort_quick_sort(left, i - 1);
	sort_quick_sort(i + 1, right);
	return;
}


template <class T>
void Quick_Sort<T>::output()
{
	if (length<2)
	{
		return;
	}
	cout << "The result of quickesort:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << v[i] << "    ";
	}
	cout << endl;
}

int main()
{
	End<int> end;//建立抽象类指针以及对象计数器
	Quick_Sort<int> Quicker(100);
	MaoPao_Sort<int> MaoPao(100);
	Select_Sort<int> Select(100);
	XierInsert_Sort<int> Xier(100);
	end.action();
	return 0;
}

