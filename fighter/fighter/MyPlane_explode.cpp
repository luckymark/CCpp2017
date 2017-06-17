#include "stdafx.h"
#include "MyPlane_explode.h"
extern RenderWindow the_window;
MyPlane_explode::MyPlane_explode(My_plane *my)
{

	if (my->get_shooted_time() < my->get_Myplane_life()/3)
	{
		_filename ="image/plane1.png";
		//cout << "爆炸加载了";
	}
	else if(my->get_shooted_time()  >  2*(my->get_Myplane_life()/3))
	{
		_filename ="image/plane2.png";
		//cout << "2爆炸加载";
	}
	else 
	{
		_filename ="image/plane3.png";
	}
	if (!_image.loadFromFile(_filename)) //用来读取图片
	{
		//cout << "your plane_exploding load failed!"<<_filename;
	}
	_sprite.setTexture(_image);//用来存图片
	_x = my->getTexture().getSize().x;
	_y = my->getTexture().getSize().y;
	_sprite.setOrigin(my->get_My_x(),my->get_My_y());
	the_window.draw(_sprite);
}


MyPlane_explode::~MyPlane_explode()
{
}
