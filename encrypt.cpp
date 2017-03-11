
#include "iostream"
using namespace std;
#include "math.h"
#include "string.h" 
char jiaMi(char a[],char b[],char c[])
{
	int sb=strlen(b);
	int sa=strlen(a);
	for(int i=0;i<sa;i++)
	{
	c[i]=a[i]+b[i%sb]-'A';
	if(c[i]>'Z')
	c[i]-=26;
    }
    cout<<"your cipher code is:";
    cout<<c<<endl;
    return *c; 
} 
 
void jieMi(char a[],char b[],char c[])
{
	int sb=strlen(b);
	int sa=strlen(a);
	for(int i=0;i<sa;i++)
	{
	c[i]='A'+a[i]-b[i%sb];
	if(a[i]<b[i%sb])
	c[i]+=26;
    }
    cout<<"your original text is:";
    cout<<c<<endl;
} 
 int main()
 {
 	char a[100],b[100],result[100];
 	cout<<"please input what you want to encrypt:"<<endl;
    cin>>a; 
    cout<<"please input your key:"<<endl;
    cin>>b;
	jiaMi(a,b,result);
	jieMi(result,b,a);
}
