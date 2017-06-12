#pragma once
#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "YOUneedTHIS.h"
class Animation :public sf::Drawable, public sf::Transformable
{
public:
	explicit Animation(const sf::Texture& texture);
	Animation();
	void setTexture(const sf::Texture& texture);
	const sf::Texture* getTexture() const;
	void setFrameSize(sf::Vector2i frameSize);
	sf::Vector2i getFrameSize() const;
	void setNumFrames(std::size_t numFrames);
	std::size_t getNumFrames() const;
	void setDuration(sf::Time duration);
	sf::Time getDuration() const;
	void setRepeating(bool flag);
	bool isRepeating() const;
	void restart();
	bool isFinished() const;
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;
	void update(sf::Time dt);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Sprite mSprite;
	sf::Vector2i mFrameSize;
	std::size_t mNumFrames;
	std::size_t mCurrentFrame;
	sf::Time mDuration;
	sf::Time mElapsedTime;
	bool mRepeat;
};
#endif // !ANIMATION_H_
