#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Length,LastNum;
long long a[100000],b[100000];
long long p=158427067ll,q=358424749ll;
long long e1=79,e2=718787103891511ll;
long long n=56784181724281183ll;

long long nextPrime(long long x);
long long FORe2(long long  x);
long long fastAdd(long long x,long long y);
long long fastExp(long long x,long long y);
void encrypt();
void decrypt();

int main(){
	char ch;
	int i=1,j=1;
	while (scanf("%c",&ch)!=EOF){
		if (ch=='\n') break;
		if (j==4){
			j=0;
			i++;
		}
		a[i]<<=8;
		a[i]+=ch;
		j++;
	}
	Length=i;
	LastNum=j;
	encrypt();
	memset(a,0,sizeof(a));
	decrypt();
	return 0;
}

long long nextPrime(long long x){
	while(1){
		int i;
		for (i=2;i<=x/i;i++){
			if (x%i==0){
				break;
			}
		}
		if (i>x/i){
			return x;
		}
		else{
			x++;
		}
	}
}
long long FORe2(long long  x){
	long long y=(p-1)*(q-1);
	if (y%x==0){
		return -1;
	}
	long long i;
	for (i=y+1;i>0;i+=y)
		if (i%x==0){
			break;
		}
	return i>0? i/x:-1;
}
long long fastAdd(long long x,long long y){
	long long result;
	if (y==0) return 0;
	else {
		while ((y&1)==0){
			y>>=1;
			x=x+x;
			if (x>=n){
				x=x-n;
			}
		}
		result=x;
		y>>=1;
		while (y!=0){
			x=x+x;
			if (x>=n) {
				x-=n;
			}
			if ((y&1)!=0){
				result+=x;
			}
			if (result>=n){
				result-=n;
			}
			y>>=1;
		}
	}
	return result>=n? result%n:result;
}
long long fastExp(long long x,long long y){
	long long result;
	if (y==0) return 1;
	else {
		while ((y&1)==0){
			y>>=1;
			x=fastAdd(x,x);
		}
		result=x;
		y>>=1;
		while (y!=0){
			x=fastAdd(x,x);
			if ((y&1)!=0){
				result=fastAdd(result,x);
			}
			y>>=1;
		}
	}
	return result>=n? result%n:result;
}
void encrypt(){
	for (int i=1;i<=Length;i++){
		b[i]=fastExp(a[i],e1);		
	}
	for (int i=1;i<=Length;i++){
		if (i==Length){
			for (int j=1;j<=LastNum;j++){
				printf("%c",(char)((b[i]>>((LastNum-j)*8))&127));
			}
		}
		else {
			printf("%c%c%c%c",(char)((b[i]>>24)&127),(char)((b[i]>>16)&127),(char)((b[i]>>8)&127),(char)(b[i]&127));
		}
	}
	printf("\n");
}
void decrypt(){
	for (int i=1;i<=Length;i++){
		a[i]=fastExp(b[i],e2);		
	}
	for (int i=1;i<=Length;i++){
		if (i==Length){
			for (int j=1;j<=LastNum;j++){
				printf("%c",(char)((a[i]>>((LastNum-j)*8))&127));
			}
		}
		else {
			printf("%c%c%c%c",(char)((a[i]>>24)&127),(char)((a[i]>>16)&127),(char)((a[i]>>8)&127),(char)(a[i]&127));
		}
	}
	printf("\n");
}
