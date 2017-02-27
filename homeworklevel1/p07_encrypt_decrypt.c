#include <stdio.h>
#include <string.h>
typedef long long LL;
const int MAXN=100005;
char s[MAXN];
LL m,n,p,q,e1,e2,a[MAXN];
LL mul(LL a,LL b,LL c){
	LL ans=0; a%=c;
	while (b){
		if (b&1) {
			ans=ans+a;
			if (ans>=c) ans-=c;
		}
		a=a+a; b>>=1;
		if (a>=c) a-=c;
	}
	return ans;
}
LL power(LL a,LL b,LL c){
	LL ans=1;
	while (b){
		if (b&1) ans=mul(ans,a,c);
		a=mul(a,a,c); b>>=1;
	}
	return ans;
}
LL next_prime(LL x) {
	int i,j;
	while (1) {
		for (i=2,j=1;i*i<=x;++i) if (x%i==0) { j=0; break; }
		if (j==1) { return x; break; }
		x++;
	}
}
LL gcd(LL x,LL y){ return y==0?x:gcd(y,x%y); }
LL extend_gcd(LL a,LL b,LL &x,LL &y) {
	if (b==0) { x=1; y=0; return a; }
	else {
		int tmp=extend_gcd(b,a%b,y,x);
		y-=x*(a/b); return tmp;
	}
}
void test(){
	p=next_prime(102567192LL);
	q=next_prime(186127350LL);
	n=p*q;
	printf("%lld %lld %lld\n",p,q,n);
	for (LL i=10;i;++i) if (gcd(i,(p-1)*(q-1))==1) { e1=i; break; }
	extend_gcd(e1,(p-1)*(q-1),e2,m);
	e2=(e2%((p-1)*(q-1))+(p-1)*(q-1))%((p-1)*(q-1));
	printf("%lld %lld\n",e1,e2);
}
//102567211 186127387 19090566975307657 11 17355060624193691
int main(){
	int i; //test();
	p=102567211LL; q=186127387LL; n=19090566975307657LL; e1=11LL; e2=17355060624193691LL;
	scanf("%s",s); m=strlen(s);
	for (i=0;i<m;++i) printf("%lld\n",a[i]=power(s[i],e1,n));
	for (i=0;i<m;++i) printf("%c",power(a[i],e2,n)); printf("\n");
	
	return 0;
}

/*
RSA算法是一种非对称密码算法，所谓非对称，就是指该算法需要一对密钥，使用其中一个加密，则需要用另一个才能解密。
RSA的算法涉及三个参数，n、e1、e2。
其中，n是两个大质数p、q的积，n的二进制表示时所占用的位数，就是所谓的密钥长度。
e1和e2是一对相关的值，e1可以任意取，但要求e1与(p-1)*(q-1)互质；再选择e2，要求(e2*e1)mod((p-1)*(q-1))=1。
（n，e1),(n，e2)就是密钥对。其中(n，e1)为公钥，(n，e2)为私钥。[1] 
RSA加解密的算法完全相同，设A为明文，B为密文，则：A=B^e2 mod n；B=A^e1 mod n；（公钥加密体制中，一般用公钥加密，私钥解密）
e1和e2可以互换使用，即：
A=B^e1 mod n；B=A^e2 mod n;
*/
