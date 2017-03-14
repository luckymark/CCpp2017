#include <stdio.h>

int main()
{
    int age;
    for(age = 1;age <= 250; age++){
        if((age/6 + age/7 + age/12 + 5 + age/2 + 4 == age & age%6==0 & age%7==0 & age%12==0)){
            printf("The age is %d.\n",age-4);
        }
    }
    return 0;
}
