#pragma once
#ifndef SOUNDNODE_H_
#define SOUNDNODE_H_
#include "SceneNode.h"
#include "SounderPlayer.h"
class SoundNode :public SceneNode
{
public:
	explicit SoundNode(SoundPlayer& player);
	void playSound(SoundEffect::ID sound, sf::Vector2f position);
	virtual unsigned int getCategory() const
	{
		return Category::SoundEffect;;
	}
private:
	SoundPlayer& mSounds;
};
#endif // !SOUNDNODE_H_
