#include "graph.h"
#include <cstdio>

int main(){
Graph tree;
int x;
puts("The value of the root of tree is___?");
scanf("%d",&x);
tree.creat(x,-1);
char s[1000];
for (;;)
{
    scanf("%s",s);
    if (s[0]=='B')//build
        {
            int In_fa,In_value;
            puts("fa=___? value=____?");
            scanf("%d%d",&In_fa,&In_value);
            if (In_fa>=tree.get_point_size())
            {
                puts("That point is not in the tree.");
                continue;
            }
            tree.creat(In_value,In_fa);
        }
    if (s[0]=='V')//view
        {
            int In_num;
            puts("number=____?");
            scanf("%d",&In_num);
            if (In_num>=tree.get_point_size())
            {
                puts("That point is in the tree.");
                continue;
            }
            printf("value=%d fa=%d son_total=%d\n",tree.get_value(In_num),tree.get_fa(In_num),tree.get_son_total(In_num));
        }
}

return 0;
}
