#pragma once
#ifndef GAMEOVERSTATE_H_
#define GAMEOVERSTATE_H_
#include "StateIdentifiers.h"
#include "State.h"
#include "StateStack.h"
#include "Container.h"
#include "YOUneedTHIS.h"
#include "World.h"
#include "Player.h"
class GameOverState : public State
{
	public:
		GameOverState(StateStack& stack, Context context);

		virtual void draw();
		virtual bool update(sf::Time dt);
		virtual bool handleEvent(const sf::Event& event);


	private:
		sf::Text mGameOverText;
		sf::Time mElapsedTime;
	};
#endif // !GAMEOVERSTATE_H_
