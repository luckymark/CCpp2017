#include"Canvas.h"

int main(void)
{
	using namespace std;
	Canvas a;
	for (int i = 0; i < 10; ++i)
	{
		a.setShape(i);
	}
	a.show();
	system("pause");//原来的main函数在后面修改了，所以就只有这么一点了。。。
	return 0;
}