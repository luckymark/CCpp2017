#include "Include\World.hpp"
#include"Include\Projectile.hpp"
#include "Include\Foreach.hpp"
#include"Include\Player.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


#include <algorithm>
#include <cmath>
#include <limits>

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);

World::World(sf::RenderWindow& window, int& mScore, sf::Time* mTime, Player* player)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mFonts(mFonts)
	, mSounds()
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 20000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mViewCenter(mSpawnPosition)
	, mScrollSpeed(-50.f)
	, mPlayerAircraft(nullptr)
	, mEnemySpawnPoints()
	, mAllies()
	, mActiveEnemies()
	, mRandomEvents(sf::seconds(5), sf::seconds(10), sf::seconds(0))
	, mScore(mScore)
	, mTime(mTime)
//	, mBloom(NULL)
	, mPlayer(player)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Scroll the world, reset player velocity
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	mViewCenter.y -= mScrollSpeed * dt.asSeconds();
	randomEvents(dt);

	mPlayerAircraft->setVelocity(0.f, 0.f);

	

	// Setup commands to destroy entities, and guide missiles
	destroyEntitiesOutsideView();
	guideMissiles();

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);

	//adjust the velocity of  diagonal movements 
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();
	if (velocity.x != 0.f && velocity.y != 0.f)        
		mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));

	mPlayerAircraft->accelerate(0.f, mScrollSpeed);		//使玩家与屏幕相对静止

	// Collision detection and response (may destroy entities)
	handleCollisions();

	// Remove all destroyed entities, create new ones
	mSceneGraph.removeWrecks();
	spawnEnemies();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(dt, mCommandQueue);	//此函数实现飞机的位移，调用了entity的  virtual void		updateCurrent(sf::Time dt, CommandQueue& commands);

	adaptPlayerPosition();
	mSounds.emptyQueue();


	mFlashNode.update(dt);
	mFlashNode.removeWrecks();		//移除过期爆炸节点


	mScore = mPlayerAircraft->getScore();
	
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);

	mWindow.draw(mFlashNode);

}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

bool World::hasAlivePlayer() const
{
	return !mPlayerAircraft->isMarkedForRemoval();
}

bool World::hasPlayerReachedEnd() const
{
	return !mWorldBounds.contains(mPlayerAircraft->getPosition());
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
	mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
	mTextures.load(Textures::Avenger, "Media/Textures/Avenger.png");
	mTextures.load(Textures::Desert, "Media/Textures/Desert.png");

	mTextures.load(Textures::Bullet, "Media/Textures/Bullet.png");
	mTextures.load(Textures::Missile, "Media/Textures/Missile.png");

	mTextures.load(Textures::HealthRefill, "Media/Textures/HealthRefill.png");
	mTextures.load(Textures::MissileRefill, "Media/Textures/MissileRefill.png");
	mTextures.load(Textures::FireSpread, "Media/Textures/FireSpread.png");
	mTextures.load(Textures::FireRate, "Media/Textures/FireRate.png");

	mTextures.load(Textures::Explosion, "Media/Textures/Explosion.png");
}

void World::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds = getViewBounds();
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerAircraft->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance-30);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance+30);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance+10);
	mPlayerAircraft->setPosition(position);
}



bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
	unsigned int category1 = colliders.first->getCategory();
	unsigned int category2 = colliders.second->getCategory();

	// Make sure first pair entry has category type1 and second has type2
	if (type1 & category1 && type2 & category2)
	{
		return true;
	}
	else if (type1 & category2 && type2 & category1)
	{
		std::swap(colliders.first, colliders.second);
		return true;
	}
	else
	{
		return false;
	}
}


void World::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		Category::Type category = (i == Air) ? Category::SceneAirLayer : Category::None;

		SceneNode::Ptr layer(new SceneNode(category));
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Aircraft> player(new Aircraft(mWindow,Aircraft::Eagle, mTextures, mFonts,mSounds,true,mPlayer));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mSceneLayers[Air]->attachChild(std::move(player));

	// Add enemy aircraft
	addEnemies();

}

void World::updateScore(Aircraft& mAircraft)
{
	if (!mAircraft.isAllied() && mAircraft.isDestroyed())
	{
		switch (mAircraft.getType())
		{
		case Aircraft::Type::Raptor:
		case Aircraft::Type::RaptorA1:
		case Aircraft::Type::RaptorA2:
		case Aircraft::Type::RaptorB1:
		case Aircraft::Type::RaptorB2:
		case Aircraft::Type::RaptorC1:
		case Aircraft::Type::RaptorC2:
		case Aircraft::Type::RaptorD1:
		case Aircraft::Type::RaptorD2:
			mScore += 10;
			mPlayerAircraft->addPoints(1);
			break;
		case Aircraft::Type::Avenger:
		case Aircraft::Type::AvengerA1:
		case Aircraft::Type::AvengerA2:
		case Aircraft::Type::AvengerB1:
		case Aircraft::Type::AvengerB2:
		case Aircraft::Type::AvengerC1:
		case Aircraft::Type::AvengerC2:
		case Aircraft::Type::AvengerD1:
		case Aircraft::Type::AvengerD2:
			mScore += 15;
			mPlayerAircraft->addPoints(3);
			break;
		case Aircraft::Type::EagleA1:
		case Aircraft::Type::EagleA2:
		case Aircraft::Type::EagleB1:
		case Aircraft::Type::EagleB2:
			mScore += 40;
			mPlayerAircraft->addPoints(10);
			break;
		}
		mSounds.play(SoundEffect::Explosion2);
		mPlayerAircraft->updateScore(mScore);
		addFlash(Textures::Explosion,mAircraft.getPosition().x, mAircraft.getPosition().y);
	}

}

void World::addEnemies()
{


	addEagleA1(5000);
	addEagleA2(8000);
	addEagleB1(10000);
	addEagleB2(18000);

	addEagleA1(13000);
	addEagleA2(15000);
	addEagleB1(14000);
	addEagleB2(16000);

	
	// Add enemies to the spawn point container
	addEnemy(Aircraft::Raptor, 0.f, 500.f);
	addEnemy(Aircraft::Raptor, 0.f, 700.f);
	addEnemy(Aircraft::Raptor, 0.f, 700.f);
	addEnemy(Aircraft::Raptor, 0.f, 1000.f);


	addTroopA1(1500);


	addEnemy(Aircraft::Raptor, +300.f, 2000.f);
	addEnemy(Aircraft::Raptor, -300.f, 2000.f);
	addEnemy(Aircraft::Raptor, 0.f, 2100.f);

	addEnemy(Aircraft::Avenger, +140.f, 2600.f);
	addEnemy(Aircraft::Avenger, -140.f, 2600.f);

	addTroopA2(3000);

	addEnemy(Aircraft::Raptor, +200.f, 3300.f);
	addEnemy(Aircraft::Raptor, -200.f, 3300.f);
	addEnemy(Aircraft::Raptor, 0.f, 3500.f);
	addEnemy(Aircraft::Avenger, +240.f, 3500.f);
	addEnemy(Aircraft::Avenger, -240.f, 3500.f);
	addEnemy(Aircraft::Raptor, +400.f, 3700.f);
	addEnemy(Aircraft::Raptor, -400.f, 3700.f);
	addEnemy(Aircraft::Raptor, 0.f, 3900.f);


	addEnemy(Aircraft::Avenger, +70.f, 4500.f);
	addEnemy(Aircraft::Avenger, -70.f, 4500.f);
	addEnemy(Aircraft::Avenger, +140.f, 4700.f);
	addEnemy(Aircraft::Avenger, -140.f, 4700.f);

	addTroopE2(5000);





	addEnemy(Aircraft::Raptor, +100.f, 6500.f);
	addEnemy(Aircraft::Raptor, -100.f, 6500.f);
	addEnemy(Aircraft::Avenger, -70.f, 6800.f);


	addTroopA1(8000);
	addTroopA2(8000);


	addTroopD1(9000);

	addEnemy(Aircraft::Raptor, 0.f, 500.f+8000);
	addEnemy(Aircraft::Raptor, 0.f, 700.f + 8000);
	addEnemy(Aircraft::Raptor, 0.f, 700.f + 8000);
	addEnemy(Aircraft::Raptor, 0.f, 1000.f + 8000);


	addTroopA1(1500 + 8000);


	addEnemy(Aircraft::Raptor, +300.f, 2000.f + 8000);
	addEnemy(Aircraft::Raptor, -300.f, 2000.f + 8000);
	addEnemy(Aircraft::Raptor, 0.f, 2100.f + 8000);

	addEnemy(Aircraft::Avenger, +140.f, 2600.f + 8000);
	addEnemy(Aircraft::Avenger, -140.f, 2600.f + 8000);

	addTroopA2(3000 + 8000);

	addEnemy(Aircraft::Raptor, +200.f, 3300.f + 8000);
	addEnemy(Aircraft::Raptor, -200.f, 3300.f + 8000);
	addEnemy(Aircraft::Raptor, 0.f, 3500.f);
	addEnemy(Aircraft::Raptor, +400.f, 3700.f + 8000);
	addEnemy(Aircraft::Raptor, -400.f, 3700.f + 8000);
	addEnemy(Aircraft::Raptor, 0.f, 3900.f + 8000);

	addTroopB1(4500 + 8000);
	addTroopB2(4500 + 8000);


	addEnemy(Aircraft::Avenger, +70.f, 5000.f + 8000);
	addEnemy(Aircraft::Avenger, -70.f, 5000.f + 8000);
	addEnemy(Aircraft::Avenger, +140.f, 5200.f + 8000);
	addEnemy(Aircraft::Avenger, -140.f, 5200.f + 8000);

	addTroopA1(5500 + 8000);
	addTroopA2(5500 + 8000);

	addTroopD1(6000 + 8000);

	addEnemy(Aircraft::Raptor, +100.f, 6500.f + 8000);
	addEnemy(Aircraft::Raptor, -100.f, 6500.f + 8000);
	addEnemy(Aircraft::Avenger, -70.f, 6800.f + 8000);
	addEnemy(Aircraft::Avenger, -70.f, 7000.f + 8000);
	addEnemy(Aircraft::Avenger, 70.f, 7400.f + 8000);
	addEnemy(Aircraft::Avenger, 70.f, 7600.f + 8000);





	// Sort all enemies according to their y value, such that lower enemies are checked first for spawning
	std::sort(mEnemySpawnPoints.begin(), mEnemySpawnPoints.end(), [](SpawnPoint lhs, SpawnPoint rhs)
	{
		return lhs.y < rhs.y;
	});
}

void World::addTroopA1(float y)
{
	for (int i = 0; i < 6; i++)
	{
		addEnemy(Aircraft::RaptorA1,100  + i * 50, y + i * 15);
	}
}

void World::addTroopA2(float y)
{
	for (int i = 0; i < 6; i++)
	{
		addEnemy(Aircraft::RaptorA2, -100 - i * 50, y + i * 15);
	}
}

void World::addTroopA1()
{
	for (int i = 0; i < 6; i++)
	{
		addEnemy(Aircraft::RaptorA1,100+i*50, mViewCenter.y + 500 + i*15);
	}
}

void World::addTroopA2()
{
	for (int i = 0; i < 6; i++)
	{
		addEnemy(Aircraft::RaptorA2, -100 - i * 50, mViewCenter.y + 500 + i * 15);
	}
}

void World::addTroopB1()
{
	addEnemy(Aircraft::RaptorA1, 100 + 1 * 50, mViewCenter.y + 500);
	addEnemy(Aircraft::RaptorA1, 100 + 3 * 50, mViewCenter.y + 500);
	addEnemy(Aircraft::AvengerA1, 100 + 2 * 30, mViewCenter.y + 500 + 40);
}

void World::addTroopB2()
{
	addEnemy(Aircraft::RaptorA2, -100 - 1 * 50, mViewCenter.y+500);
	addEnemy(Aircraft::RaptorA2, -100 - 3 * 50, mViewCenter.y+500);
	addEnemy(Aircraft::AvengerA2, -100 - 2 * 30, mViewCenter.y + 500+40);
}

void World::addTroopC1()
{	
	addEnemy(Aircraft::RaptorB1, 50 + 0 * 50, mViewCenter.y + 500+40);
	addEnemy(Aircraft::RaptorB1, 50 + 2 * 50, mViewCenter.y + 500);
	addEnemy(Aircraft::RaptorB1, 50 + 4 * 50, mViewCenter.y + 500+40);

	addEnemy(Aircraft::AvengerB1, 50 - 1 * 50, mViewCenter.y + 500 + 100);
	addEnemy(Aircraft::AvengerB1, 50 + 2 * 50, mViewCenter.y + 500+70);
	addEnemy(Aircraft::AvengerB1, 50 + 5 * 50, mViewCenter.y + 500 + 100);
}

void World::addTroopC2()
{
	addEnemy(Aircraft::RaptorB1, -50 - 0 * 50, mViewCenter.y + 500 + 40);
	addEnemy(Aircraft::RaptorB1, -50 - 2 * 50, mViewCenter.y + 500);
	addEnemy(Aircraft::RaptorB1, -50 - 4 * 50, mViewCenter.y + 500 + 40);

	addEnemy(Aircraft::AvengerB1, -50 + 1 * 50, mViewCenter.y + 500 + 100);
	addEnemy(Aircraft::AvengerB1, -50 - 2 * 50, mViewCenter.y + 500 + 70);
	addEnemy(Aircraft::AvengerB1, -50 - 5 * 50, mViewCenter.y + 500 + 100);
}

void World::addTroopD1()
{
	addEnemy(Aircraft::RaptorC1, 0 , mViewCenter.y + 500 + 30);
	addEnemy(Aircraft::RaptorC1, 0 , mViewCenter.y + 500);
	addEnemy(Aircraft::RaptorC1, 0 , mViewCenter.y + 500 + 60);

	addEnemy(Aircraft::AvengerC1, 50 + 1 * 25, mViewCenter.y + 500 + 90);
	addEnemy(Aircraft::AvengerC1, 50 + 3 * 25, mViewCenter.y + 500 + 50);
	addEnemy(Aircraft::AvengerC1, 50 + 5 * 25, mViewCenter.y + 500 + 10);

	addEnemy(Aircraft::AvengerC2, -50 - 1 * 25, mViewCenter.y + 500 + 90);
	addEnemy(Aircraft::AvengerC2, -50 - 3 * 25, mViewCenter.y + 500 + 50);
	addEnemy(Aircraft::AvengerC2, -50 - 5 * 25, mViewCenter.y + 500 + 10);
}

void World::addTroopE1()
{
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 );
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500+40 );
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 +80);
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 +120);
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 +160);
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 + 200);
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 + 240);
	addEnemy(Aircraft::RaptorD1, +150 , mViewCenter.y + 500 + 280);

	addEnemy(Aircraft::AvengerD1, +150 -100, mViewCenter.y + 500 + 73);
	addEnemy(Aircraft::AvengerD1, +150 - 100, mViewCenter.y + 500 + 25);



}

void World::addTroopE2()
{
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 40);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 80);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 120);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 160);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 200);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 240);
	addEnemy(Aircraft::RaptorD2, -150, mViewCenter.y + 500 + 280);

	addEnemy(Aircraft::AvengerD2, -150 + 100, mViewCenter.y + 500 + 73);
	addEnemy(Aircraft::AvengerD2, -150 + 100, mViewCenter.y + 500 + 25);
}

void World::addEagleA1()
{
	addEnemy(Aircraft::EagleA1, 0, mViewCenter.y + 300 );
}

void World::addEagleA2()
{
	addEnemy(Aircraft::EagleA2, 0, mViewCenter.y + 300);
}

void World::addEagleB1()
{
	addEnemy(Aircraft::EagleB1, 0, mViewCenter.y + 500);
}

void World::addEagleB2()
{
	addEnemy(Aircraft::EagleB2, 0, mViewCenter.y + 500);
}

void World::addEagleA1(float y)
{
	addEnemy(Aircraft::EagleA1, 0, y);
}

void World::addEagleA2(float y)
{
	addEnemy(Aircraft::EagleA2, 0, y);
}

void World::addEagleB1(float y)
{
	addEnemy(Aircraft::EagleB1, 0, y);
}

void World::addEagleB2(float y)
{
	addEnemy(Aircraft::EagleB2, 0, y);
}


void World::addTroopB1(float y)
{
	addEnemy(Aircraft::RaptorA1, 100 + 1 * 50, y );
	addEnemy(Aircraft::RaptorA1, 100 + 3 * 50, y );
	addEnemy(Aircraft::AvengerA1, 100 + 2 * 37, y + 25);		//x+2*38,y+25不要更改
}

void World::addTroopB2(float y)
{
	addEnemy(Aircraft::RaptorA2, -100 - 1 * 50, y);
	addEnemy(Aircraft::RaptorA2, -100 - 3 * 50, y);
	addEnemy(Aircraft::AvengerA2, -100 - 2 * 37, y + 25);		//y+25不要更改
}

void World::addTroopC1(float y)
{
	addEnemy(Aircraft::RaptorB1, 50 + 0 * 50, y + 40);
	addEnemy(Aircraft::RaptorB1, 50 + 2 * 50, y);
	addEnemy(Aircraft::RaptorB1, 50 + 4 * 50, y + 40);

	addEnemy(Aircraft::AvengerB1, 50 - 1 * 50, y + 100);
	addEnemy(Aircraft::AvengerB1, 50 + 2 * 50, y + 70);
	addEnemy(Aircraft::AvengerB1, 50 + 5 * 50, y + 100);
}

void World::addTroopC2(float y)
{
	addEnemy(Aircraft::RaptorB1, -50 - 0 * 50, y + 40);
	addEnemy(Aircraft::RaptorB1, -50 - 2 * 50, y);
	addEnemy(Aircraft::RaptorB1, -50 - 4 * 50, y + 40);

	addEnemy(Aircraft::AvengerB1, -50 + 1 * 50, y + 100);
	addEnemy(Aircraft::AvengerB1, -50 - 2 * 50, y + 70);
	addEnemy(Aircraft::AvengerB1, -50 - 5 * 50, y + 100);
}

void World::addTroopD1(float y)
{
	addEnemy(Aircraft::RaptorC1, 0, y + 30);
	addEnemy(Aircraft::RaptorC1, 0, y);
	addEnemy(Aircraft::RaptorC1, 0, y + 60);

	addEnemy(Aircraft::AvengerC1, 50 + 1 * 25, y + 90);
	addEnemy(Aircraft::AvengerC1, 50 + 3 * 25, y + 50);
	addEnemy(Aircraft::AvengerC1, 50 + 5 * 25, y + 10);

	addEnemy(Aircraft::AvengerC2, -50 - 1 * 25, y + 90);
	addEnemy(Aircraft::AvengerC2, -50 - 3 * 25, y + 50);
	addEnemy(Aircraft::AvengerC2, -50 - 5 * 25, y + 10);
}

void World::addTroopE1(float y)
{
	addEnemy(Aircraft::RaptorD1, +150, y);
	addEnemy(Aircraft::RaptorD1, +150, y + 40);
	addEnemy(Aircraft::RaptorD1, +150, y + 80);
	addEnemy(Aircraft::RaptorD1, +150, y + 120);
	addEnemy(Aircraft::RaptorD1, +150, y + 160);
	addEnemy(Aircraft::RaptorD1, +150, y + 200);
	addEnemy(Aircraft::RaptorD1, +150, y + 240);
	addEnemy(Aircraft::RaptorD1, +150, y + 280);

	addEnemy(Aircraft::AvengerD1, +150 - 100, y + 73);
	addEnemy(Aircraft::AvengerD1, +150 - 100, y + 25);
}

void World::addTroopE2(float y)
{
	addEnemy(Aircraft::RaptorD2, -150, y);
	addEnemy(Aircraft::RaptorD2, -150, y + 40);
	addEnemy(Aircraft::RaptorD2, -150, y + 80);
	addEnemy(Aircraft::RaptorD2, -150, y + 120);
	addEnemy(Aircraft::RaptorD2, -150, y + 160);
	addEnemy(Aircraft::RaptorD2, -150, y + 200);
	addEnemy(Aircraft::RaptorD2, -150, y + 240);
	addEnemy(Aircraft::RaptorD2, -150, y + 280);

	addEnemy(Aircraft::AvengerD2, -150 + 100, y + 73);
	addEnemy(Aircraft::AvengerD2, -150 + 100, y + 25);
}



void World::addEnemy(Aircraft::Type type, float relX, float relY)
{
	SpawnPoint spawn(type, mSpawnPosition.x + relX, mSpawnPosition.y - relY);
	mEnemySpawnPoints.push_back(spawn);
}

void World::spawnEnemies()
{
	// Spawn all enemies entering the view area (including distance) this frame
	while (!mEnemySpawnPoints.empty()
		&& mEnemySpawnPoints.back().y > getBattlefieldBounds().top+85)
	{
		SpawnPoint spawn = mEnemySpawnPoints.back();

		std::unique_ptr<Aircraft> enemy(new Aircraft(mWindow,spawn.type, mTextures, mFonts,mSounds,false));
		enemy->setPosition(spawn.x, spawn.y);
		enemy->setRotation(180.f);

		mSceneLayers[Air]->attachChild(std::move(enemy));

		// Enemy is spawned, remove from the list to spawn
		mEnemySpawnPoints.pop_back();
	}
}

void World::destroyEntitiesOutsideView()
{
	Command command;
	command.category = Category::Projectile | Category::EnemyAircraft;
	command.action = derivedAction<Entity>([this](Entity& e, sf::Time)
	{
		if (!getBattlefieldBounds().intersects(e.getBoundingRect()))
			e.destroy();
	});

	mCommandQueue.push(command);
}

void World::guideMissiles()
{
	// Setup command that stores all enemies in mActiveEnemies
	Command enemyCollector;
	enemyCollector.category = Category::EnemyAircraft;
	enemyCollector.action = derivedAction<Aircraft>([this](Aircraft& enemy, sf::Time)
	{
		if (!enemy.isDestroyed())
			mActiveEnemies.push_back(&enemy);
	});

	// Setup command that guides all missiles to the enemy which is currently closest to the player
	Command missileGuider;
	missileGuider.category = Category::AlliedProjectile;
	missileGuider.action = derivedAction<Projectile>([this](Projectile& missile, sf::Time)
	{
		// Ignore unguided bullets
		if (!missile.isGuided())
			return;

		float minDistance = std::numeric_limits<float>::max();
		Aircraft* closestEnemy = nullptr;

		// Find closest enemy
		FOREACH(Aircraft* enemy, mActiveEnemies)
		{
			float enemyDistance = distance(missile, *enemy);

			if (enemyDistance < minDistance)
			{
				closestEnemy = enemy;
				minDistance = enemyDistance;
			}
		}

		if (closestEnemy)
			missile.guideTowards(closestEnemy->getWorldPosition());
	});

	// Push commands, reset active enemies
	mCommandQueue.push(enemyCollector);
	mCommandQueue.push(missileGuider);
	mActiveEnemies.clear();
}

sf::FloatRect World::getViewBounds() const
{
	return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
}

sf::FloatRect World::getBattlefieldBounds() const
{
	// Return view bounds + some area at top, where enemies spawn
	sf::FloatRect bounds = getViewBounds();
	bounds.top -= 100.f;
	bounds.height += 100.f;

	return bounds;
}

void World::handleCollisions()
{
	std::set<SceneNode::Pair> collisionPairs;
	mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);

	FOREACH(SceneNode::Pair pair, collisionPairs)		//飞机碰撞
	{
		if (matchesCategories(pair, Category::PlayerAircraft, Category::EnemyAircraft))
		{
			auto& player = static_cast<Aircraft&>(*pair.first);
			auto& enemy = static_cast<Aircraft&>(*pair.second);

			// Collision: Player damage = enemy's remaining HP
			player.damage(enemy.getHitpoints()*3);
			enemy.destroy();

			updateScore(enemy);

			if (player.getHitpoints() <= 0)
			{
				addFlash(Textures::Explosion,player.getPosition().x, player.getPosition().y);
			}
			
		}

		else if (matchesCategories(pair, Category::EnemyAircraft, Category::AlliedProjectile)
			|| matchesCategories(pair, Category::PlayerAircraft, Category::EnemyProjectile))
		{
			auto& aircraft = static_cast<Aircraft&>(*pair.first);
			auto& projectile = static_cast<Projectile&>(*pair.second);

			// Apply projectile damage to aircraft, destroy projectile
			aircraft.damage(projectile.getDamage());
			projectile.destroy();
			mSounds.play(SoundEffect::Explosion1);
			
			if (projectile.isGuided())
			{
				addFlash(Textures::Explosion,aircraft.getPosition().x, aircraft.getPosition().y);
			}

			updateScore(aircraft);
		}
	}
}



void World::randomEvents(sf::Time dt)
{
	randomEnemys(dt);
}

void World::randomEnemys(sf::Time dt)
{
	static int randomLevel = 1;

	if (mPlayerAircraft->getPosition().y < 18000 && randomLevel == 1)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}
	else if (mPlayerAircraft->getPosition().y < 16000 && randomLevel == 2)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}
	else if (mPlayerAircraft->getPosition().y < 14000 && randomLevel == 3)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}
	else if (mPlayerAircraft->getPosition().y < 12000 && randomLevel == 4)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}
	else if (mPlayerAircraft->getPosition().y < 10000 && randomLevel == 5)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}
	else if (mPlayerAircraft->getPosition().y < 12000 && randomLevel == 6)
	{
		mRandomEvents.RandomEnemyInterval -= sf::seconds(0.3);
		randomLevel++;
	}


	mRandomEvents.RandomEventsCountdown += dt;

	if (mRandomEvents.RandomEventsCountdown > mRandomEvents.RandomEnemyInterval)
	{
//		addTroopC();
		int Rand = rand();

		if (Rand % 6 == 0)
		{
			int Rand = rand();
			if (Rand % 3 == 0)
			{
				if (rand() % 2 == 0)
				{
					addTroopA2();
				}
				else
				{
					addTroopA1();
				}
			}
			else
			{
				if (rand() % 2 == 0)
				{
					addTroopB1();
				}
				else
				{
					addTroopB2();
				}
			}
		}
		else if(Rand%6>2)
		{
			addEnemy(Aircraft::Raptor, rand() % 600 - 300, mViewCenter.y + 500);
		}
		else
		{
			addEnemy(Aircraft::Avenger, rand() % 600 - 300, mViewCenter.y + 500);
		}

		if (mPlayerAircraft->getPosition().y<10000)	//随机Troop
		{


			int Rand = rand();
			if (Rand % 9 == 0)
			{
				if (rand() % 2 == 0)addTroopE1();
				else addTroopE2();

			}
			else if (Rand % 9 > 6)
			{
				if (rand() % 2 == 0)addTroopA1();
				else addTroopA2();
			}
			else if (Rand % 9 > 4)
			{
				if (rand() % 2 == 0)addTroopB1();
				else addTroopB2();
			}
			else if (Rand % 9 > 2)
			{
				if (rand() % 2 == 0)addTroopC1();
				else addTroopC2();
			}
			else if (Rand % 9 > 0)
			{
				addTroopD1();
			}
		}

		mRandomEvents.RandomEventsCountdown -= mRandomEvents.RandomEnemyInterval;

		std::sort(mEnemySpawnPoints.begin(), mEnemySpawnPoints.end(), [](SpawnPoint lhs, SpawnPoint rhs)	//加入随机敌机后，给飞机队列排序，满足World::spawnEnemies 需求
		{
			return lhs.y < rhs.y;
		});
	}


}

void World::randomTroop(sf::Time dt)
{

}



void World::addAlly()
{
		
}

void World :: addFlash(Textures::ID type,float x,float y)
{
	sf::Texture& texture = mTextures.get(type);
	std::unique_ptr<Flash> mflash(new Flash(texture,type));

	mflash->setPosition(x,y);
	mFlashNode.attachChild(std::move(mflash));

}

sf::Vector2f World::getViewCenter()
{
	return  mSpawnPosition- mViewCenter;
}
