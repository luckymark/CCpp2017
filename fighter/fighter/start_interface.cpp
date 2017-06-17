#include "stdafx.h"
#include "start_interface.h"


start_interface::start_interface()
{
	/*开始界面：
	左边距657px
	上面的521px   226、75
	下面的625px   220, 75*/
	//play的点击范围
	MenuItem playButton;
	playButton.rect.top = 490;
	playButton.rect.left = 657;
	playButton.rect.width = 226;
	playButton.rect.height = 70;
	playButton.action = Play;

	//Exit的点击范围
	MenuItem exitButton;
	exitButton.rect.top =  590;
	exitButton.rect.left = 657;
	exitButton.rect.height = 75;
	exitButton.rect.width = 220;
	exitButton.action = Exit;
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
}


start_interface::~start_interface()
{
}
void start_interface::design_click_area()
{


}

//判断鼠标点击位置是否在矩形区域里面从而返回状态参数
start_interface::MenuResult start_interface::HandleClick(int x, int y)
{
	//迭代器遍历list容器里面存放的点击区域以供判断
	std::list<MenuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.height+ menuItemRect.top > y && menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.width+ menuItemRect.left > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}

//根据鼠标动作来做出相应的响应
start_interface::MenuResult  start_interface::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (1)
	{
		while (window.pollEvent(menuEvent))
		{
			//sf::Event::
			if (menuEvent.type == sf::Event::MouseButtonReleased)//:MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
