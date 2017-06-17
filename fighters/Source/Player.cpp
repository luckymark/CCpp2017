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
	mKeyBinding[sf::Keyboard::Right] = GetMissileORUpgradeFire;		//设法给一个键绑定两个功能
	mKeyBinding[sf::Keyboard::Left] = GetHpOrFirePile;
	mKeyBinding[sf::Keyboard::Down] = CloseMenu;
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
		// Check if pressed key appears in key binding, trigger command if so, 若按键被绑定了事件，将该事件压入待执行事件队列
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

void Player::initializeActions()		//载入函数，将commands与对应函数关联
{
	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-1, 0));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+1, 0));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0, -1));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0, +1));
	mActionBinding[Fire].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.fire(); });
	mActionBinding[LaunchMissile].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.launchMissile(); });

	mActionBinding[EMenu].action = derivedAction<Aircraft>([](Aircraft& a,sf::Time) {a.openEMenu(); });
	mActionBinding[QMenu].action= derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.openQMenu(); });
	mActionBinding[CloseMenu].action= derivedAction<Aircraft>([](Aircraft& a, sf::Time) {a.closeMenu(); });
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
	case EMenu:
	case QMenu:
//	case GetMissileANDUpgradeFire:
		return true;

	default:
		return false;
	}
}
