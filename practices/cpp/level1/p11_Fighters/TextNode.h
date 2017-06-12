#pragma once
#ifndef TEXTNODE_H_
#define TEXTNODE_H_
#include"YOUneedTHIS.h"
#include"SceneNode.h"
#include"Utility.h"
class TextNode :public SceneNode
{
public:
	explicit TextNode(const FontHolder& fonts, const std::string& text);
	void setString(const std::string& text);
private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text mText;
};
#endif // !TEXTNODE_H_
