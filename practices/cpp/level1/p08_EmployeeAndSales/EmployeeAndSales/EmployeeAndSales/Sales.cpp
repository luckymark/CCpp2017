#include "Sales.h"
#include <cstdio>

double Sales::get_salary(){
return get_level()*1000+sales_num*0.2;
}

void Sales::set_sales(int in_sales){
sales_num=in_sales;
}
