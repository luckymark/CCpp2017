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
	system("pause");//ԭ����main�����ں����޸��ˣ����Ծ�ֻ����ôһ���ˡ�����
	return 0;
}