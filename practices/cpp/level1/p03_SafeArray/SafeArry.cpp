# include<iostream>
# include<time.h>
# include<stdlib.h>
using namespace std;

class SafeArry {
private:
	int array[300];
public:
	SafeArry();
	~SafeArry();
	void put(int vrl);
	bool get(int num);
};

SafeArry::SafeArry()
{
	memset(array, 0, 300);
}
void SafeArry::put(int vrl)
{
	for (int i = 0; i < 300; i++) {
		array[i] = vrl;
	}
}
bool SafeArry::get(int num)
{
	if (num - 1 > 299||num<1) {
		cout << "ilegal visit!!" << endl;
		cout << "please input again:"<<endl;
		return false;
	}
	else {
		cout << array[num] << endl;
		return true;
	}
}
SafeArry::~SafeArry()
{

}
int main()
{
	SafeArry safearry;
	for (int i = 0; i < 300; i++) {
		srand(time(0));
		safearry.put(rand());
	}
	cout << "the arry has been generated." << endl;
	cout << "please input the num you want to visit:" << endl;
	int num;
	cin >> num;
	while (1) {
		if (safearry.get(num)) {
			break;
		}
		else {
			cin >> num;
		}
	}
	
	system("pause");
	return 0;
}
