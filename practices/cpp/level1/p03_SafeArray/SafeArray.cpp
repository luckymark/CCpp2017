#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
template<class T>
class SafeArray
{
	private:
		T *array;
		int size,pos;
	public:
		SafeArray(int t):size(t)
		{
			size=t;
			pos=0;
			array=new T[size];
		}
		~SafeArray()
		{
			delete [] array;
		}
		T &operator [](int n) throw(const char *)
		{
			if(n<0||n>=size) throw("out of range");
			else return *(array+n);
		}
		void push_back(int x)
		{
			*(array+pos)=x;
			pos++;
		}
};
int main()
{
	SafeArray<int> a(8);
	a.push_back(1);
	a.push_back(2);
	try{
		cout<<a[-1]<<endl;	
	}catch(const char *Err)
	{
		cout<<Err<<endl;
	}
	cout<<a[0]<<endl;
	return 0;
}
