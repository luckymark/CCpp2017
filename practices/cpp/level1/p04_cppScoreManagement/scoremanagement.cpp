/*
题目：C++考试成绩管理

功能要求：

查看学生名单（含所有信息）
选课（添加学生）
退选（删除学生）
录入成绩（从特定学号开始，每录入完一人，询问是否继续）
退出程序
功能要求（选做）：

支持录入多门课程
*/

#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
using namespace std;

struct Record{
	int id;
	string name;
	double score;
};

vector<Record> students;

void loadformfile();
void listout();
void addstu();
void delstu();
void record(int);
void savetofile();

int main(){
	loadformfile();
    while(ture){
        sys("clr");
        cout<<"1.list"<<endl;
        cout<<"2.add"<<endl;
        cout<<"3.delete"<<endl;
        cout<<"4.record"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"-->"<<endl;
        int choice;
        cin>>choice;
        switch (choice){
            case 1:
                listout();
                break;
            case 2:
                addstu();
                break;
            case 3:
                delstu();
                break;
            case 4:
				cout<<"Input the number you would start."<<endl;
				cin<<choice;
                record(choice);
                break;
            case 5:
                savetofile();
                break;
            default:
                break;
        }

    }
	return 0;
}

void loadformfile(){
    ifstream f("data.txt");
    char c;
    int id;
    string name;
    double score;
    while(f>>c){
        f>>id>>name>>score;
        Record newrecord ={id,name,score};
        students.append(newrecord);
    }
}

void listout(){
	for(auto it=students.begin();it!=stu.end();it++){
		cout<<it->id<<" "<<it->name<<" "<<it->score<<endl;
	}
}

void addstu(){
	string name;
	cout<<"Input the name of students:"<<ends;
	Record newstu={(students.end()-1)->id,name,-1};
	students.append(newrecord);
}

void delstu(){
	int id;
	cout<<"Input the id of the student:"<<ends;
	cin<<id;
	if(id<(students.end()-1)->id){
		students.erase(id)
	}else{
		cout<<"No this student"<<endl;
	}
}

void record(int n){
	for(auto it=students[n];it!=stu.end();it++){
		double score;
		char choice;
		cin>>it->score;
		cout<<"Would you like to continue?(y/n)"<<endl;
		cin<<c;
		if(c=='y'){
			continue;
		}else if(c=='n'){
			break;
		}else{
			cout<<"please input y/n."<<endl;
			break;
		}
	}
}

void savetofile(){
	ofstream f("data.txt");
	for(auto it=students.begin();it!=students.end();it++){
		f<<it->id<<" "<<it->name<<" "<<it->score<<endl;
}

