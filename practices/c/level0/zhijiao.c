#include<stdio.h>

double zj(float a,float b,float c)
{
	float d;
	if(a<b)
	{
		d=a;
		a=b;
		b=d;
		if(a<c)
		{
		    d=a;
		    a=c;
		    c=d;
		}
	}
	else
	{
		if(a<c)
		{
			d=a;
		    a=c;
		    c=d;
		}
	}
	if(a*a==b*b+c*c)
	return printf("Ϊֱ��");
	else 
	return printf("��Ϊֱ��");
	
 } 
 
 void main()
 {
 	float x,y,z,m;
 	printf("��������:\n");
 	scanf("%f%f%f",&x,&y,&z);
 	m=zj(x,y,z);
 	printf("%d",m);
 }
