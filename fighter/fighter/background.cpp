#include "stdafx.h"
#include "background.h"


background::background(string filename)
{
	filename0=filename;//�ļ���
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
	 if(!image0.loadFromFile(filename0))//������ȡͼƬ
	 {
		 //cout << "��������ʧ�ܣ�";
	 }
	 sprite0.setTexture(image0);//������ͼƬ
	 sprite0.setOrigin(0, 0);
}
Sprite background::get_background()
{
	return  sprite0;
}

background::~background()
{
}
