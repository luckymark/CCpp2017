#include<stdio.h>
#include<math.h>

int main(void)
{
	int num_judge;
	scanf("%d",&num_judge);
	
	int help = sqrt ( num_judge ) ;
	int identify = 1;

	for (int k =2; k<=help; k++) {
		if (num_judge % k == 0) {
			identify = 0;
			break;
		}
	}

	if (identify == 0 || num_judge ==1) {
        printf("no it isn't ");
    } else if (identify == 1) {
        printf(" yes it is ");
    }

	return 0;
}
