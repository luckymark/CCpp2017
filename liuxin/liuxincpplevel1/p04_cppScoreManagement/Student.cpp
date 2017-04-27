#include <cstdio>
#include <cstring>
#include "Student.h"

Student::Student(){
	score=0;
}
Student::Student(char *a,char *b){
	score=0;
	memcpy(ID+1,a+1,strlen(a+1));
	memcpy(name+1,b+1,strlen(b+1));
}

void Student::write(){
	printf("%s %s %d\n",ID+1,name+1,score);
}

bool Student::operator ==(const Student &x){
	if (strlen(ID)!=strlen(x.ID)) return 0;
	else {
		int i,len=strlen(ID);
		for (i=1;i<=len;++i) if (ID[i]!=x.ID[i]) return 0;
		return 1;
	}
}
