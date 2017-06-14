#include "Utility.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>
#include <ctime>
#include <cassert>

namespace
{
	std::default_random_engine createRandomEngine()
	{
		auto seed = static_cast<unsigned long>(std::time(nullptr));
		return std::default_random_engine(seed);
	}
	auto RandomEngine = createRandomEngine();
}

std::string toString(sf::Keyboard::Key key)
{
	#define KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;
	switch (key)
	{
		KEYTOSTRING_CASE(Unknown)
		KEYTOSTRING_CASE(A)
		KEYTOSTRING_CASE(B)
		KEYTOSTRING_CASE(C)
		KEYTOSTRING_CASE(D)
		KEYTOSTRING_CASE(E)
		KEYTOSTRING_CASE(F)
		KEYTOSTRING_CASE(G)
		KEYTOSTRING_CASE(H)
		KEYTOSTRING_CASE(I)
		KEYTOSTRING_CASE(J)
		KEYTOSTRING_CASE(K)
		KEYTOSTRING_CASE(L)
		KEYTOSTRING_CASE(M)
		KEYTOSTRING_CASE(N)
		KEYTOSTRING_CASE(O)
		KEYTOSTRING_CASE(P)
		KEYTOSTRING_CASE(Q)
		KEYTOSTRING_CASE(R)
		KEYTOSTRING_CASE(S)
		KEYTOSTRING_CASE(T)
		KEYTOSTRING_CASE(U)
		KEYTOSTRING_CASE(V)
		KEYTOSTRING_CASE(W)
		KEYTOSTRING_CASE(X)
		KEYTOSTRING_CASE(Y)
		KEYTOSTRING_CASE(Z)
		KEYTOSTRING_CASE(Num0)
		KEYTOSTRING_CASE(Num1)
		KEYTOSTRING_CASE(Num2)
		KEYTOSTRING_CASE(Num3)
		KEYTOSTRING_CASE(Num4)
		KEYTOSTRING_CASE(Num5)
		KEYTOSTRING_CASE(Num6)
		KEYTOSTRING_CASE(Num7)
		KEYTOSTRING_CASE(Num8)
		KEYTOSTRING_CASE(Num9)
		KEYTOSTRING_CASE(Escape)
		KEYTOSTRING_CASE(LControl)
		KEYTOSTRING_CASE(LShift)
		KEYTOSTRING_CASE(LAlt)
		KEYTOSTRING_CASE(LSystem)
		KEYTOSTRING_CASE(RControl)
		KEYTOSTRING_CASE(RShift)
		KEYTOSTRING_CASE(RAlt)
		KEYTOSTRING_CASE(RSystem)
		KEYTOSTRING_CASE(Menu)
		KEYTOSTRING_CASE(LBracket)
		KEYTOSTRING_CASE(RBracket)
		KEYTOSTRING_CASE(SemiColon)
		KEYTOSTRING_CASE(Comma)
		KEYTOSTRING_CASE(Period)
		KEYTOSTRING_CASE(Quote)
		KEYTOSTRING_CASE(Slash)
		KEYTOSTRING_CASE(BackSlash)
		KEYTOSTRING_CASE(Tilde)
		KEYTOSTRING_CASE(Equal)
		KEYTOSTRING_CASE(Dash)
		KEYTOSTRING_CASE(Space)
		KEYTOSTRING_CASE(Return)
		KEYTOSTRING_CASE(BackSpace)
		KEYTOSTRING_CASE(Tab)
		KEYTOSTRING_CASE(PageUp)
		KEYTOSTRING_CASE(PageDown)
		KEYTOSTRING_CASE(End)
		KEYTOSTRING_CASE(Home)
		KEYTOSTRING_CASE(Insert)
		KEYTOSTRING_CASE(Delete)
		KEYTOSTRING_CASE(Add)
		KEYTOSTRING_CASE(Subtract)
		KEYTOSTRING_CASE(Multiply)
		KEYTOSTRING_CASE(Divide)
		KEYTOSTRING_CASE(Left)
		KEYTOSTRING_CASE(Right)
		KEYTOSTRING_CASE(Up)
		KEYTOSTRING_CASE(Down)
		KEYTOSTRING_CASE(Numpad0)
		KEYTOSTRING_CASE(Numpad1)
		KEYTOSTRING_CASE(Numpad2)
		KEYTOSTRING_CASE(Numpad3)
		KEYTOSTRING_CASE(Numpad4)
		KEYTOSTRING_CASE(Numpad5)
		KEYTOSTRING_CASE(Numpad6)
		KEYTOSTRING_CASE(Numpad7)
		KEYTOSTRING_CASE(Numpad8)
		KEYTOSTRING_CASE(Numpad9)
		KEYTOSTRING_CASE(F1)
		KEYTOSTRING_CASE(F2)
		KEYTOSTRING_CASE(F3)
		KEYTOSTRING_CASE(F4)
		KEYTOSTRING_CASE(F5)
		KEYTOSTRING_CASE(F6)
		KEYTOSTRING_CASE(F7)
		KEYTOSTRING_CASE(F8)
		KEYTOSTRING_CASE(F9)
		KEYTOSTRING_CASE(F10)
		KEYTOSTRING_CASE(F11)
		KEYTOSTRING_CASE(F12)
		KEYTOSTRING_CASE(F13)
		KEYTOSTRING_CASE(F14)
		KEYTOSTRING_CASE(F15)
		KEYTOSTRING_CASE(Pause)
	}
	return "";
}

void centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

void centerOrigin(Animation& animation)
{
	sf::FloatRect bounds = animation.getLocalBounds();
	animation.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

float toDegree(float radian)
{
	return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}

int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
	return distr(RandomEngine);
}

float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
	assert(vector != sf::Vector2f(0.f, 0.f));
	return vector / length(vector);
}
