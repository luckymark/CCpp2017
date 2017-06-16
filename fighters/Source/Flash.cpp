#include "Include\Flash.h"
#include "Include\ResourceIdentifiers.hpp"


Flash::Flash(const sf::Texture & texture, Textures::ID type)
	: mSprite(texture)
	, mIsMarkedForRemoval(false)
	, curTime(sf::seconds(0))
	, clock()
	, timePerFrame(sf::seconds(1.f / 20.f))
	, curFrame(1)
	, frameShifter(sf::seconds(0))
{
	if (Textures::Explosion == type)
	{
		frameSize.x = texture.getSize().x / 4;
		frameSize.y = texture.getSize().y / 4;

		frameRect.top = 0;
		frameRect.left = 0;
		frameRect.width = frameSize.x;
		frameRect.height = frameSize.y;

		flashTime = sf::seconds(1);
	}


}

void Flash::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!mIsMarkedForRemoval)
	{
		target.draw(mSprite, states);
	}
}

bool Flash::isMarkedForRemoval() const
{
	return mIsMarkedForRemoval;
}


void Flash::updateFlash(sf::Time dt)
{
	
	curTime += dt;
	frameShifter += dt;

	if (frameShifter > timePerFrame)
	{
		curFrame++;
		frameShifter -= timePerFrame;

		if (curFrame / 4 == 1)		//到下一行
		{
			frameRect.left = 0;
			frameRect.top += frameRect.height;
		}
		else
		{
			frameRect.left += frameSize.x;
		}
	}

	mSprite.setTextureRect(frameRect);
	mSprite.setPosition(-100, -100);

	if (curTime > flashTime)
	{
		mIsMarkedForRemoval = true;
	}
	
}