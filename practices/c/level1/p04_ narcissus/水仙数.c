#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a,b,c;
  int shuixianshu;
  printf("Please output all shuixianshus:\n");
  for(a=1;a<10;++a){
    for(b=0;b<10;++b){
        for(c=0;c<10;++c){
            shuixianshu = a*100 + b*10 + c;

            if (a*a*a+b*b*b+c*c*c == shuixianshu)
                printf("%5d",shuixianshu);
        }
    }
  }

  printf("\n");

    return 0;
}
