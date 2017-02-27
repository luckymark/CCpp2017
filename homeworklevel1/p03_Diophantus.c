#include <math.h>
#include <stdio.h>
const double INF=1e8,eps=1e-8;
int main(){
	double i=0,j;
	while (i<INF) {
		if (fabs(i/6+i/12+i/7+9-i/2)<eps) printf("%.0f\n",i);
		i+=0.1;
	}
	return 0;
}
