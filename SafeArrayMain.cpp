#include <cstdio>
#include "SafeArray.h"
using namespace std;

#define INF 2147483647

int main(){
	int n,temp;/*
		n:Capability of the SafeArray
	*/
	scanf("%d",&n);
	SafeArray<int> a(n,INF);/*
		Set the Capability of the SafeArray and the Returned Value when the Array Bounds 
	*/
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		a[i]=temp;//Or a.set(i,temp);
	}
	for(int i=0;i<n-1;++i){
		printf("%d ",a.at(i));//Or printf("%d ",a[i]);
	}
	printf("%d\n",a.at(n-1));
	printf("%d\n",a.at(n));
}
