#include <stdio.h>

/*int pd(int n)
{
	for(int i=2;i<=n/2;i++)                    //This program is used for drawing a table
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}


int main(int argc, char** argv) 
{
	int a[100];
	int tot=0;
	printf("a[0]=2\n");
	for(int i=3;i<100;i++)
	{
		if(pd(i))
		{
			a[tot++]=i;
			printf("a[%d]=%d;\n",tot,i);
		}
	}
	return 0;
}  */

int main()
{
	int a[25];        //打表
	int judge = 0;
	a[0] = 2;
	a[1] = 3;
	a[2] = 5;
	a[3] = 7;
	a[4] = 11;
	a[5] = 13;
	a[6] = 17;
	a[7] = 19;
	a[8] = 23;
	a[9] = 29;
	a[10] = 31;
	a[11] = 37;
	a[12] = 41;
	a[13] = 43;
	a[14] = 47;
	a[15] = 53;
	a[16] = 59;
	a[17] = 61;
	a[18] = 67;
	a[19] = 71;
	a[20] = 73;
	a[21] = 79;
	a[22] = 83;
	a[23] = 89;
	a[24] = 97;
	for (int i = 4; i <=100; i+=2)
	{
		for (int j = 0; j < 25; j++)
		{
			for (int k = 0; k < 25; k++)
			{
				if (a[j] + a[k] == i)
				{
					judge = 1;
					break;
				}
			}
			if (judge==1)
			{
				cout << i << "满足哥德巴赫猜想" << endl;
				break;
			}
			else if (judge==0)
			{
				return -1;
				printf("Goldbach do not exists");
			}
		judge = 0;
	}
    return 0;
}

