#include <stdio.h> 

int main(void)
{	
	//  age/6+age/12+age/7+5 = age-age/2-4	
	for(int i=10;i<=120;i++){
        	if(i%6 == 0 && i%12 == 0 && i%7 == 0){
            		printf("His age is %d",i);
       	 	}
    	}

	return  0;
 } 
