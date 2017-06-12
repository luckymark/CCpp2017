#include "stdafx.h"
#include "Queue_.h"

Queue_::Queue_()//默认构造函数
{
	num = 0;
}

Queue_::~Queue_()//默认析构函数
{
}


void Queue_::one_first()
{
	for (int i = 0; i < length; i++)
	{
		one[i] = 0;
		array[i] = &one[i];
	}
}

void Queue_::one_append()//入队
{
	if (!one_isFull())
	{
		std::cin >> *(array[num]);
		num++;
	}
	else
	{

		std::cout << "full!" << std::endl;
	}
}


void Queue_::one_pop()//出队
{
	if (!one_isEmp())
	{
		std::cout << "出柜："<<*(array[0]) << std::endl;

		int *temp = array[0];

		for (int e = 0; e < length-2; e++)//将array【0】指向原array【1】的数据，即使array【1】数据成为第一个
		{
			array[e] = array[e + 1];
		}

		array[length-1] = temp;
		
		num--;
	}
	else
	{
		std::cout << "emp!" << std::endl;
	}
	
}


bool Queue_::one_isFull()//是否满
{
	if (num == length)return true;
	return false;
}

bool Queue_::one_isEmp()//是否空
{
	if (num == 0)return true;
	return false;
}