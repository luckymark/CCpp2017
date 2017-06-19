#include "ScoreManagement.h"
#include <iostream>
using namespace std;

int main()
{
	ScoreManagement scoremanagement;
	struct StudentIdentifies* pID = new struct StudentIdentifies[quantity];
	cout << "**********************************************************" << endl;
	cout << "Welcome to use the ScoreManagement System" << endl;
	cout << "**********************************************************" << endl;
	cout << "These are actions you can do:" << endl;
	cout << "Please select the choice you want to do:" << endl;

	StudentIdentifies a[quantity];
	while (true)
	{
		scoremanagement.ShowSelectionList();
		int n;
		cin >> n;
		scoremanagement.Select(a,n);
	}
}
