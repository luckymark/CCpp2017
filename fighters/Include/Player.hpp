#ifndef BOOK_PLAYER_HPP
#define BOOK_PLAYER_HPP

#include "Command.hpp"
#include"Aircraft.hpp"

#include <SFML/Window/Event.hpp>

#include <map>


class CommandQueue;

class Player
{
	public:
		enum Action
		{
			MoveLeft,
			MoveRight,
			MoveUp,
			MoveDown,
			LaunchMissile,
			Fire,
			EMenu,
			QMenu,
			CloseMenuOrUpgradeMissileSlot,
			GetMissileORUpgradeFire,
			GetHpOrFirePile,
			Restart,
			Continue,
			Exit,
			ActionCount,
		};


	public:
		int										RaptorPoint;
		int										AvengerPoint;
		int										EaglePoint;
		int										RaptorScore;
		int										AvengerScore;
		int										EagleScore;

								Player();

								void					handleEvent(const sf::Event& event, CommandQueue& commands);
		void					handleRealtimeInput(CommandQueue& commands);

		void					assignKey(Action action, sf::Keyboard::Key key);
		sf::Keyboard::Key		getAssignedKey(Action action) const;

		bool					isPlayerAlive();
		void					setPlayerDead();
		void					setPlayerAlive();
		void					gameContinue();
		void					Reborn();
		Aircraft*                               mAircraft;
	private:
		void					initializeActions();
		static bool				isRealtimeAction(Action action);


	private:
		bool									playerAlive;
		std::map<sf::Keyboard::Key, Action>		mKeyBinding;
		std::map<Action, Command>				mActionBinding;

};

#endif // BOOK_PLAYER_HPP
