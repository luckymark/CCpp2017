#ifndef STUDENT_H
#define STUDENT_H

class student
{
	public:
		student();
		void menu();
		void add();
		void remove();
		void find();
		int exit();
		
	protected:
		struct information 
		{
			string name;
			int score;
			string ID;
		};
		information student0[100];
		int choice;
		int count;
		int existence; 
};

#endif
