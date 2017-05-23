#pragma once
#ifndef SCENENODE_H_
#define SCENENODE_H_
#include"YOUneedTHIS.h"

class SceneNode:public sf::Transformable,public sf::Drawable//,private sf::NonCopyable
{	
public:
	typedef std::unique_ptr<SceneNode> Ptr;
private:
	std::vector<Ptr> mChildren;
	SceneNode * mParent;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;
	void update(sf::Time dt);
};
typedef std::unique_ptr<SceneNode> Ptr;
#endif // !SCENENODE_H_