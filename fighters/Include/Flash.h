#ifndef FLASH_H_
#define FLASH_H_

#include"SceneNode.hpp"
#include"ResourceIdentifiers.hpp"

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Flash :public SceneNode
{
public:
	Flash(const sf::Texture & texture, Textures::ID type);
	void					updateFlash(sf::Time dt);
	virtual bool 			isMarkedForRemoval() const;
private:
	void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;		//!!!!!!!!!在调用 mWindow.draw(SceneNode) 时，此函数实现绘图!!!!!!!!!
	sf::Sprite	mSprite;

	sf::Time	flashTime;
	sf::Time	curTime;
	sf::Clock	clock;
	sf::Vector2f frameSize;
	sf::Time	timePerFrame;
	sf::Time	frameShifter;
	bool		mIsMarkedForRemoval;
	int			curFrame;
	int			framePerline;
	sf::IntRect frameRect;

};

#endif // !FLASH_H_

