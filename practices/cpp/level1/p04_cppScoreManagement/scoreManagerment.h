#pragma once
#ifndef scoreManagerment_H_
#define scoreManagerment_H_
#include<iostream>
#include<string>
class Scoremanage
{
private:
	std::string name;
	int id;
	int grade;
	Scoremanage *next;
public:
	Scoremanage(void);
	void add(void);
	void del(int i);
	void setgrade(int i);
	void setid(void);
	void show(void);
};
typedef Scoremanage* List;
#endif // !scoreManagerment_H_
