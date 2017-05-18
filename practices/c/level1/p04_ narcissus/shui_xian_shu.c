#include <stdio.h>

int main(void)
{
  int bai,shi,ge;
  int shui_xian_shu;
  
  printf("Please output all shui_xian_shus:\n");
  for(bai=1;bai<10;++bai){
    for(shi=0;shi<10;++shi){
      for(ge=0;ge<10;++ge){
            shuixianshu = bai*100 + shi*10 + ge;

            if (bai*bai*bai + shi*shi*shi + ge*ge*ge == shui_xian_shu)
                printf("%5d\n",shui_xian_shu);
      }
    }
  }

  printf("\n");

    return 0;
}
