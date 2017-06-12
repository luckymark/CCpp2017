#include "SoundNode.h"

SoundNode::SoundNode(SoundPlayer & player)
	:SceneNode()
	,mSounds(player)
{
}

void SoundNode::playSound(SoundEffect::ID sound, sf::Vector2f position)
{
	mSounds.play(sound, position);
}

