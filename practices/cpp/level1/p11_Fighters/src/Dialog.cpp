#include "Dialog.h"
#include "Director.h"

Dialog::Dialog(int kind, string item_setting_name, sf::Vector2f pos, Director *world_)
	:Item(kind, item_setting_name, pos, world_){
		cur_face = 0;
		face_num = 42;
		if(!font.loadFromFile("/Library/Fonts/Arial Unicode.ttf")){
			cerr << "fail to open the font" << endl;
		}
		words.push_back(L"你好");
		text.setString(L"你好");
		words.push_back(L"我叫蕾米莉亚");
		words.push_back(L"我想试一下sfml能不能换行\n以下是测试内容");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		words.push_back(L"123");
		animation[cur_animation].initlize();
		animation[cur_animation].set_position(sf::Vector2f(400,400));
		text.setFont(font);
		text.setCharacterSize(24);
		text.setPosition(sf::Vector2f(10,10));
	}
void Dialog::Action(sf::Time dt, sf::Vector2f pos){
	if(cur_face == face_num-1 || sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		dead();
		return;
	}
	if(click_clock.getElapsedTime().asSeconds() > 1.0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		animation[cur_animation].next_frame();
		text.setString(words[++cur_face]);
		click_clock.restart();
	}
}

void Dialog::display(){
	/*set positioon*/
	animation[cur_animation].set_play_flag(1);
	animation[cur_animation].set_sound_flag(0);
	animation[cur_animation].begin_cur_display(&(world -> window));
	world -> window.draw(text);
}

void Dialog::dead(){
	world->new_stuff(5,sf::Vector2f(0,0));
	world->new_stuff(2,sf::Vector2f(50,50));
	world->new_stuff(0,sf::Vector2f(400.0,400.0));
	world->new_stuff(3,sf::Vector2f(200.0,200.0));
	world -> bgm.open_from_setting("../data/BGM/setting");
	world->delete_stuff(this);
}
