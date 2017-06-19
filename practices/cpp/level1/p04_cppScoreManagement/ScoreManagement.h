#pragma once
#include <string>
using namespace std;

const int quantity = 5;

struct StudentIdentifies
{
	StudentIdentifies() 
	{
		name = "";
		stID = 0;
		score = 0;
	};
	string	name;
	int		stID;
	int		score;
};

class ScoreManagement
{
private:

public:
	void	ShowSelectionList();
	void	Select(struct StudentIdentifies a[quantity],int option);
	void	Show(StudentIdentifies a[quantity]);
	void	Add(StudentIdentifies a[quantity]);
	void	Delete(StudentIdentifies a[quantity]);
	void	Insert(StudentIdentifies a[quantity]);
	int		Count = 0;
};