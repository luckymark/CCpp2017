#include <stdio.h>
int  main(void)
{
	float years=0;
	float childhood,young,single;
  
    while(years<200)
    {
    	childhood=(float)years/6;
    	young=(float)years/7;
    	single=(float)years/12;
    	if(years==(childhood+young+single+5+4)*2)
	    	printf("¶ù×ÓËÀÊ±¶ª·¬Í¼Îª%dËê.\n",(int)years-4); 
		years++;
	}
	return 0;
}
