#ifndef CLASSES_H
#define CLASSES_H

#define MAXN 150
class Classes
{
	private:
		struct
		{
			char name[20];
			char studentNumber[20];
			int grade;
		}student[151];
		int totalNumber;
	
	public:
		void showList();
		void addStudent();
		void deleteStudent();
		void enteringGrade();
};
#endif 
