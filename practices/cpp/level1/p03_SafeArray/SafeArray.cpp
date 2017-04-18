#include"SafeArray.h"

void SafeArray::insert(int num, int No)
{
	array[No] = num;
}

void SafeArray::look(int i)
{
	using namespace std;
	cout<<array[i]<<endl;
}

bool SafeArray::judge(int n)
{
	return(0 <= n&&n < 100);
}