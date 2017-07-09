#include "Include\Player.hpp"
#include "Include\CommandQueue.hpp"
#include "Include\Aircraft.hpp"
#include "Include\Foreach.hpp"

#include <map>
#include <string>
#include <algorithm>

using namespace std::placeholders;

struct AircraftMover
{
	AircraftMover(float vx, float vy)
	: velocity(vx, vy)
	{
	};

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		aircraft.accelerate(velocity * aircraft.getMaxSpeed());
	}
	sf::Vector2f velocity;
	
};

Player::Player()
	:playerAlive(true)
	, RaptorPoint(2)
	, AvengerPoint(3)
	, EaglePoint(5)
	, RaptorScore(10)
	, AvengerScore(15)
	, EagleScore(25)

//	: mCurrentMissionStatus(MissionRunning)
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::A] = MoveLeft;
	mKeyBinding[sf::Keyboard::D] = MoveRight;
	mKeyBinding[sf::Keyboard::W] = MoveUp;
	mKeyBinding[sf::Keyboard::S] = MoveDown;
	mKeyBinding[sf::Keyboard::Up] = Fire;
	mKeyBinding[sf::Keyboard::Space ] = LaunchMissile;
	mKeyBinding[sf::Keyboard::Q] = QMenu;
	mKeyBinding[sf::Keyboard::E] = EMenu,
	mKeyBinding[sf::Keyboard::Right] = GetMissileORUpgradeFire;		//�跨��һ��������������
	mKeyBinding[sf::Keyboard::Left] = GetHpOrFirePile;
	mKeyBinding[sf::Keyboard::Down] = CloseMenuOrUpgradeMissileSlot;
	mKeyBinding[sf::Keyboard::Num1] = Continue;
	mKeyBinding[sf::Keyboard::Num2] = Restart;
	mKeyBinding[sf::Keyboard::Num3] = Exit;

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	FOREACH(auto& pair, mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so, �������������¼��������¼�ѹ���ִ���¼�����
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue & commands)
{
	// Traverse all assigned keys and check if they are pressed
	FOREACH(auto pair, mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}


void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

bool Player::isPlayerAlive()
{
	return playerAlive;
}

void Player::setPlayerDead()
{
	playerAlive = false;
}

void Player::setPlayerAlive()
{
	playerAlive = true;
}

void Player::gameContinue()
{
	if (mAircraft->reborn());

}

void Player::Reborn()
{
	mAircraft->reborn();
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()		//���뺯������commands���Ӧ��������
{
	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-1, 0));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+1, 0));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0, -1));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0, +1));
	mActionBinding[Fire].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.fire(); });
	mActionBinding[LaunchMissile].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.launchMissile(); });

	mActionBinding[EMenu].action = derivedAction<Aircraft>([](Aircraft& a,sf::Time) {a.openEMenu(); });
	mActionBinding[QMenu].action= derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.openQMenu(); });
	mActionBinding[CloseMenuOrUpgradeMissileSlot].action= derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.closeMenuOrUpgradeMissileSlot(); });
	mActionBinding[GetMissileORUpgradeFire].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.GetMissileORUpgradeFire(); });
	mActionBinding[GetHpOrFirePile].action= derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.GetHpOrFirePile(); });

	mActionBinding[Continue].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.reborn(); });
	mActionBinding[Restart].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.restart(); });
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
	case Fire:
//	case EMenu:
//	case QMenu:
//	case GetMissileANDUpgradeFire:
		return true;

	default:
		return false;
	}
}
