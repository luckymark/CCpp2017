#ifndef UTILITY_H_
#define UTILITY_H_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sstream>

namespace sf
{
	class Sprite;
	class Text;
}

class Animation;

template <typename T>
std::string		toString(const T& value);

std::string		toString(sf::Keyboard::Key key);

void			centerOrigin(sf::Sprite& sprite);
void			centerOrigin(sf::Text& text);
void			centerOrigin(Animation& animation);

float			toDegree(float radian);
float			toRadian(float degree);

int				randomInt(int exclusiveMax);

float			length(sf::Vector2f vector);
sf::Vector2f	unitVector(sf::Vector2f vector);

#include "Utility.inl"
#endif // UTILITY_H_
