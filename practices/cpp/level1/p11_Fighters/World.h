#ifndef WORLD_H_
#define WORLD_H_

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Aircraft.h"
#include "CommandQueue.h"
#include "Command.h"
#include "YOUneedTHIS.h"
#include "TextNode.h"
#include "PostEffect.h"
#include "BloomEffect.h"

namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderTarget& outputTarget, FontHolder& fonts, SoundPlayer& sounds);
	void update(sf::Time dt);
	void draw();

	CommandQueue& getCommandQueue();

	bool hasAlivePlayer() const;
	bool hasPlayerReachedEnd() const;


private:
	void loadTextures();
	void adaptPlayerPosition();
	void adaptPlayerVelocity();
	void handleCollisions();

	void buildScene();
	void addEnemies();
	void addEnemy(Aircraft::Type type, float relX, float relY);
	void spawnEnemies();
	void destroyEntitiesOutsideView();
	void guideMissiles();
	sf::FloatRect getViewBounds() const;
	sf::FloatRect getBattlefieldBounds() const;
	void updateSounds();


private:
	enum Layer
	{
		Background,
		LowerAir,
		UpperAir,
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


private:
	sf::RenderTarget& mTarget;
	sf::View mWorldView;
	TextureHolder mTextures;
	FontHolder&	 mFonts;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	CommandQueue mCommandQueue;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
	SoundPlayer& mSounds;
	std::vector<SpawnPoint> mEnemySpawnPoints;
	std::vector<Aircraft*> mActiveEnemies;
	sf::RenderTexture mSceneTexture;
	BloomEffect mBloomEffect;

};

#endif // WORLD_H_
