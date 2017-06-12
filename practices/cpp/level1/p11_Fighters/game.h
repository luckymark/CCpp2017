#include"enemy.h"
#include <stdlib.h>
#include <time.h>


class Game
{
public:
	Game();//Y
	void run();//Y

private:
	void processEvents();//Y
	void update(sf::Time deltaTime);//Y
	void render();//Y
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void enemyAction();
	void checkCollide();
	void deleteCrash();
	sf::RenderWindow mWindow;//Y
	Hero* mPlayer;

    //std::vector<Entity*> allEntity;
    std::vector<Enemy*>allEnemy;
	sf::Texture backgroundText;
	sf::Texture gameover;
	//sf::Texture congratulaton;
	sf::Sprite background;
	sf::Music BGM1;
	int PlayerHP,Score;
	sf::Font font;
	sf::Text mScore,mHP;
	bool haveBoss,victory,fail;
};
