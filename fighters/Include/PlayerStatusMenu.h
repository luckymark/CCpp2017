#ifndef PLAYERSTATUSMENU_H_
#define PLAYERSTATUSMENU_H_


#include<SFML/Graphics.hpp>

class Aircraft;

class PlayerStatusMenu
{
public:
	enum Menus
	{
		QMenu,
		EMenu
	};

	PlayerStatusMenu(sf::RenderWindow& window);
	void					updateMenu(sf::Vector2f position,int HP,int points,int missiles, int fireRateCost, int fireSpreadCost);
	void					showMenu()const;
	void					openMenu(Menus menu);
	void					closeMenus();
	bool					isEOpened();
	bool					isQOpened();
	void					initializeTexts();
	void					updateTexts(sf::Vector2f position, int HP, int points, int missiles, int fireRateCost, int fireSpreadCost);
	void					updateTextsColor(int HP, int points, int missiles, int fireRateCost, int fireSpreadCost);
	void					updateRings(sf::Vector2f position, int fireRateCost, int fireSpreadCost);

private:
	sf::Font				mFont;
	sf::Text				mStatusText;
	sf::Text				mHPText;
	sf::Text				mMissileCost;
	sf::Text				mHPCost;
	sf::Text				mPoints;
	sf::Text				mFireRateCost;
	sf::Text				mFireSpreadCost;
	sf::RenderWindow&       mWindow;

	sf::Sprite				EMenuSprite;
	sf::Sprite				QMenuSprite;
	sf::Sprite				RingA;
	sf::Sprite				RingB;
	sf::Sprite				Missiles;
	sf::Texture				EMenuTexture;
	sf::Texture				QMenuTexture;
	sf::Texture				RingATexture;
	sf::Texture				RingBTexture;
	sf::Texture				MissileTexture;
	sf::Vector2f			missileSize;
	sf::IntRect				missileFrame;

	bool					isQMEnuOpened;
	bool					isEMenuOpened;
	bool					isRingAChanged;
	bool					isRingBChanged;
};


#endif // !PLAYERSTATUSMENU_H_

#pragma once
