#include "stdafx.h"
#include "Queue_.h"

Queue_::Queue_()//Ĭ�Ϲ��캯��
{
	num = 0;
}

Queue_::~Queue_()//Ĭ����������
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

void Queue_::one_append()//���
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


void Queue_::one_pop()//����
{
	if (!one_isEmp())
	{
		std::cout << "����"<<*(array[0]) << std::endl;

		int *temp = array[0];

		for (int e = 0; e < length-2; e++)//��array��0��ָ��ԭarray��1�������ݣ���ʹarray��1�����ݳ�Ϊ��һ��
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


bool Queue_::one_isFull()//�Ƿ���
{
	if (num == length)return true;
	return false;
}

bool Queue_::one_isEmp()//�Ƿ��
{
	if (num == 0)return true;
	return false;
}