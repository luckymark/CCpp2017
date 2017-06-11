#include <cstdio>
#include "Circuit.h"
Circuit test;
void link(int device_op){
if (device_op==1)
    printf("Link a Fan after NO.? device.");
if (device_op==2)
    printf("Link a Light after NO.? device.");
if (device_op==3)
    printf("Link a Switch after NO.? device.");
int INT_op;
scanf("%d",&INT_op);
if (INT_op>test.get_total())
    {
        puts("");
        puts("That device is not in the circle.");
    }
test.creat(INT_op,device_op);
}

int main(){
test.show();
test.creat(test.get_st(),1);
test.Shift(1,1);
test.show();
char s_op[1000];
for (;;)
    {
        gets(s_op);
        if ((s_op[0]!='F')&&(s_op[0]!='S')&&(s_op[0]!='L')&&(s_op[0]!='O')&&(s_op[0]!='C'))
            continue;
        if (s_op[0]=='F')
            link(1);
        if (s_op[0]=='L')
            link(2);
        if (s_op[0]=='S')
            link(3);
        if (s_op[0]=='O')
            test.show();
        if (s_op[0]=='C')
            {
                int INT_op;
                int BOOL_op;
                puts("Change NO.___ device to __(0/1).");
                scanf("%d%d",&INT_op,&BOOL_op);
                if (INT_op>test.get_total())
                    {
                        puts("");
                        puts("That device is not in the circle.");
                    }
                else
                    test.Shift(INT_op,BOOL_op);
            }
    }
return 0;
}
