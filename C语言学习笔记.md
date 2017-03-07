# C语言学习笔记

## 无缓冲输入
    getche() 回显无缓冲输入
    getch() 无回显无缓冲输入
    两者都在conio.h头文件中
## 数学函数
### 取整函数
    floor(double x) 向下取整
	ceil(double x) 向上取整
	round(double x) 四舍五入
##字符串
###整数转字符串
    itoa(int n) 将整型值转换为字符串
    itoa(lont n) 将长整型值转换为字符串
    ultoa(unsigned long) 将无符号长整型值转换为字符串
###改变字符串大小写 string.h
	strupr(char *s) 返回一个指向c的指针，函数会改变c；
	strlwr(char *s) 返回一个指向c的指针，函数会改变c；
	strcpy(char *str1, char *str2) 将str2的内容复制到str1
	strcmp(const char *s1, const char *s2) 字符串相同返回0

    
