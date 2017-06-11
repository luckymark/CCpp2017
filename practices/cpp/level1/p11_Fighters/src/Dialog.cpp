#include "Dialog.h"
#include "Director.h"

Dialog::Dialog(int kind, string item_setting_name, sf::Vector2f pos, Director *world_)
	:Item(kind, item_setting_name, pos, world_){
		cur_face = 0;
		face_num = 42;
		if(!font.loadFromFile("/Library/Fonts/Arial Unicode.ttf")){
			cerr << "fail to open the font" << endl;
		}
		words.push_back(L"蕾米：帕秋，你在哪里?");
		text.setString(L"蕾米：帕秋，你在哪里？");
		words.push_back(L"蕾米：...");
		words.push_back(L"蕾米：我得去找她.");
		words.push_back(L"蕾米：...");
		words.push_back(L"蕾米:算了，帕秋的话，应该能保护好自己?\n我还是先去找弗兰吧\n弗兰在一个密室里，但愿她没事。");
		words.push_back(L"蕾米：诶？这也可能是弗兰的恶作剧啊，我得先去密室看一下。");
		words.push_back(L"...");
		words.push_back(L"前情提要：\n幻想乡发生了异变，\n时空出现了错误");
		words.push_back(L"就在灵梦和咲夜出门调查的时候，\n有可疑的怪物入侵了红魔馆");
		words.push_back(L"就在蕾米正在看家的时候，\n帕秋莉当着她的面消失了。");
		words.push_back(L"蕾米在“思考”过后，决定去密室寻找弗兰");
		words.push_back(L"...");
		words.push_back(L"对不起，我实在是编不出来了");
		words.push_back(L"新手教程加载中.");
		words.push_back(L"新手教程加载中..");
		words.push_back(L"新手教程加载中...");
		words.push_back(L"新手教程加载中....");
		words.push_back(L"新手教程加载中.....");
		words.push_back(L"新手教程加载中......");
		words.push_back(L"新手教程加载中.......");
		words.push_back(L"新手教程加载中........");
		words.push_back(L"新手教程加载中.........");
		words.push_back(L"新手教程加载中..........");
		words.push_back(L"新手教程加载中...........");
		words.push_back(L"新手教程加载中............");
		words.push_back(L"新手教程加载中.............");
		words.push_back(L"新手教程加载中..............");
		words.push_back(L"新手教程加载中...............");
		words.push_back(L"新手教程加载中...............complete");
		words.push_back(L"红魔馆中的空间是错乱的，当你觉得\n你自己迷路了的时候，你最好停下来看看地图");
		words.push_back(L"红魔馆中有很多的门，需要用点力气才能通过。\n现在有很多的怪物在把手");
		words.push_back(L"一共有5中怪物");
		words.push_back(L"第一种叫做金三月半，只能发射基本的子弹");
		words.push_back(L"第二种叫做生化羊驼，可以喷出其他的怪物，是难缠的对手");
		words.push_back(L"第三种叫做人形自走式辅导员，可以发出基本的子弹，干掉之后还死不透");
		words.push_back(L"第四种和第五种是辅导员被干掉之后，它的左和右半身，\n这两种怪物无法发射子弹，但是和他们有身体接触是很危险的。");
		words.push_back(L"WASD控制方向，Q为冲撞技能，鼠标左键发射子弹（自损）\nE抱头蹲防，X符卡技能。");
		words.push_back(L"Q技能有4秒钟冷却时间，按住释放和按一下释放会获得不同的速度");
		words.push_back(L"X技能有10秒钟的冷却时间，必须将动作做到位之后，才能释放");
		words.push_back(L"X技能和Q技能的释放都和鼠标的位置有关");
		words.push_back(L"M键呼出地图，胜利之后，按下Y+R可以重启游戏，\n输了之后按下R可以直接重启游戏,但愿没有什么问题.");
		words.push_back(L"请好好珍惜地图");
		words.push_back(L"鼠标右键可以跳过所有对话");
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
	//world->new_stuff(3,sf::Vector2f(200.0,200.0));
	world -> bgm.open_from_setting("../data/BGM/setting");
	world->delete_stuff(this);
}
