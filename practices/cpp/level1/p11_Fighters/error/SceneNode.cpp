#include "SceneNode.h"

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(states);
}

void SceneNode::drawChildren(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
	{
		(*itr)->draw(target, states);
	}
}

void SceneNode::updateCurrent(sf::Time dt)
{
	//
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
	{
		(*itr)->update(dt);
	}
}

SceneNode::SceneNode()
{
	mParent = NULL;
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

Ptr SceneNode::detachChild(const SceneNode & node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p)->bool {return p.get() == &node; });
	Ptr result = std::move(*found);
	result->mParent = NULL;
	mChildren.erase(found);
	return result;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();;
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}
