# include<stdio.h>
# include<stdlib.h>
int main(){
	char Arr[3];
	int t1,t2,t3;
	for(int i=100; i<1000; i++){
		sprintf(Arr, "%d", i);
		t1 = Arr[0]-48;
		t2 = Arr[1]-48;
		t3 = Arr[2]-48;
		if(i==(t1*t1*t1+t2*t2*t2+t3*t3*t3)) printf("%d\n", i);
	}
	return 0;
}
