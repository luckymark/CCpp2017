#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include "FO.h"
#include <list>
using namespace std;

class Game
{
public:
	Game();
	void NowLoading();
	void loadBackgrounds();
	void loadPrimeFrame();
	void loadPlayer();
	void loadEnemy();
	void loadMusicAndSounds();
	void run();
	void menu();
	void Stage1();
	void frameDisplay();
	void backgroundDisplay();
	void playerAmmoDisplay();
	void enemiesDisplay();
	void playerDisplay();
	void processTaps();
	void playerInput(sf::Keyboard::Key key, bool isPressed);
	friend bool isOutOfBoard(sf::Sprite value);//wait for updating
	void mainProcessing();
	/*friend DWORD WINAPI BGMPlay(LPVOID lpParameter);*/
	~Game();

/*private:
	void checkCollision(PFITERATOR object1, PFITERATOR object2);
	bool checkOverstep(PFITERATOR object);
	*/
private:
	Game* self = this;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight, mIsGrazing, mIsFire;
	sf::RenderWindow mWindow;
	sf::Font font;
	sf::Text text;
	sf::Texture Reimu, Marisa, Sanae, loading, nowLoading, stageSelect, front00, julgePointArray;
	sf::Texture bullets, bg1, bgEff1, bg2, bgEff2, bg3, bgEff3, Enemy1, Enemy2;
	sf::Sprite loadingUI, loadingUISub, back[6], backEff[6], front01, front02, front03, front04;
	sf::Sprite julgePoint, playerAmmo;
	sf::Music menuMusic, stage1BGM, stage2BGM, stage3BGM;
	sf::SoundBuffer playerBulletSoundBuffer, playerBulletSoundBuffer1, enemyBulletSoundBuffer, collisionSoundBuffer, spellCardSoundBuffer, buttomSoundBuffer;
	sf::Sound playerBulletSound, playerBulletSound1, enemyBulletSound, collisionSound, spellCardSound, buttomSound;
	sf::Clock clock;
	FO player;
	list<sf::Sprite> playerBullets, enemyBullets;
	list<sf::Sprite> enemies;

/*	sf::Time globalTime, fireTime;
	sf::Clock fireClock;
	*/
};

