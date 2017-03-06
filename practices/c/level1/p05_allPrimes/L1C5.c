# include<stdio.h>
# include<time.h>
# include<math.h>
# include<stdbool.h>
bool is_primer(int i)
{
	for(int k=2; k<=sqrt(i); k++)
	{
		if(i%k == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long op,ed;
	op=clock();
	//cout<<"1 "<<endl;
	for(int i=2; i<101; i++){
		if(is_primer(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}
