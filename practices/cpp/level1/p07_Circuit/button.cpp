#include "stdafx.h"
#include "button.h"


void Button::on()
{
	x->on();
}

void Button::off() {
	x->off();
}

void Button::bind(ele *a) {
	x = a;
}