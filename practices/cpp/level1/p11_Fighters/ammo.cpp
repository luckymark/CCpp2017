#include"Game.h"

Ammo::Ammo()
{
	type = C;
	M_Texture.loadFromFile("Images/Shape_81.png");
	L_Texture.loadFromFile("Images/Shape_109.png");
	C1_Texture.loadFromFile("Images/Shape_117.png");
	C2_Texture.loadFromFile("Images/Shape_119.png");
	C3_Texture.loadFromFile("Images/Shape_121.png");
	M_.setTexture(M_Texture);
	L_.setTexture(L_Texture);
	C1_.setTexture(C1_Texture);
	C2_.setTexture(C2_Texture);
	C3_.setTexture(C3_Texture);
	C1_.setScale(1.5, 1.5);
	C1_.setOrigin(C1_Texture.getSize().x / 2, C1_Texture.getSize().y / 2);
	C2_.setScale(1.5, 1.5);
	C2_.setOrigin(C2_Texture.getSize().x / 2, C2_Texture.getSize().y / 2);
	C3_.setScale(1.5, 1.5);
	C3_.setOrigin(C3_Texture.getSize().x / 2, C3_Texture.getSize().y / 2);
	clock.restart();
	time = clock.getElapsedTime();
	for (int i = 0; i < 6; i++)place[i].y = -50;
}

Ammo::~Ammo(){}

void Ammo::SetAmmo(ammotype m_type)
{
	type = m_type;
	if (type == L)pt = &L_;
	else if (type == M)pt = &M_;
}

void Ammo::Dynamic()
{
	time = clock.getElapsedTime();
	if (time.asMilliseconds() < 200 && common != &C1_) {
		common = &C1_;
	}
	else if (time.asMilliseconds() < 400 && common != &C2_) {
		common = &C2_;
	}
	else if (time.asMilliseconds() < 600 && common != &C3_) {
		common = &C3_;
	}
	else {
		clock.restart();
		time = clock.getElapsedTime();
	}
}
