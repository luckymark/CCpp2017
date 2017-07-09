#include"Include\PlayerStatusMenu.h"
#include"Include\stringhelpers.hpp"
#include"Include\Aircraft.hpp"

PlayerStatusMenu::PlayerStatusMenu(sf::RenderWindow& window)
	:mWindow(window)
	,isQMEnuOpened(false)
	, isEMenuOpened(false)
	, isRingAChanged(false)
	, isRingBChanged(false)
	, Speedcount(1)
	, Pilecount(1)
	, Slotcount(1)
{
	initializeTexts();
}

void PlayerStatusMenu::updateMenu(sf::Vector2f position, int HP, int points, int missiles, int fireRateCost, int fireSpreadCost,int mMissileSlotCost)
{
	updateTexts(position, HP, points,missiles,fireRateCost,fireSpreadCost, mMissileSlotCost);
	updateTextsColor(HP, points, missiles, fireRateCost, fireSpreadCost, mMissileSlotCost);
	updateRings(position,fireRateCost, fireSpreadCost, mMissileSlotCost);

	EMenuSprite.setPosition(position.x + 15, position.y - 100);
	QMenuSprite.setPosition(position.x - 200, position.y - 100);
}

void PlayerStatusMenu::showMenu()const
{
	if (isEMenuOpened)
	{
		mWindow.draw(mHPCost);
		mWindow.draw(mMissileCost);
		mWindow.draw(Slot);


		mWindow.draw(EMenuSprite);
		mWindow.draw(mStatusText);
		mWindow.draw(Missiles);
		mWindow.draw(Slot);
		mWindow.draw(mHPText);
		mWindow.draw(mPoints);




	}
	else if (isQMEnuOpened)
	{
		mWindow.draw(mFireRateCost);
		mWindow.draw(mFireSpreadCost);
		mWindow.draw(mMissileSlotCost);
		mWindow.draw(Slot);

		mWindow.draw(QMenuSprite);
		mWindow.draw(mStatusText);
		mWindow.draw(Missiles);
		mWindow.draw(mHPText);
		mWindow.draw(mPoints);
		mWindow.draw(RingA);
		mWindow.draw(RingB);
		mWindow.draw(RingC);
	}



}

void PlayerStatusMenu::openMenu(Menus menu)
{
	if (Menus::EMenu == menu)
	{
		isEMenuOpened = true;
	}
	else if (Menus::QMenu == menu)
	{
		isQMEnuOpened = true;
	}
}

void PlayerStatusMenu::closeMenus()
{
	isEMenuOpened = false;
	isQMEnuOpened = false;
}

bool PlayerStatusMenu::isEOpened()
{
	return isEMenuOpened;
}

bool PlayerStatusMenu::isQOpened()
{
	return isQMEnuOpened;
}

void PlayerStatusMenu::initializeTexts()
{

	mFont.loadFromFile("Media/Sansation.ttf");
	mStatusText.setFont(mFont);
	mStatusText.setCharacterSize(15);

	mHPText.setFont(mFont);
	mHPText.setCharacterSize(15);

	mPoints.setFont(mFont);
	mPoints.setCharacterSize(15);

	MissileTexture.loadFromFile("Media/Textures/Missiles4.png");
	Missiles.setTexture(MissileTexture);
	missileSize.x= MissileTexture.getSize().x / 4;
	missileSize.y= missileFrame.height = MissileTexture.getSize().y;
	missileFrame.left = 0;
	missileFrame.top = 0;
	missileFrame.height= MissileTexture.getSize().y;
	missileFrame.width= MissileTexture.getSize().x / 4;

	SlotTexture.loadFromFile("Media/Textures/Slot4.png");
	Slot.setTexture(SlotTexture);
	slotSize.x = SlotTexture.getSize().x / 4;
	slotSize.y = missileFrame.height = SlotTexture.getSize().y;
	slotFrame.left = 0;
	slotFrame.top = 0;
	slotFrame.height = SlotTexture.getSize().y;
	slotFrame.width = SlotTexture.getSize().x / 4;


	EMenuTexture.loadFromFile("Media/Textures/EMenu.png");
	EMenuSprite.setTexture(EMenuTexture);

	QMenuTexture.loadFromFile("Media/Textures/QMenu.png");
	QMenuSprite.setTexture(QMenuTexture);

	mHPCost.setString("(5 Points)");
	mHPCost.setFont(mFont);
	mHPCost.setCharacterSize(12);

	mMissileCost.setString("(2 Points)");
	mMissileCost.setFont(mFont);
	mMissileCost.setCharacterSize(12);

	mFireRateCost.setFont(mFont);
	mFireRateCost.setCharacterSize(12);

	mFireSpreadCost.setFont(mFont);
	mFireSpreadCost.setCharacterSize(12);

	mMissileSlotCost.setFont(mFont);
	mMissileSlotCost.setCharacterSize(12);

	RingATexture.loadFromFile("Media/Textures/RingA1.png");
	RingA.setTexture(RingATexture);

	RingBTexture.loadFromFile("Media/Textures/RingB1.png");
	RingB.setTexture(RingBTexture);

	RingCTexture.loadFromFile("Media/Textures/RingC1.png");
	RingC.setTexture(RingCTexture);




}

void PlayerStatusMenu::updateTexts(sf::Vector2f position, int HP, int points, int missiles, int fireRateCost, int fireSpreadCost, int MissileSlotCost)
{
	mStatusText.setPosition(position.x - 65, position.y + 60);
	mStatusText.setString("HP:           " + toString("   Points:") + "\n\n" + "      Missiles:");

	mPoints.setString(toString(points));
	mPoints.setPosition(position.x + 65, position.y + 60);


	mHPText.setPosition(position.x - 30, position.y + 60);
	mHPText.setString(toString(HP));

	

	mHPCost.setPosition(position.x + 13, position.y - 55);
	mMissileCost.setPosition(position.x + 150, position.y - 55);

	mMissileSlotCost.setString("(" + toString(MissileSlotCost) + "Points)");
	mMissileSlotCost.setPosition(position.x - 135, position.y + 15);


	mFireRateCost.setString("(" + toString(fireRateCost) + " Points" + ")");
	mFireRateCost.setPosition(position.x - 70, position.y - 55);

	mFireSpreadCost.setString("(" + toString(fireSpreadCost) + " Points" + ")");
	mFireSpreadCost.setPosition(position.x - 210, position.y - 55);


	switch (missiles)		//更新导弹数量
	{
	case 0:
		missileFrame.width = 0;
		break;
	case 1:
		missileFrame.width = missileSize.x;
		break;
	case 2:
		missileFrame.width = missileSize.x*2;
		break;
	case 3:
		missileFrame.width = missileSize.x * 3;
		slotFrame.width = slotSize.x * 3;
		break;
	case 4:
		missileFrame.width = missileSize.x * 4;
		slotFrame.width = slotSize.x * 4;
		break;
	}

	switch (Slotcount)		//导弹槽
	{
	case 1:
		slotFrame.width = missileSize.x * 2;
		break;
	case 2:
		slotFrame.width = slotSize.x * 3;
		break;
	case 3:
		slotFrame.width = slotSize.x * 4;
		break;
	}

	Missiles.setTextureRect(missileFrame);
	Missiles.setPosition(position.x + 20, position.y + 83);

	Slot.setTextureRect(slotFrame);
	Slot.setPosition(position.x + 20, position.y + 83);

}

void PlayerStatusMenu::updateTextsColor(int HP, int points, int missiles, int fireRateCost, int fireSpreadCost,int missileSlotCost)
{
	sf::Color color;
	mPoints.setFillColor(color.Green);
	if (HP <= 30)
	{
		mHPText.setFillColor(color.Red);
	}
	else if (HP <= 60)
	{
		mHPText.setFillColor(color.Yellow);
	}
	else
	{
		mHPText.setFillColor(color.Green);
	}


	if (points < 5)
	{
		mHPCost.setFillColor(color.Red);
	}
	else
	{
		mHPCost.setFillColor(color.Blue);
	}


	if (points < 2)
	{
		mMissileCost.setFillColor(color.Red);
	}
	else
	{
		mMissileCost.setFillColor(color.Blue);
	}

	if (points < fireRateCost)
	{
		mFireRateCost.setFillColor(color.Red);
	}
	else
	{
		mFireRateCost.setFillColor(color.Cyan);
	}

	if (points < fireSpreadCost)
	{
		mFireSpreadCost.setFillColor(color.Red);
	}
	else
	{
		mFireSpreadCost.setFillColor(color.Cyan);
	}
	if (points < missileSlotCost)
	{
		mMissileSlotCost.setFillColor(color.Red);
	}
	else
	{
		mMissileSlotCost.setFillColor(color.Cyan);
	}
}

void PlayerStatusMenu::updateRings(sf::Vector2f position, int fireRateCost, int fireSpreadCost,int SlotCost)
{
	static int preFireSpread;
	if (fireSpreadCost != 20)	//20是初始cost
	{
		if (fireSpreadCost != preFireSpread)
		{
			Speedcount++;
			RingATexture.loadFromFile("Media/Textures/RingA" + toString(Speedcount) + ".png");
			RingA.setTexture(RingATexture);
			
		}
	}
	RingA.setPosition(position.x - 215, position.y - 45);
	preFireSpread = fireSpreadCost;

	static int preFireRate;
	if (fireRateCost != 10)		//10是初始cost
	{
		if (fireRateCost != preFireRate)
		{
			Pilecount ++;
			RingBTexture.loadFromFile("Media/Textures/RingB" + toString(Pilecount) + ".png");
			RingB.setTexture(RingBTexture);
		}
	}
	RingB.setPosition(position.x - 80, position.y - 45);
	preFireRate = fireRateCost;

	static int preSlot;
	if (SlotCost != 15)		//10是初始cost
	{
		if (SlotCost != preSlot)
		{
			Slotcount++;
			RingCTexture.loadFromFile("Media/Textures/RingC" + toString(Slotcount) + ".png");
			RingC.setTexture(RingCTexture);
		}
	}
	RingC.setPosition(position.x - 130, position.y +30);
	preSlot = SlotCost;
}