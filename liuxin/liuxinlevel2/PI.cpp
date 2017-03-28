#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

const LL MAXN=10004,base=10000;
struct BigNum{
	LL l,x[MAXN];
	inline void clear() { l=1; memset(x,0,sizeof(x)); }
	BigNum() { clear(); }
	BigNum(LL a) { for (l=0;a;a/=base) x[++l]=a%base; }
	BigNum operator +(const BigNum &B) const {
		BigNum C; C.l=(B.l>l?B.l:l);
		for (LL i=1;i<=C.l;++i) {
			C.x[i]+=x[i]+B.x[i];
			if (C.x[i]>=base) {
				C.x[i+1]+=C.x[i]/base;
				C.x[i]%=base;
			}
		}
		if (C.x[C.l+1]) C.l++;
		return C;
	}
	BigNum operator -(const BigNum &B) const {
		BigNum C=(*this);
		for (LL i=1;i<=C.l;++i) {
			C.x[i]-=B.x[i];
			if (C.x[i]<0) { C.x[i+1]--; C.x[i]+=base; }
		}
		while (C.l>1&&!C.x[C.l]) C.l--;
		return C;
	}
	BigNum operator *(const BigNum &B) const {
		BigNum C; C.l=l+B.l-1;
		for (LL i=1;i<=l;++i)
			for (LL j=1;j<=B.l;++j) {
				LL k=i+j-1;
				C.x[k]+=x[i]*B.x[j];
				if (C.x[k]>=base) {
					C.x[k+1]+=C.x[k]/base;
					C.x[k]%=base;
				}
			}
		while (C.x[C.l+1]>0) {
			C.l++;
			if (C.x[C.l]>base) {
				C.x[C.l+1]=C.x[C.l]/base;
				C.x[C.l]%=base;
			}
		}
		return C;
	}
	BigNum operator *(const LL &b) const {
		BigNum C; C.l=l;
		for (LL i=1;i<=C.l;++i) {
			C.x[i]+=x[i]*b;
			if (C.x[i]>=base) {
				C.x[i+1]+=C.x[i]/base;
				C.x[i]%=base;
			}
		}
		while (C.x[C.l+1]) {
			LL i=C.l++;
			if (C.x[i]>=base) {
				C.x[i+1]+=C.x[i]/base;
				C.x[i]%=base;
			}
		}
		return C;
	}
	BigNum operator /(const LL &b) const {
		BigNum C=(*this);
		for (LL i=C.l,j=0;i>0;--i) {
			j=j*base+C.x[i];
			C.x[i]=j/b;
			j%=b;
		}
		while (C.l>1&&C.x[C.l]==0) C.l--;
		return C;
	}
	void write(){
		cout<<x[l];
		for (LL i=l-1;i;--i)
		if (x[i]<10) printf("000%I64d",x[i]); else
		if (x[i]<100) printf("00%I64d",x[i]); else
		if (x[i]<1000) printf("0%I64d",x[i]); else 
		if (x[i]<10000) printf("%I64d",x[i]);
		cout<<endl;
	}
};
typedef BigNum NB;
int main(){
	printf("Please input the length/4:\n");
	LL i,j,n=read();
	double tmp=clock();
	NB A,B; A.l=B.l=n; A.x[n]=B.x[n]=1;
	//A.write(); B.write();
	for (i=1;B.l>1;++i) {
		B=B*i; //B.write();
		j=i*2+1;
		B=B/j; //B.write();
		A=A+B;
	}
	//cout<<i<<' '<<A.l<<endl;
	A=A*2;
	A.write();
	printf("time=%.3lf ms\n",clock()-tmp);
	printf("memory=%d byte\n",sizeof(A)*3);
	
	return 0;
}

/*
So easy!
If you know following format!
But is it the best solution?
PI/2=1+1/3+1/3*2/5+1/3*2/5*3/7+...
*/
