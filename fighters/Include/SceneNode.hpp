#ifndef BOOK_SCENENODE_HPP
#define BOOK_SCENENODE_HPP

#include"Category.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <set>
#include <memory>
#include <utility>

struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	friend  class Aircraft;
	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;


public:
	explicit				SceneNode(Category::Type category = Category::None);

	void					attachChild(Ptr child);
	Ptr						detachChild(const SceneNode& node);

	void					update(sf::Time dt, CommandQueue& commands);
	void					update(sf::Time dt);
	virtual void			updateFlash(sf::Time dt);
	virtual bool			toRemove();

	sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const; 

	void					onCommand(const Command& command, sf::Time dt);		//执行对应指令
	virtual unsigned int	getCategory() const;

	void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
	void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void					removeWrecks();
	void					removeBlooms();
	virtual sf::FloatRect	getBoundingRect() const;
	virtual bool			isMarkedForRemoval() const;
	virtual bool			isDestroyed() const;
	virtual bool			toRemove()const;


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	void					updateChildren(sf::Time dt, CommandQueue& commands);

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;


private:

	SceneNode*				mParent;
	Category::Type			mDefaultCategory;
public:
	std::vector<Ptr>		mChildren;
};

bool	collision(const SceneNode& lhs, const SceneNode& rhs);
float	distance(const SceneNode& lhs, const SceneNode& rhs);

#endif // BOOK_SCENENODE_HPP
