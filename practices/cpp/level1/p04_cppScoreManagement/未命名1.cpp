#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//�ļ���
	string filename = "M1.txt";
	//����ļ�����string���͵ĵ���c_str��Ա��ȡC����ַ���
	//��ΪIO��׼����ʹ��C����ַ�������Ϊ�ļ�����
	//�˴����ļ�Ҳ������ifstream�ĳ�Ա����open��ִ��
	ifstream infile(filename.c_str());
	//����ļ��Ƿ�򿪳ɹ�
	if(!infile)
	{//���û�ɹ�
	//	throw runtime_error("file cannot open");
		return -1;
	}
	else
	{//�ļ��򿪳ɹ�����ʼ���ж��ļ�����
		string s;
		//fstream����Ҳ��getline��Ա��������ҪŪ��
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


