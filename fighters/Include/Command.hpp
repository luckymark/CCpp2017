#ifndef BOOK_COMMAND_HPP
#define BOOK_COMMAND_HPP

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


class SceneNode;
class Player;

struct Command
{
												Command();

	std::function<void(SceneNode&, sf::Time)>	action;
	std::function<void(Player&, sf::Time)>		option;
	unsigned int								category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
	return [=] (SceneNode& node, sf::Time dt)
	{
		// Check if cast is safe
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		// Downcast node and invoke function on it
		fn(static_cast<GameObject&>(node), dt);
	};
}


#endif // BOOK_COMMAND_HPP
