#include "scoreManagerment.h"

Scoremanage::Scoremanage(void)
{
	name = "NULL";
	grade = 0;
	next = NULL;
}

void Scoremanage::add(void)
{
	Scoremanage *L = this;
	while (L->next != NULL)
	{
		L = L->next;
	}
	L->next = new Scoremanage;
	std::cout << "please input a student's name: ";
	getline(std::cin, L->next->name);
}

void Scoremanage::del(int i)
{
	Scoremanage * L = this;
	Scoremanage * D;
	for (int t = 0; t < i-1; t++);
	{
		L = L->next;
	}
	D = L->next;
	L->next = D->next;
	delete D;
}

void Scoremanage::setgrade(int i)
{
	Scoremanage * L = this;
	for (int t = 0; t < i; ++t)
	{
		if (L != NULL) 
		{
			L = L->next;
		}
	}
	if (L != NULL)
	{
		std::cout << L->name << " grade: ";
		std::cin >> L->grade;
	}
	else
	{
		std::cout << "error, out of edge,please input q";
	}
	
}

void Scoremanage::setid(void)
{
	Scoremanage *L = this;
	int count = 0;
	while (L != NULL)
	{
		L->id = count;
		count++;
		L = L->next;
	}
}

void Scoremanage::show(void)
{
	Scoremanage *L = this->next;
	setid();
	while (L != NULL)
	{
		std::cout << L->id << " name: " << L->name << " grade: " << L->grade << std::endl;
		L = L->next;
	}
}

