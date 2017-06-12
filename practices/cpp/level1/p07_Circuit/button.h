#pragma once
#include "ele.h"
class Button {
public:
	void on();
	void off();
	void bind(ele *a);
private:
	ele * x;
};

