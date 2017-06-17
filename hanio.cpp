#include "iostream"
using namespace std;
void hanoi(int n,char src,char mid,char dest)
{
	if(n==1)
	{
	cout<<src<<"->"<<dest<<"  ";
	return;
    }
	hanoi(n-1,src,dest,mid);
	cout<<src<<"->"<<dest<<"  ";
	hanoi(n-1,mid,src,dest);
	return;
}
int main()
{
	cout<<"please input the number of the dishes!\n";
	int n;
	cin>>n;
	hanoi(n,'A','B','C');
	return 0;
} 
