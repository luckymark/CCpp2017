#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//文件名
	string filename = "M1.txt";
	//如果文件名是string类型的调用c_str成员获取C风格字符串
	//因为IO标准库是使用C风格字符串来作为文件名的
	//此处打开文件也可以用ifstream的成员函数open来执行
	ifstream infile(filename.c_str());
	//检查文件是否打开成功
	if(!infile)
	{//如果没成功
	//	throw runtime_error("file cannot open");
		return -1;
	}
	else
	{//文件打开成功，开始进行读文件操作
		string s;
		//fstream类中也有getline成员函数，不要弄错
		//getline(infile,s);
		while(!infile.eof())
		{
			//infile >> s;
			getline(infile,s);
		    cout << s << endl;
		}
	}
	infile.close();
	return 0;
}


