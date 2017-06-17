#pragma once
#include "Resolve_interface.h"
//#include "Object_manage.h"
class Object_manage;
class start_interface
{
public:
	enum MenuResult { Nothing, Exit, Play };
	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	start_interface();
	~start_interface();

	void design_click_area();
private:
	friend class Object_manage;
	list<MenuItem> _menuItems;
};

