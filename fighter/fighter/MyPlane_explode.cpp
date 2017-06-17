#include "stdafx.h"
#include "MyPlane_explode.h"
extern RenderWindow the_window;
MyPlane_explode::MyPlane_explode(My_plane *my)
{

	if (my->get_shooted_time() < my->get_Myplane_life()/3)
	{
		_filename ="image/plane1.png";
		//cout << "��ը������";
	}
	else if(my->get_shooted_time()  >  2*(my->get_Myplane_life()/3))
	{
		_filename ="image/plane2.png";
		//cout << "2��ը����";
	}
	else 
	{
		_filename ="image/plane3.png";
	}
	if (!_image.loadFromFile(_filename)) //������ȡͼƬ
	{
		//cout << "your plane_exploding load failed!"<<_filename;
	}
	_sprite.setTexture(_image);//������ͼƬ
	_x = my->getTexture().getSize().x;
	_y = my->getTexture().getSize().y;
	_sprite.setOrigin(my->get_My_x(),my->get_My_y());
	the_window.draw(_sprite);
}


MyPlane_explode::~MyPlane_explode()
{
}
