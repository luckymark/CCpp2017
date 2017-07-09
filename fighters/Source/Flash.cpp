#include "Include\Flash.h"
#include "Include\ResourceIdentifiers.hpp"


Flash::Flash(const sf::Texture & texture, Textures::ID type)
	: mSprite(texture)
	, mIsMarkedForRemoval(false)
	, curTime(sf::seconds(0))
	, clock()
	, curFrame(1)
	, frameShifter(sf::seconds(0))
	, mType(type)
{

	switch (type)
	{
	case Textures::Explosion:
		xframes = 4;
		yframes = 4;
		timePerFrame = sf::seconds(1.f / 20.f);
		mSprite.setPosition(-100, -100);	//矫正flash位置
		break;
	case Textures::Spark:
		xframes = 4;
		yframes = 4;
		timePerFrame = sf::seconds(1.f / 40.f);
		mSprite.setPosition(-25, -45);
		break;
	case Textures::Loop:
		xframes = 5;
		yframes = 5;
		timePerFrame = sf::seconds(1.5f / 25.f);
		mSprite.setPosition(-20, -10);
		break;
	case Textures::Explosion_missile:
		xframes = 4;
		yframes = 4;
		timePerFrame = sf::seconds(1.f / 35.f);
		mSprite.setPosition(-45, -45);
		break;
	case Textures::RebornCircle:
		xframes = 7;
		yframes = 7;
		timePerFrame = sf::seconds(1.f / 7.f);
		mSprite.setPosition(0, 0);
		break;

	}


	frameSize.x = texture.getSize().x / xframes;
	frameSize.y = texture.getSize().y / yframes;

	frameRect.top = 0;
	frameRect.left = 0;
	frameRect.width = frameSize.x;
	frameRect.height = frameSize.y;


	flashTime = sf::seconds(xframes*yframes*timePerFrame.asSeconds());


	mSprite.setTextureRect(frameRect);

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
	if (mType == Textures::RebornCircle)
	{
		if (mIsMarkedForRemoval)
		{
			int i = mIsMarkedForRemoval;
			 i = mIsMarkedForRemoval;
		}
	}
	return mIsMarkedForRemoval;
}

void Flash::loadTexture(sf::Texture texture)
{
	mSprite.setTexture(texture);
}

void Flash::remove()
{
	mIsMarkedForRemoval = true;
}


void Flash::updateFlash(sf::Time dt)
{
	
	curTime += dt;
	frameShifter += dt;



	if (frameShifter > timePerFrame)
	{
		curFrame++;
		frameShifter -= timePerFrame;

		if (curFrame % xframes== 1)		//到下一行
		{
			float t = xframes;
			frameRect.left = 0;
			frameRect.top += frameRect.height;
		}
		else
		{
			frameRect.left += frameSize.x;
		}
	}

	mSprite.setTextureRect(frameRect);
	

	if (curTime > flashTime)
	{
		mIsMarkedForRemoval = true;
	}
	
}