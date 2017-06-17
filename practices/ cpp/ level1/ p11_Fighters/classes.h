#define move_speed_my_aircraft 2
#define window_lenth 1920
#define window_width 1080
void move_aircraft(sf::Sprite &duixiang)
{
	sf::Vector2f now_position = duixiang.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (now_position.x>53.25)) {
		duixiang.move(-move_speed_my_aircraft, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (now_position.x<window_lenth - 53.25)) {
		duixiang.move(move_speed_my_aircraft, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (now_position.y>75)) {
		duixiang.move(0, -move_speed_my_aircraft);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (now_position.y<window_width - 75)) {
		duixiang.move(0, move_speed_my_aircraft);
	}
}
//飞机类
class AIRCRAFT {
public:
	sf::Texture tex_aircraft;
	sf::Sprite aircraft;
};
//boss_1
class BOSS_1 :public AIRCRAFT
{
public:
	int if_exist = 0;
	int life = 0;
	int judge = 1;
	BOSS_1()
	{
		if (!tex_aircraft.loadFromFile("boss_1.png")) {
			// error...
		}
		aircraft.setTexture(tex_aircraft);
		aircraft.setOrigin(49, 40);
		aircraft.setScale(2.0f, 2.0f);
	}
};
//boss_2
class BOSS_2 :public AIRCRAFT
{
public:
	int if_exist = 0;
	int life = 0;
	BOSS_2()
	{
		if (!tex_aircraft.loadFromFile("boss_2.png")) {
			// error...
		}
		aircraft.setTexture(tex_aircraft);
		aircraft.setOrigin(70, 58.5);
		aircraft.setScale(1.0f, 1.0f);
	}
};
//enemy_1
class ENEMY_AIRCRAFT :public AIRCRAFT
{
public:
	int if_exist = 0;
	ENEMY_AIRCRAFT()
	{
		if (!tex_aircraft.loadFromFile("enemy_1.png")) {
			// error...
		}
		aircraft.setTexture(tex_aircraft);
		aircraft.setOrigin(41, 30.5);
		aircraft.setScale(2.0f, 2.0f);
	}
};
//enemy_2
class ENEMY_AIRCRAFT_2 :public AIRCRAFT
{
public:
	int if_exist = 0;
	int fly_way = 1;
	ENEMY_AIRCRAFT_2()
	{
		if (!tex_aircraft.loadFromFile("enemy_2.png")) {
			// error...
		}
		aircraft.setTexture(tex_aircraft);
		aircraft.setOrigin(42, 45);
		aircraft.setScale(0.8f, 0.8f);
	}
};
//my_aircraft
class MY_AIRCRAFT :public AIRCRAFT
{
public:
	MY_AIRCRAFT()
	{
		if (!tex_aircraft.loadFromFile("my_aircraft.png")) {
			// error...
		}
		aircraft.setTexture(tex_aircraft);
		aircraft.setOrigin(41.5, 26);
		aircraft.setPosition(960, 930);
		aircraft.setScale(2.0f, 2.0f);
	}
};
//导弹类
class MISSILE {
public:
	sf::Texture tex_missile;
	sf::Sprite missile;
};
//我方导弹类
class MY_MISSILE :public MISSILE
{
public:
	int if_exist = 0;
	MY_MISSILE()
	{
		if (!tex_missile.loadFromFile("missile.png")) {
			// error...
		}
		missile.setTexture(tex_missile);
		missile.setOrigin(12, 11);
		missile.setScale(2.0f, 2.0f);
	}
};
//energy
class ENERGY :public MISSILE
{
public:
	int if_exist = 0;
	ENERGY()
	{
		if (!tex_missile.loadFromFile("energy.png")) {
			//error...
		}
		missile.setTexture(tex_missile);
		missile.setOrigin(33, 32);
		missile.setScale(1.0f, 1.0);
	}
};
//敌机导弹类
class ENEMY_MISSILE :public MISSILE
{
public:
	int if_exist = 0;
	ENEMY_MISSILE()
	{
		if (!tex_missile.loadFromFile("enemy_missile_1.png")) {
			// error...
		}
		missile.setTexture(tex_missile);
		missile.setOrigin(14.5, 25);
		missile.setScale(1.5f, 1.5f);
	}
};
//blood_plus
class BLOOD_PLUS :public MISSILE
{
public:
	int if_exist = 0;
	BLOOD_PLUS()
	{
		if (!tex_missile.loadFromFile("blood.png")) {
			//error...
		}
		missile.setTexture(tex_missile);
		missile.setOrigin(13, 11.5);
		missile.setScale(2.0f, 2.0f);
	}
};
