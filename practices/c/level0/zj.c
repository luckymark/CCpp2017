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
		d=a;
		a=c;
		c=d;
	}
	else
	{
		if(a<c)
		d=a;
		a=c;
		c=d;
	}
	if(a*a==b*b+c*c)
	return printf("为直角");
	else 
	return printf("不为直角");
	
 } 
 
 void main()
 {
 	float x,y,z,m;
 	printf("输入三边:\n");
 	scanf("%f%f%f",&x,&y,&z);
 	m=zj(x,y,z);
 	printf("%d",m);
 }
