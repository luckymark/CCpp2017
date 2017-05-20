#include "SelfPlane.h"

USING_NS_CC;

SelfPlane* SelfPlane::create(const char* fileName)
{
	SelfPlane* plane = new SelfPlane();

	if (plane && plane->initWithFile(fileName))
	{
		plane->autorelease();
		return plane;
	}

	CC_SAFE_DELETE(plane);
	return nullptr;
}