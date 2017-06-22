#include"Game.h"
#include<cstdlib>
#include<ctime>
Rain::Rain() 
{
	char str[30];
	for (int i = 0; i < 4; i++) {
		sprintf(str, "Images/Shape_%d.png", 128 + i);
		rainT[i].loadFromFile(str);
		rainS[i].setTexture(rainT[i]);
		rainS[i].setScale(1.5, 1.5);
		rainS[i].setOrigin(rainT[i].getSize().x/2, rainT[i].getSize().y-10);
		rainS[i].setColor(sf::Color(255, 255, 255, 150));
	}
	srand((unsigned)std::time(NULL));
	randnew = rand() % 600 + 10;
	ct = 0;
	for (int i = 0; i < 15; i++)sign[i].y = 500;
	time = clock.restart();
	for (int i = 0; i < 15; i++)control[i] = true;
	m_statu = true;
}
void Rain::newrain()
{
	m_time = m_clock.getElapsedTime();
	if (m_time.asMilliseconds() > 500) {
		sign[ct].x = randnew;
		sign[ct++].y = -15;
		if (ct == 15)ct = 0;
		randnew = rand() % 600 + 10;
		m_time = m_clock.restart();
	}
}

void Rain::setnew(bool status) { m_statu = status; }

void Rain::move()
{
	time = clock.getElapsedTime();
	for (int i = 0; i < 15; i++) {
		if (sign[i].y < 560) {
			sign[i].y += (sign[i].y + 20)*(sign[i].y+20) / 14400 + 1;
			if (time.asMilliseconds() > 100) {
				if (control[i] == true) {
					sign[i].x -= 3;
				}
				else sign[i].x += 3;
				control[i] ^= 1;
			}
		}
	}
	if (time.asMilliseconds() > 100) {
		time = clock.restart();
	}
}

Rain::~Rain(){}


sf::Vector2f &Rain::getPos(int i) { return sign[i]; }

void Rain::setPos(const sf::Vector2f &l_pos)
{
	for (int i = 0; i < 4; i++) {
		rainS[i].setPosition(l_pos);
	}
}

void Rain::update()
{
	if (m_statu == true)newrain();
	move();
}

