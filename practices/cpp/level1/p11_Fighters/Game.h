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
	void loadPointsAndEffs();
	void loadEnemy();
	void loadMusicAndSounds();
	void run();
	void menu();
	void Stage1();
	int S1E1();
	int S1E2();
	int S1E3();
	void pushToDraw(list<FO>::iterator it);
	void frameDisplay();
	void backgroundDisplay();
	void playerAmmoDisplay();
	void enemiesDisplay();
	void enemyBulletsDisplay();
	void playerDisplay();
	void effsDisplay();
	void enemyCollisionProcessing(list<FO>::iterator it);
	void enemyUnderAttack(list<FO>::iterator it, list<sf::Sprite>::iterator itAmmo);
	void enemyCrash(list<FO>::iterator it);
	void setRoundSnipe(list<FO>::iterator it, double speed);
	void setSharpRandom(list<FO>::iterator it, double speed);
	void processTaps();
	void playerInput(sf::Keyboard::Key key, bool isPressed);
	friend bool isOutOfBoard(sf::Sprite value);//wait for updating
	friend bool isFOOutOfBoard(FO value);//wait for updating
	void mainProcessing();
	bool checkCollision(sf::Sprite obj1, sf::Sprite obj2);
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
	sf::Texture loading, nowLoading, stageSelect, front00, julgePointArray, Title1, allBullets1, allBullets2;
	sf::Texture bullets, buffetsEff, deathCircle, bg1, bgEff1, bg2, bgEff2, bg3, bgEff3, Enemy1, Enemy2;
	sf::Sprite loadingUI, loadingUISub, back[6], backEff[6], front01, front02, front03, front04;
	sf::Sprite julgePoint, playerAmmo, AmmoEff, deathEff;
	sf::Music menuMusic, stage1BGM, stage2BGM, stage3BGM;
	sf::SoundBuffer playerBulletSoundBuffer, playerBulletSoundBuffer1, enemyBulletSoundBuffer, collisionSoundBuffer, spellCardSoundBuffer, buttomSoundBuffer;
	sf::SoundBuffer breakSoundBuffer;
	sf::Sound playerBulletSound, playerBulletSound1, enemyBulletSound, collisionSound, spellCardSound, buttomSound;
	sf::Sound breakSound;
	sf::Clock clock;
	FO player;
	list<FO>  enemyBullets;
	list<sf::Sprite> playerBullets, deathEffs;
	list<sf::Sprite> enemies, playerBulletsEffs;
	int remnant;
};

