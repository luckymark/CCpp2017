#include "SafeArray.h"
#include <cstdio>

SafeArray::SafeArray(){
	data=NULL;
	totalLength=0;
}

SafeArray::~SafeArray(){
	delete []data;
	totalLength=0;
	data=NULL;
}

bool SafeArray::sizeable(const int length){
	totalLength=length;
	data=new int[length];
}

bool SafeArray::write(int index,int number){
	if (index<0||index>=totalLength){
		return false;
	}
	data[index]=number;
	return true;
}

int SafeArray::read(int index){
	if (index<0||index>=totalLength){
		printf("索引越界，返回data[0] ");
		return -1;
	}
	return data[index];
}

int& SafeArray::operator [](int index){
	if (index<0||index>=totalLength){
		printf("索引越界，返回data[0] ");
		return data[0];
	}
	else return data[index];
}


