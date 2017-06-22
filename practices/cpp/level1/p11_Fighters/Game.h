#ifndef GAME_H_
#define GAME_H_
#define F_SPEED 18
#include<Windows.h>
#include"Score.h"
#include"window.h"
class Ammo {
public:
	Ammo();
	~Ammo();
	enum ammotype { M, L, F, C };
	void SetAmmo(ammotype type = C);
	void Ammo::Dynamic();
	sf::Sprite * common;
	sf::Sprite * extra;
	sf::Vector2f place[6];
	sf::Sprite C1_;
	sf::Sprite C2_;
	sf::Sprite C3_;
private:
	ammotype type;
	sf::Sprite * pt = nullptr;
	sf::Texture M_Texture;
	sf::Texture L_Texture;
	sf::Texture F_Texture;
	sf::Texture C1_Texture;
	sf::Texture C2_Texture;
	sf::Texture C3_Texture;
	sf::Sprite M_;
	sf::Sprite L_;
	sf::Sprite F_;
	sf::Time time;
	sf::Clock clock;
};

class Rain {
private:
	sf::Time time;
	sf::Clock clock;
	sf::Time m_time;
	sf::Clock m_clock;
	bool control[15];
	void move();
	int randnew;
	void newrain();
	int ct;
	sf::Vector2f sign[15];
	bool m_statu;
public:
	sf::Sprite rainS[4];
	sf::Texture rainT[4];
	void setnew(bool);
	sf::Vector2f &getPos(int i);               
	void setPos(const sf::Vector2f &l_pos);
	~Rain();
	Rain();
	void update();
};
class sound {
public:
	sound();
	~sound();
	void isShoot();
	void playback();
	void playboom();
	void playrest();
	void playstart();
private:
	sf::SoundBuffer backbuf;
	sf::Sound backmusic;
	sf::SoundBuffer shootbuf;
	sf::Sound shootmusic;
	sf::SoundBuffer boombuf;
	sf::Sound boommusic;
	sf::SoundBuffer restbuf;
	sf::Sound restmusic;
	sf::SoundBuffer startbuf;
	sf::Sound startmusic;
};
class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	Ammo ammo;
	Rain rain;
	sound Sound;
	void collision(Ammo &ammo);
	void endGame();
private:
	void MoveFighter();
	void fire();
	void showboom(int i);
	void boom();
	bool begin;
	void collision();
	int lives;
	bool setrest;
	int restct;
	void beshoot();
	void show_behind();
	void showrain();
	void showBegin();
	void showEnd();
	Window m_window;
	sf::Time BoomTime[12];
	sf::Time restT;
	sf::Time t_rain;
	sf::Time bT;
	sf::Time next;//调节背景帧
	sf::Time time;
	sf::Time safeT;
	sf::Time end_T;
	sf::Clock BoomClock[12];
	sf::Clock restC;
	sf::Clock clock;
	sf::Clock cloc;
	sf::Clock c_rain;
	sf::Clock bc;
	sf::Clock safeC;
	sf::Clock end_C;
	sf::Vector2f boompc[12];
	sf::Sprite behind[152];
	sf::Sprite m_fighter;
	sf::Sprite m_backdrop;
	sf::Sprite BoomS[12];
	sf::Sprite startS;
	sf::Sprite end_S;
	sf::Sprite back2[6];
	sf::Texture behindT[152];
	sf::Texture backT[6];
	sf::Texture BoomT[12];
	sf::Texture startT;
	sf::Texture m_fighterTexture;
	sf::Texture m_backdropTexture;
	sf::Texture endT;
	int back;
	bool shoot;
	int ct;//标记子弹数据的写入位置
	int back_2;
	int cp[12];
	int bct;
	Score score;
	bool end;
	bool beginpicture;
};
#endif