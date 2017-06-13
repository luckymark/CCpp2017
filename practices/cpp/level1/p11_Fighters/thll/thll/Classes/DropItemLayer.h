#ifndef _DROP_ITEM_LAYER_H_
#define _DROP_ITEM_LAYER_H_

#define DROP_TYPE_1_TAG 11
#define DROP_TYPE_2_TAG 22

#include "cocos2d.h"

class DropItemLayer : public cocos2d::Layer
{
public:
	static DropItemLayer* create();

	static DropItemLayer* sharedDropItemLayer;

	virtual bool init();

	void createDrop();

	void addDrop(cocos2d::Sprite *sprite);

	void dropMove();

	cocos2d::Vector<cocos2d::Sprite*> getDropList();

	void removeDrop(cocos2d::Sprite *sprite);
private:

	cocos2d::Vector<cocos2d::Sprite*> dropList;

};
#endif // !_DROP_ITEM_LAYER_H_

