#include "stdafx.h"
#include "background.h"


background::background(string filename)
{
	filename0=filename;//文件名
	if (filename0 != "image/start.psd")
	{
		if (background_order == 1)
		{
			filename0 = "image/background1.png";
			background_order = 2;
		}
		else
		{
			filename0 = "image/background2.png";
			background_order = 1;
		}
	}
	 if(!image0.loadFromFile(filename0))//用来读取图片
	 {
		 //cout << "背景加载失败！";
	 }
	 sprite0.setTexture(image0);//用来存图片
	 sprite0.setOrigin(0, 0);
}
Sprite background::get_background()
{
	return  sprite0;
}

background::~background()
{
}
