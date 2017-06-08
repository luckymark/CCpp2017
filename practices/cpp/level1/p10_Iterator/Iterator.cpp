#include<iostream>
#include"Iterator.h"

Iterator::Iterator()
{
	current=0;
}

Iterator::Iterator(int *o,int *c)
{
	current=c;
	origin=o;
}

Iterator& Iterator::operator=(Iterator i)
{
	this->origin=i.origin;
	this->current=i.current;
	return *this;
}

bool Iterator::operator==(Iterator i)
{
	return this->current==i.current;
}

bool Iterator::operator!=(Iterator i)
{
	return this->current!=i.current;
}

Iterator& Iterator::operator++()
{
	this->current+=1;
	if(this->current-this->origin==100)
		this->current-=100;
	return *this;
}

int Iterator::operator*()
{
	return *current;
}