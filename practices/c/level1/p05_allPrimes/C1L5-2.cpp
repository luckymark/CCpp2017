# include<stdio.h>
# include<time.h>
using namespace std;
int main()
{
	long op,ed;
	int n = 0;
	op=clock();
	bool flag = 0;
	int A[50002] = {0, 1};
	for(int i=2; i*i<=50000; i++){
		if(A[i]==1){
			continue;
		}
		else{
			n = 2*i;
			while(n < 50001 && A[i] != 1){
				A[n] = 1;
				n += i;
			}
			n = i;				
		}
		flag = 0;
	}
		
	ed=clock();
	printf("RUNTIME : %ldms\n",ed-op);
	
	for(int i=1; i<50000; i++){
		if(A[i] == 0){
			printf("%d ", i);
		}
	}
	return 0;
}
