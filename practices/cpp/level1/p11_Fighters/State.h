#ifndef STATE_H_
#define STATE_H_

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>

namespace sf
{
	class RenderWindow;
}

class StateStack;
class Player;
class MusicPlayer;
class SoundPlayer;

class State
{
	public:
		typedef std::unique_ptr<State> Ptr;

		struct Context
		{
								Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player,
									MusicPlayer& music, SoundPlayer& sounds);

			sf::RenderWindow*	window;
			TextureHolder*		textures;
			FontHolder*			fonts;
			Player*				player;
			MusicPlayer*		music;
			SoundPlayer*		sounds;
		};

							State(StateStack& stack, Context context);
		virtual				~State();

		virtual void		draw() = 0;
		virtual bool		update(sf::Time dt) = 0;
		virtual bool		handleEvent(const sf::Event& event) = 0;

	protected:
		void				requestStackPush(States::ID stateID);
		void				requestStackPop();
		void				requestStateClear();

		Context				getContext() const;

	private:
		StateStack*			mStack;
		Context				mContext;
};

#endif // STATE_H_
