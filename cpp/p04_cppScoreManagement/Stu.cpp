#include<iostream>
#include"Stu.h"

using namespace std;

void Stu::AddName(char* name)
{
	strcpy_s(this->name,11,name);
}

void Stu::AddCourse(char* course)
{
	strcpy_s(this->course,11, course);
}

void Stu::AddScore(int score)
{
	this->score = score;
}


void Stu::info()
{
	cout <<"student info: "<< endl << "name: " << this->name << " " << "course: " << this->course << " " << "score: " << this->score << endl;
}

void Queue::AddStu()
{
	Stu* pt = new Stu;
	count++;

	if (front == NULL)
		front = pt;
	else
		rear->next = pt;

	rear = pt;

	char temp[11] ;
	cout << "name:";
	cin.get(temp,11);

	for (int i = 0; i < 11; i++)
	{
		if (temp[i] == ' ')
		{
			temp[i] = '\0';
			break;
		}
	}

	while (cin.get() != '\n');
	pt->AddName(temp);
	cout << "course: ";
	cin.get(temp, 11);
	for (int i = 0; i < 11; i++)
	{
		if (temp[i] == ' ')
		{
			temp[i] = '\0';
			break;
		}
	}
	while (cin.get() != '\n');
	pt->AddCourse(temp);
	cout << "score:";
	int score;
	cin >> score;
	pt->AddScore(score);

	
}


Stu* Queue::find(char* name)	
{
	Stu* pre=front;
	for (Stu* pt = front; pt != NULL; pt = pt->next)
	{
		if (strcmp(name, pt->name) == 0)
		{
			pt->info();
			return pre;			//pre返回目标学生前一个,若目标在队列首，pre==pt；
		}
		pre = pt;
	}
	cout << "no such student" << endl;
	return NULL;
}


void Queue::DelStu(char* name)
{
	if (strcmp(name, front->name) == 0)	//在队首
	{
		Stu* temp = front;
		front->info();
		front = front->next;
		delete(temp);
	}
	else
	{
		Stu*pt = find(name);	//pt是目标学生前一个
		if (pt != NULL)
		{
			if (pt->next->next == NULL)	//目标在队尾
			{
				rear = pt;
				delete(pt->next);
				pt->next = NULL;
			}
			else
			{
				Stu* del = pt->next;
				pt->next = pt->next->next;
				delete(del);
			}

		}
	}
	cout << "is deleted." << endl;
}

void Queue::list()
{
	if (front == NULL)
	
		cout << "empty list." << endl;
	else
	{
		for (Stu* temp = front; temp != NULL; temp = temp->next)
			cout << "name: " << temp->name << " " << "course: " << temp->course << " " << "score: " << temp->score << endl;
	}
}

void Queue::menu()
{
	cout << endl << "'a' to add stuent, 'c' to change info, 'd' to delete student, 'f' to find student,\n'l' to list all students, 's' to sort by score, 'q' to save and quit." << endl;
}

void Queue::ChangeInfo()
{
	

	if (front == NULL)
		cout << "empty list" << endl;
	else
	{
		cout << "name to change: ";
		char temp[11];
		cin.get(temp, 11);
		for (int i = 0; i < 11; i++)
		{
			if (temp[i] == ' ')
			{
				temp[i] = '\0';
				break;
			}
		}

		while (cin.get() != '\n');
		if (strcmp(temp, front->name) == 0)	//在队首
		{
			cout << "name: ";
			cin.get(temp, 11);
			for (int i = 0; i < 11; i++)
			{
				if (temp[i] == ' ')
				{
					temp[i] = '\0';
					break;
				}
			}

			while (cin.get() != '\n');
			front->AddName(temp);
			cout << "course: ";
			cin.get(temp, 11);
			for (int i = 0; i < 11; i++)
			{
				if (temp[i] == ' ')
				{
					temp[i] = '\0';
					break;
				}
			}

			while (cin.get() != '\n');
			front->AddCourse(temp);
			cout << "score: ";
			int score;
			cin >> score;
			front->AddScore(score);
		}
		else
		{
			Stu* pt = find(temp);

			cout << "name: ";
			cin.get(temp, 11);
			for (int i = 0; i < 11; i++)
			{
				if (temp[i] == ' ')
				{
					temp[i] = '\0';
					break;
				}
			}

			while (cin.get() != '\n');
			pt->next->AddName(temp);
			cout << "course: ";
			cin.get(temp, 11);
			for (int i = 0; i < 11; i++)
			{
				if (temp[i] == ' ')
				{
					temp[i] = '\0';
					break;
				}
			}

			while (cin.get() != '\n');
			pt->next->AddCourse(temp);
			cout << "score: ";
			int score;
			cin >> score;
			pt->next->AddScore(score);
		}
	}
}

void Queue::load(FILE* pt)
{
	char temp[11];
	while (fscanf_s(pt, "%s", temp,10)!=EOF)
	{
		AddStu(pt,temp);
		count++;
	}
}

void Queue::AddStu(FILE* pt,char* name)
{
	Stu* temp = new Stu;

	if (front == NULL)
		front = temp;
	else
		rear->next = temp;

	rear = temp;

	char course[11];
	int score;
	fscanf_s(pt, "%s", course,10);
	fscanf_s(pt, "%d", &score);
	temp->AddName(name);
	temp->AddCourse(course);
	temp->AddScore(score);
}

void Queue::save(FILE* pt)
{
	for (Stu* temp = front; temp != NULL; temp = temp->next)
	{
		fprintf(pt, "%s ", temp->name);
		fprintf(pt, "%s ", temp->course);
		fprintf(pt, "%d ", temp->score);
		fprintf(pt, "%c", '\n');
	}
}

void Queue::sort()
{
	int n = count;

	struct room
	{
		char name[11];
		char course[11];
		int score;
	};
	struct room* pt = new struct room[n];

	int i = 0;
	for (Stu* temp = front; temp != NULL; temp = temp->next)
	{
		strcpy_s((pt + i)->name,temp->name);
		strcpy_s((pt + i)->course,temp->course);
		(pt + i)->score = temp->score;
		i++;
	}

	for (int i = 0; i<n - 1; i++)
	{
		for (int j = 0; j<n - 1 - i; j++)
		{
			if ((pt+j)->score < (pt+j+1)->score)
			{
				struct room temp = *(pt+j);
				*(pt + j) = *(pt + j + 1);
				*(pt + j + 1) = temp;
			}
		}
	}

	i = 0;
	for (Stu* temp = front; temp != NULL; temp = temp->next)
	{
		temp->AddName((pt + i)->name);
		temp->AddCourse((pt + i)->course);
		temp->score = (pt+i)->score;
		i++;
	}

}