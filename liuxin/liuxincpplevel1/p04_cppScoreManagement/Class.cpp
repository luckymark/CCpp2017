#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#include "Student.h"
#include "Class.h"

Class::Class(char *a,char *b){
	memcpy(name,a,strlen(a));
	memcpy(description,b,strlen(b));
}

void Class::write(){
	printf("%s:\n\t%s\n",name,description);
}

int Class::Add(Student x){
	if (total==199) return -1;
	s[++total]=x;
	return 1;
}

int Class::Delete(Student x){
	int i,j;
	for (i=1,j=0;i<=total;++i) if (x==s[i]) { j=i; break; }
	if (!j) return -1;
	else {
		for (i=j;i<total;++i) s[i]=s[i+1];
		total--;
		return 1;
	}
}

void Class::ShowList(){
	Class::write();
	for (int i=1;i<=total;++i) {
		printf("\t\t%d: ",i);
		s[i].write();
	}
}

void Class::InputScore(){
	system("cls");
	printf("Start...\n");
	Class::ShowList();
	while (1) {
		printf("input:\n\t\tI x y\n\t\tD x\n\t\tE\n");
		char ch=getchar();
		while (ch!='I'&&ch!='D'&&ch!='E') ch=getchar();
		if (ch=='I') {
			int i,j;
			scanf("%d%d",&i,&j);
			s[i].score=j;
		}
		else if (ch=='D') {
			int i;
			scanf("%d",&i);
			Class::Delete(s[i]);
		}
		else break;
		Class::ShowList();
	}
}

/*
*/
