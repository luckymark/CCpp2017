#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <SFML\System\Vector2.hpp>

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


template <typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}
