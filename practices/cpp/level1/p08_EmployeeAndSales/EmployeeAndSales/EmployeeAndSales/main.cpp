#include "Employee.h"
#include "Sales.h"
#include <cstdio>

int main(){
/*
Employee A;
int x;
puts("age?");
scanf("%d",&x);
A.set_age(x);

puts("levle?");
scanf("%d",&x);
A.set_level(x);

puts("name?");
char s[1000];
scanf("%s",s);
A.set_name(s);

puts("phone?");
scanf("%s",s);
A.set_phone(s);

puts("adress?");
scanf("%s",s);
A.set_adress(s);


printf("age=%d  levle=%d name=%s  phone=%s salary=%d\n",A.get_age(),A.get_level(),A.get_name(),A.get_phone(),A.get_salary());
printf("adress=%s\n",A.get_adress());
*/
Sales A;

int x;
puts("age?");
scanf("%d",&x);
A.set_age(x);

puts("levle?");
scanf("%d",&x);
A.set_level(x);

puts("name?");
char s[1000];
scanf("%s",s);
A.set_name(s);

puts("phone?");
scanf("%s",s);
A.set_phone(s);

puts("adress?");
scanf("%s",s);
A.set_adress(s);

puts("sales?");
scanf("%d",&x);
A.set_sales(x);
printf("age=%d  levle=%d name=%s  phone=%s salary=%.3lf\n",A.get_age(),A.get_level(),A.get_name(),A.get_phone(),A.get_salary());
printf("adress=%s\n",A.get_adress());
}
