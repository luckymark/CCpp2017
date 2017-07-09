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
	void					loadTexture(sf::Texture texture);
	void					remove();
private:
	void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;		//!!!!!!!!!�ڵ��� mWindow.draw(SceneNode) ʱ���˺���ʵ�ֻ�ͼ!!!!!!!!!
	sf::Sprite	mSprite;
	Textures::ID mType;
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
	int xframes, yframes;

};

#endif // !FLASH_H_

