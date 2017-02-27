#include <stdio.h>                                                                                                    +e <stdio.h>
#include <stdlib.h>

int main(void)
{
   int month = 0;
   printf("which month:");
   scanf("%d",&month);

   switch(month){
   case 2:
       printf("There are 28 or 29 days in this month\n");
       break;
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
       printf("There are 31 days in this month\n");
       break;
   case 4:
   case 6:
   case 9:
   case 11:
       printf("There are 30 days in this month\n");
       break;
   default :
       printf("Input a wrong month\n");

   }

    return 0;
}
