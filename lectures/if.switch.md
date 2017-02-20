#C语言中的分支结构（if、switch）
---
##if语句
``` C
if (1)
{
   printf("vanishment this world");
}
```
当小括号内的表达式值为真（也就是非0的值）时 执行if的内嵌语句

if的内嵌语句从语法上来说是单语句 建议**用花括号括起来**
``` C
if (1)
{
   printf("YES");
}
else
{
   printf("NO");   
}
```
当小括号内的表达式值为真（也就是非0的值）时 执行if的内嵌语句

当小括号内的表达式值为假（也就是0值）时 执行else后的语句

else会同**与自身最近的上一个if语句配对** 这一点尤其要注意

---
##switch语句
``` C
int a=1;
switch (a)
{
   case 1:  printf("YES");
            break;
   case 0:  printf("NO"); 
            break;
   default: printf("ERROR");   
            break;
}
```
小括号内的表达式类型**只能是int或char或bool(C99,详见下)**

当表达式的值与某个case后的常量相等时 

执行该case对应的语句**直至break一类的语句或switch语句结束**

当表达式的值与每个case后的常量都不相等时

执行default对应的语句**直至break一类的语句或switch语句结束**

goto语句也能跳出switch 因其使程序难以阅读 建议使用break

---
##C89 C99中相关部分
相比C89 C99有了如下相关变化

- 条件语句的嵌套层数由8层变为63层

- 增加了一个数据类型bool 

  其头文件stdbool.h的源代码如下

    /*

　　* ISO C Standard: 7.16 Boolean type and values

　　*/

　　#ifndef _STDBOOL_H

　　#define _STDBOOL_H

　　#ifndef __cplusplus

　　#define bool _Bool

　　#define true 1

　　#define false 0

　　#else /* __cplusplus */

　　/* Supporting in C++ is a GCC extension. */

　　#define _Bool bool

　　#define bool bool

　　#define false false

　　#define true true

　　#endif /* __cplusplus */

　　/* Signal that all the definitions are present. */

　　#define __bool_true_false_are_defined 1

　　#endif /* stdbool.h */

---
> ~~很惭愧 就做了一点微小的工作~~ 

---
