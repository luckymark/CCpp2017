#ifndef DIALOG_H_
#define DIALOG_H_

#include "Item.h"

class Dialog: public Item{
	private:
		vector<wstring> words;
		sf::Font font;
		sf::Text text;
		int cur_face;
		int face_num;
		sf::Clock click_clock;
	public:
		Dialog(int kind, string item_setting_name, sf::Vector2f pos, Director *world_);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
		virtual void display();
		virtual void dead();
};

#endif
