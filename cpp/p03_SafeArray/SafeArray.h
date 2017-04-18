#ifndef SAFEARRAR_H_
#define SAFEARRAY_H_

class Array
{

public:
	void visit(int pos, int& visitor);		//将数组中pos位置的值赋给visitor
	void change(int pos, int value);		//将value的值赋到数组的pos位置
	Array(int len)
	{
		pt = new int(len);
		this->len = len;

		for (int i = 0; i < len; i++)	//初始化
		{
			*(pt + i) = 0;
		}
	};

private:

	int* pt;
	int len;

};

#endif

