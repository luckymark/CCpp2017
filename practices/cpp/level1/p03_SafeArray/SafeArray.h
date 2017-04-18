#include<iostream>
class SafeArray
{
private:
	int array[100];

public:
	void insert(int num,int No);
	void look(int i);
	bool judge(int n);
	SafeArray()
	{
		for (int i = 0;i < 100;i++) {
			array[i] = 0;
		}
	}
};
