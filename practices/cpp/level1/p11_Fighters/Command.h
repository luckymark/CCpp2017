#pragma once
#include "Category.h"

#include <SFML\System\Time.hpp>

#include <functional>
#include <cassert>

class SceneNode;

struct Command
{
	typedef std::function<void(SceneNode&, sf::Time)> Action;

	Command();

	Action						action;
	unsigned int				category;
};

template <typename GameObject, typename Function>
Command::Action derivedAction(Function fn)
{
	return [=](SceneNode& node, sf::Time dt)
	{
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		fn(static_cast<GameObject&>(node), dt);
	};
}