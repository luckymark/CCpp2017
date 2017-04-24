#ifndef CLASSES_H
#define CLASSES_H
class Classes{
	private:
		struct Student{
			char name[20];
			char studentNumber[20];
			int grade;
		}student[151];
		int totalNumber;
		int MAXN;
	
	public:
		void showList();
		void addStudent();
		void deleteStudent();
		void enteringGrade();
};
#endif 
