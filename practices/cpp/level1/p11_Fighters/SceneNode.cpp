#include "SceneNode.h"

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
