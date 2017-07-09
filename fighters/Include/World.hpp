#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Aircraft.hpp"
#include "Command.hpp"
#include "CommandQueue.hpp"
#include "SoundHolder.hpp"
#include "Flash.h"


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

// Forward declaration
namespace sf
{
	class RenderWindow;
}

class Player;

class World : private sf::NonCopyable
{
public:

	explicit							World(sf::RenderWindow& window,int& mScore, Player* player);
	void								update(sf::Time dt);
	void								draw();

	CommandQueue&						getCommandQueue();

	bool 								hasAlivePlayer() const;
	bool 								hasPlayerReachedEnd() const;
	sf::Vector2f						getViewCenter();
	float								getWorldLength();

private:
	void								loadTextures();
	void								adaptPlayerPosition();
	void								handleCollisions();
	void								randomEvents(sf::Time dt);
	void								randomEnemys(sf::Time dt);
	void								randomTroop(sf::Time dt);

	void								buildScene();
	void								addEnemies();

																//基于当前位置
																//标号为1 向左，2向右
	void								addTroopA1();		
	void								addTroopA2();
	void								addTroopB1();
	void								addTroopB2();
	void								addTroopC1();
	void								addTroopC2();
	void								addTroopD1();
	void								addTroopE1();
	void								addTroopE2();
	void								addEagleA1();
	void								addEagleA2();
	void								addEagleB1();
	void								addEagleB2();
																//基于预设坐标
	void								addTroopA1(float y);		//一列raptor
	void								addTroopA2(float y);
	void								addTroopB1(float y);		//2 raptor + 1 avenger
	void								addTroopB2(float y);
	void								addTroopC1(float y);		//3 raptor + 3 avenger
	void								addTroopC2(float y);
	void								addTroopD1(float y);
	void								addTroopE1(float y);
	void								addTroopE2(float y);
	void								addEagleA1(float y);
	void								addEagleA2(float y);
	void								addEagleB1(float y);
	void								addEagleB2(float y);

	void								addEnemy(Aircraft::Type type, float relX, float relY);
	void								spawnEnemies();
	void								destroyEntitiesOutsideView();
	void								guideMissiles();
	sf::FloatRect						getViewBounds() const;
	sf::FloatRect						getBattlefieldBounds() const;
	void								updateScore(Aircraft& mAircraft);
	void								addAlly();
	void								addFlash(Textures::ID type,float x, float y);



private:
	enum Layer
	{
		Background,
		DownCloud,
		Air,
		UpCloud,
		LayerCount
	};

	struct SpawnPoint
	{
		SpawnPoint(Aircraft::Type type, float x, float y)
			: type(type)
			, x(x)
			, y(y)
		{
		}

		Aircraft::Type type;
		float x;
		float y;
	};

	struct RandomEvents
	{
		RandomEvents(sf::Time RandomEnemyInterval, sf::Time RandomPickupInterval, sf::Time RandomEventsCountdown)
			: RandomEnemyInterval(RandomEnemyInterval)
			, RandomPickupInterval(RandomPickupInterval)
			, RandomEventsCountdown(RandomEventsCountdown)
		{
		}

		sf::Time RandomEnemyInterval;
		sf::Time RandomPickupInterval;

		sf::Time RandomEventsCountdown;
	};


private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	sf::Vector2f						mViewCenter;
	TextureHolder						mTextures;
	FontHolder&							mFonts;
	SoundHolder							mSounds;

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	CommandQueue						mCommandQueue;

	float								mWorldLength;
	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;
	RandomEvents						mRandomEvents;

	std::unique_ptr<Aircraft>   	    mAllies[2];
	std::vector<SpawnPoint>				mEnemySpawnPoints;
	std::vector<Aircraft*>				mActiveEnemies;

	int&								mScore;
	SceneNode							mFlashNode;
	Player*								mPlayer;


};
#endif // BOOK_WORLD_HPP
