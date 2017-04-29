# C++学习笔记
## 1.读取一整行输入时可用的几种函数和区别

# 1.```getline()```&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;page78
每次读取一行，通过换行符来确定行尾，但不保存换行符。在储存支付穿时，它用空字符来替换换行符。 
如果输入行包含的字符数比指定的多，getline就会把余下的字符留在输入队列中并设置失效位关闭后面的输入 
调用方法： 
### ```cin.getline(name,ArSize)```

name代表的是char类型一维数组名，ArSize表示数组的大小，比如若参数为20，则函数最多读入19个字符。  
# 2.```get()```
调用方法：  
### ①```cin.get(name,ArSize)```
特征：不读取换行符，而是将其留在输入队列中;若读取到空行，就会设置一个失效位 cin.failbit()
注意点：连续调用两次①cin.get(name,ArSize);时，在第一次调用以后，输入队列中的第一个就是换行符，所以第二次调用时函数认为已经到了行尾，不读取（即cin.get(name,ArSize);无法独自跨过换行符）
### ②```cin.get()```  
可读取下一个字符，即便是换行符，可用来帮助cin.get(name,ArSize);跨过换行符。  
举例:  
cin.get(name,ArSize).get();
# 3.```getline(cin,str)```
geline()的第一个参数表示到哪里去查找输入，第二个参数表示将字符串读入一个string对象中

## 2.<fstream\>
>输出至文本: 

* 包含头文件<fstream\>  
* 使用fstream时应该自己创建一个对象，对象名自己取（“在iostream中已经自动创建了cout所以不需要，但是这里需要”）;  
* 打开文件的命令：  
```c++
    std::ofstream fout;  
    fout.open("hello.txt");
//或者char name[50]="hell0.txt"; fout.open(name);  
```
使用结束后用fout.close（）关闭，如不关闭，程序正常终止时将自动关闭它；   
>从文本输入 

* 包含头文件<fstream\>  
* 指明名称空间std;
* 使用open（）方法将文件与ifstream对象关联起来。
* 声明一个或者多个ifstream对象，以自己喜欢的方式命名。
* 结合使用ifstream.eof()、fail()来判断输入是否成功。
* ifstream 对象本身被用作测试条件时，如果最后一个读取操作成功，它将被砖汉尾布尔值true,否则转换为false.
* 检查是否成功打开文件（避免试图打开一个不存在的文件用于输入）
```c++
	ifstream inFile;
	inFile.open("bowling.txt");
	if (!inFile.is_open()){
		exit(EXIT_FAILURE);
	}
```
如果文件被成功打开，is_open（）将返回true
* inFile.good()方法将在没有发生任何错误时返回true,如文件结尾、输出不匹配等。
## 3.数组
#### 1.对数组名使用&时将返回整个数组的地址