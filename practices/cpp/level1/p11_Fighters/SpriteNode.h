#pragma once
#ifndef SPRITENODE_H_
#define SPRITENODE_H_
#include"YOUneedTHIS.h"
#include"SceneNode.h"
class SpriteNode :public SceneNode
{
private:
	sf::Sprite mSprite;
private:
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);
	explicit SpriteNode(const sf::Texture& texture);
};
#endif // !SPRITENODE_H_
