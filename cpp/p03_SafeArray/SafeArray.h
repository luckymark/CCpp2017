#ifndef SAFEARRAR_H_
#define SAFEARRAY_H_

class Array
{

public:
	void visit(int pos, int& visitor);		//��������posλ�õ�ֵ����visitor
	void change(int pos, int value);		//��value��ֵ���������posλ��
	Array(int len)
	{
		pt = new int(len);
		this->len = len;

		for (int i = 0; i < len; i++)	//��ʼ��
		{
			*(pt + i) = 0;
		}
	};

private:

	int* pt;
	int len;

};

#endif

