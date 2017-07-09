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
	void					updateMenu(sf::Vector2f position,int HP,int points,int missiles, int fireRateCost, int fireSpreadCost,int mMissileSlotCost);
	void					showMenu()const;
	void					openMenu(Menus menu);
	void					closeMenus();
	bool					isEOpened();
	bool					isQOpened();
	void					initializeTexts();
	void					updateTexts(sf::Vector2f position, int HP, int points, int missiles, int fireRateCost, int fireSpreadCost, int mMissileSlotCost);
	void					updateTextsColor(int HP, int points, int missiles, int fireRateCost, int fireSpreadCost, int mMissileSlotCost);
	void					updateRings(sf::Vector2f position, int fireRateCost, int fireSpreadCost, int SlotCost);

private:
	sf::Font				mFont;
	sf::Text				mStatusText;
	sf::Text				mHPText;
	sf::Text				mMissileCost;
	sf::Text				mHPCost;
	sf::Text				mPoints;
	sf::Text				mFireRateCost;
	sf::Text				mFireSpreadCost;
	sf::Text				mMissileSlotCost;
	sf::RenderWindow&       mWindow;

	sf::Sprite				EMenuSprite;
	sf::Sprite				QMenuSprite;
	sf::Sprite				RingA;
	sf::Sprite				RingB;
	sf::Sprite				RingC;
	sf::Sprite				Missiles;
	sf::Sprite				Slot;
	sf::Texture				EMenuTexture;
	sf::Texture				QMenuTexture;
	sf::Texture				RingATexture;
	sf::Texture				RingBTexture;
	sf::Texture				RingCTexture;
	sf::Texture				SlotTexture;
	sf::Texture				MissileTexture;
	sf::Vector2f			missileSize;
	sf::Vector2f			slotSize;
	sf::IntRect				missileFrame;
	sf::IntRect				slotFrame;

	bool					isQMEnuOpened;
	bool					isEMenuOpened;
	bool					isRingAChanged;
	bool					isRingBChanged;
	int		Speedcount;
	int		Pilecount;
	int		Slotcount;
};


#endif // !PLAYERSTATUSMENU_H_

#pragma once
