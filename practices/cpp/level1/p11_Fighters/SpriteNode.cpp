#include "SpriteNode.h"

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& rect):mSprite(texture,rect)
{
}

SpriteNode::SpriteNode(const sf::Texture& texture):mSprite(texture)
{
}
