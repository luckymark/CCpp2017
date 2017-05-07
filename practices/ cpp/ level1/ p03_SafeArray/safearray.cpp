#include<iostream>
using namespace std;

class SafeArray {
private:
	int num;
	int index;
	int len;
	int *p;
public:
	SafeArray();
	bool if_out();
	void give_value();
	~SafeArray();
}safearray;

SafeArray::SafeArray()
{
	int n;
	cin >> n;
	len = n;
	index = 0;
	p = new int[len];
}
bool SafeArray::if_out()
{
	if (index >= len) {
		return 1;
	}
	else {
		return 0;
	}
}
void SafeArray::give_value()
{
	while (1) {
		int value;
		cin >> value;
		if (if_out()) {
			cout << "out of range!" << endl;
			break;
		}
		else {
			SafeArray::p[index] = value;
			index++;
		}
	}
}
SafeArray::~SafeArray()
{
	delete p;
}

void main()
{
	safearray.give_value();
}
