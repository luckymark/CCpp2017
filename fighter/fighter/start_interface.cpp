#include "stdafx.h"
#include "start_interface.h"


start_interface::start_interface()
{
	/*��ʼ���棺
	��߾�657px
	�����521px   226��75
	�����625px   220, 75*/
	//play�ĵ����Χ
	MenuItem playButton;
	playButton.rect.top = 490;
	playButton.rect.left = 657;
	playButton.rect.width = 226;
	playButton.rect.height = 70;
	playButton.action = Play;

	//Exit�ĵ����Χ
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

//�ж������λ���Ƿ��ھ�����������Ӷ�����״̬����
start_interface::MenuResult start_interface::HandleClick(int x, int y)
{
	//����������list���������ŵĵ�������Թ��ж�
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

//������궯����������Ӧ����Ӧ
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
