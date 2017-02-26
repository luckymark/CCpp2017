#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

typedef int _Bool;

#define NUM_PRM 25

void create_prime(int *prm);
_Bool judge_Goldbach_con(int *a, int n);

int main(void)
{
	int prm[NUM_PRM];
	
	create_prime(prm);
	if (judge_Goldbach_con(prm, 100)){
		printf("Goldbach conjecture is right from 2 to 100\n");
	}
	else{
		printf("Goldbach conjecture is wrong.");
	}
		
	return 0;
}

void create_prime(int *prm)
{
	int a[101], num_prm = 0;
	
	for (int i = 2; i <= 100; i++){
		a[i] = 1;
	}
		
	for (int j = 2; j <= 100; j++){
		if(a[j] == 0)
			continue;
		else{
			prm[num_prm] = j;
			num_prm++;
		}
		for (int k = 2; j * k <= 100; k++){
			a[j * k] = 0;
		}
	}
}

_Bool judge_Goldbach_con(int *prm, int n)
{
	int nature_num, prm1, prm2;
	
	for (nature_num = 4; nature_num <= n; nature_num += 2){
		for (int i = 0; i < NUM_PRM; i++){
			prm1 = prm[i];
			for (int j = 0; j < NUM_PRM; j++){
				prm2 = prm[j];
				if (nature_num ==  prm1 + prm2)
				 goto OUT;
			}
		}
		return FALSE;
		OUT:;
	}
	
	return TRUE;
}
