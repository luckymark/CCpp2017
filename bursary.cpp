#include "iostream"
#include "string.h"
#define max_size 10
#define max_bursary 10
#define max_name 10
#include "conio.h"
#include "windows.h"
void printf_bursary(int *num,FILE *fp);
void in_bursary(int *num,FILE *fp);
void del_bursary(int *num,FILE *fp);
char check();
using namespace std;
struct bursary
{  
    char name[max_name]; 
	char size[max_size];
	int  quantity;
}s[max_bursary];

int main()
{
	static int num=0;
	FILE *fp;
	fp=fopen("bursary.dat","a+b");
	if(!fp)
	{
		cout<<"can't open the FILE";
		exit(0);
	}
	
	fseek(fp,0L,SEEK_SET);
	while(1)
	{ 
	cout<<"enter 0 to see the information of bursary!"<<endl<<"enter 1 to del goods from the bursary!"<<endl<<"enter 2 to put the goods in the bursary!"<<endl<<"enter q to quit!"<<endl<<"!!!!after you input ,you must press'enter' to continue!!!"<<endl; 
	switch(check())
	{
		case '0':
		{
			printf_bursary(&num,fp);
			break;
		}
		case '1':{
				del_bursary(&num,fp);
				break;
			}
		case '2':{
			
				in_bursary(&num,fp);
				
				break;
			} 
		case 'q':exit(0);
	}
	cout<<endl;
	cout<<"if you want to quit!please enter q,if not,press any key to continue!";
	if(getchar()=='q')
	{
		exit(0);
	}
	Sleep(2000);
	} 
	return 0; 
} 
void printf_bursary(int *num,FILE *fp)                   
{
	fseek(fp,0L,SEEK_SET);               
    int book=0;
	int nm=0;
	while(*num<max_bursary && nm<*num)
	 {
	 	if(nm==0)
	 	{ 
	 		cout<<"here is the list of the bursary:"<<endl;
	 	} 
	 	cout<<s[nm].name<<" "<<s[nm].size<<" "<<s[nm].quantity;
	 	cout<<endl;
	 	nm++;
	 	book=1;
	} 
	if(book==0)
	{
		cout<<"there is no datas there!";
	}
	
	return;
}

char check()  
{
	  	char ch;
	
	while(1)
	{   
		ch=getchar();
		if(ch!='0' && ch!='1' && ch!='2' && ch!='q')
		{   
			cout<<"there is no such choice!please input again!"<<endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return ch;
}

void in_bursary(int *num,FILE *fp)                  
  {
  	 cout<<"num is:"<<*num<<endl;
     fseek(fp,0L,SEEK_END); 
  	 int h=sizeof(struct bursary);
	 if(*num==max_bursary)
	 {
	 	cout<<"there is no enough room!";      
	 	exit(0);
	 }
	  
	 while(*num<max_bursary )
	 {
	 	int book=0;           
	 	cout<<"now enter the name:";
	 	cin>>s[*num].name; 
	 	cout<<"now enter the size:";
	    cin>>s[*num].size; 
	 	cout<<"now enter the quantity:";
	 	cin>>s[*num].quantity;
	 	for(int i=0;i<*num;i++)
		 {
		 	if(s[i].name == s[*num].name && s[i].size == s[*num].size )   
		 	{
			 	s[i].quantity +=s[*num].quantity;     
			 	fseek(fp,i*h,SEEK_SET);		
			 	fwrite(&s[*num],h,1,fp);           
				fseek(fp,0L,SEEK_END);         
			  	cout<<"please enter the next data!";
			  	break;	
				book=1;
			}
			 
		 }
		 if(book==1)
		 {
		 	continue;
		 }
		fwrite(&s[*num],h,1,fp); 
		(*num)++;
	 	cout<<"if you want to continue,please entre any key;if you want to return,please enter q"<<endl;
	 	char a=getch();
	 	if(a=='q')
	 	{
	 		return;
		 }
	 	cout<<"num is:"<<*num<<endl;
	    if(*num<max_bursary)
	    { 
		 	cout<<"please enter the next data!"; 
		 } 
	   }
	   return;
	 
}
	

void del_bursary(int *num,FILE *fp)
{
    if(*num==0)
       {
           	cout<<"there is no data to del!";
           	return;
	   }
		 
    int book=0;      
    int h=sizeof(struct bursary);
	struct bursary t;
	cout<<"now enter the name:";
	cin>>t.name;
	cout<<"now enter the size:";
	cin>>t.size;
	cout<<"now enter the quantity:";
	cin>>t.quantity;
	for(int j=0;j<*num;j++)
	{
		if(s[j].name == t.name && s[j].size == t.size)
		{
				if(s[j].quantity < t.quantity)
				{ 
					cout<<"there is no enough goods!";
					exit(0); 
	       		 }
				if(s[j].quantity==t.quantity)
				{
					fseek(fp,j*h,SEEK_SET); 
					for(int i=j;i<*num-1;i++)
					{
						 s[i]=s[i+1]; 
						 (*num)--; 
					}
					fwrite(&s[j],h,*num-j-1,fp);           
					exit(0);		
				}
				 s[j].quantity-=t.quantity;         
				fseek(fp,j*h,SEEK_SET);              
				fwrite(&s[j],h,1,fp); 
				break;
		}
	 } 
    return;	
}
