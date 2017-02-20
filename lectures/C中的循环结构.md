#循环
##基本结构
###while
while（）{}

先进行判断，再执行循环体内语句。
###do while
do{}

while（）；

先执行循环体内语句，再进行判断

###for
for（1；2；3）{}

先执行语句1，之后进行判断，在执行完循环体内语句后执行语句3，然后返回2进行判断。

（1,2,3语句可以写，也可以不写）

***
关于do while循环，可以用一个简单的例子来说明

```#include<stdio.h>
int main()
{
    int i=-2,j;
    do
    {
        printf("A\n");
    }
    while(i>0);
    return 0;
}
```
##break；continue；goto语句在循环中的作用
* break可以跳出当前循环。
* continue可以直接进入下一次循环。
* goto什么的最好不好用，在有特殊需要的情况下，可以跳转到其他你想的地方。


> 其实无聊的时候可以试试用if，goto来构造循环玩（误）


##关于效率的一些玄学
* `i++` || `++i`      
* `int i=0;i<n;i++`  ||  `int i=n;i>0;i--`
* [内层循环次数大 || 外层循环次数大](https://github.com/pzhxbz/learngit/blob/master/shangkeceshi21.cpp)
* [`int i=0;i<j;i++` || `int i=0,n=j;i<j;i++`](https://github.com/pzhxbz/learngit/blob/master/shangkeceshi31.cpp)
***
关于循环效率的玄学很多，在此并不能例举完。但是，大多数关于循环效率的玄学，都无法在很大程度上提高程序的效率，重要的还是优化算法，或者采用其他技术进行优化。

> 使程序并行化是不错的选择
>
> [openmp了解](http://blog.csdn.net/netnote/article/details/3137563)



