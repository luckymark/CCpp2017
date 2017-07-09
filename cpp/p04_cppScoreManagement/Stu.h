#include<iostream>
#ifndef STU_H_
#define STU_H_

class Stu;
class Queue
{
public:


	friend class Stu;


	void list();
	void AddStu();
	void AddStu(FILE* pt,char* name);
	void DelStu(char* name);
	Stu* find(char* name);
	void ChangeInfo();
	void load(FILE* pt);
	void save(FILE* pt);
	void sort();

	void menu();
	Queue()
	{
		count = 0;
		front = rear = NULL;
	}
private:
	Stu* front;
	Stu* rear;
	int count;
};

class Stu
{
private:
	char name[11];
	char course[11];
	int score;
	Stu* next;
	

public:
	friend class Queue;

	void AddName(char* name);
	void AddCourse(char* course);
	void AddScore(int score);

	void info();

	Stu()
	{
		this->next = NULL;
	}
};

#endif