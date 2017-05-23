#pragma once
#ifndef WORLD_H_
#define WORLD_H_
#include"YOUneedTHIS.h"
#include"Aircraft.h"
#include"ResourseHolder.h"
#include"SpriteNode.h"
namespace sf
{
	class RenderWindow;
}

class World
{
public:
	explicit							World(sf::RenderWindow& window);
	void								update(sf::Time dt);
	void								draw();


private:
	void								loadTextures();
	void								buildScene();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow& mWindow;///
	sf::View mWorldView;///
	TextureHolder mTextures;///

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
};
#endif // !WORLD_H_
