#include "stdafx.h"
#include "Explode_enermy.h"
extern RenderWindow the_window;

Explode_enermy::Explode_enermy(Enermy *mm,int m)
{
	if (0 == m)
	{
		_filename = mm->get_explode()[0];
	}
	if (1== m)
	{
		_filename = mm->get_explode()[1];
	}
	if (2 == m)
	{
		_filename = mm->get_explode()[2];
	}
	
	if (!_image.loadFromFile(_filename))
	{
		cout << "±¬Õ¨Í¼Æ¬¼ÓÔØÊ§°Ü£¡";
	}
	_sprite.setTexture(_image);
	_x = mm->get_x();
	_y = mm->get_y();
	_sprite.setOrigin(_x, _y);
	the_window.draw(_sprite);
}


Explode_enermy::~Explode_enermy()
{
}
