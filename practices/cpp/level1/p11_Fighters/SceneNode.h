#pragma once
#ifndef SCENENODE_H_
#define SCENENODE_H_
#include"YOUneedTHIS.h"

class SceneNode
{	
public:
	typedef std::unique_ptr<SceneNode> Ptr;
private:
	std::vector<Ptr> mChildren;
	SceneNode * mParent;
public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
};
typedef std::unique_ptr<SceneNode> Ptr;
#endif // !SCENENODE_H_