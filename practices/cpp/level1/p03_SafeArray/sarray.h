#pragma once
#ifndef SARRAY_H_
#define SARRAY_H_
class sarrayi {
public:
	sarrayi(int i);
	~sarrayi();
	int & operator [](int i);
private:
	int len;
	int * pt;
};
#endif