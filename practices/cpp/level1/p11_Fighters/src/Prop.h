#ifndef PROP_H_
#define PROP_H_
#include "Buff.h"

struct Prop{
	Buff buff;
	int kind;
	int num;
	Prop(){
		kind = 0;
		num = 0;
	}
	Prop(Buff buff,int num);
};

#endif
