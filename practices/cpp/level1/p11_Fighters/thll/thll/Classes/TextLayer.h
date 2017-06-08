#ifndef _TEXT_LAYER_H_
#define _TEXT_LAYER_H_

#include "cocos2d.h"
#include "WordNode.h"
#include <vector>

class TextLayer :public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene(cocos2d::RenderTexture* sqr);

	static TextLayer* create();

	virtual bool init();

	virtual void onEnterTransitionDidFinish();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void readXml(std::string filename);

	void logic(float ctime);

private:
	std::vector<WordNode* > textList;

	cocos2d::LabelTTF* label;

	cocos2d::LabelTTF* labelLower;

	int textCount;

	int wordCount = 0;

	int textIndex = 0;

	bool isAvatarSetting = false;

	bool isTextOver = false;
};
#endif // !_TEXT_LAYER_H_

