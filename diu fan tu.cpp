#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    int FatherAge=0;
	for(double i=1.0;i<100;i++)           //¶ù×ÓÄêÁä 
	{
		for(double j=1;j<200;j++)       //¸¸Ç×ÄêÁä 
		{
			if((1.0/6.0*j+1.0/12.0*j+1.0/7.0*j+5+i+4==j)&&(2*i==j))
			{
				FatherAge=j;
			}
		}
	}
	cout<<"¶ù×ÓËÀÊ±¶ª·¬Í¼ÄêÁäÎª"<<FatherAge-4<<endl; 
	return 0;
}
