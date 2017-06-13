#include "TextLayer.h"

USING_NS_CC;

Scene* TextLayer::createScene(RenderTexture* sqr)
{
	auto scene = Scene::create();

	auto layer = TextLayer::create();

	scene->addChild(layer,2);

	Size visibleSize = Director::sharedDirector()->getVisibleSize();

	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());

	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); 

	back_spr->setFlipY(true);           

	back_spr->setColor(Color3B::GRAY); 

	scene->addChild(back_spr,0);

	return scene;
}

TextLayer* TextLayer::create()
{
	TextLayer* pRet = new TextLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool TextLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(TextLayer::onKeyPressed, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(TextLayer::logic), 0.5);

	return true;
}

void TextLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	WordNode* node = (WordNode*)textList[textIndex];

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (wordCount > node->getContentLength())
		{
			if (avatar != nullptr)
			{
 				avatar->removeFromParent();
			}
			isAvatarSetting = false;

			if (!isTextOver)
			{
				wordCount = 0;
				textIndex++;
				if (textIndex == textList.size() - 1)
				{
					isTextOver = true;
				}
			}
			else
			{
				Director::sharedDirector()->popScene();
			}
		}
		else
		{
			wordCount = node->getContentLength() + 1;
		}
	}
}

void TextLayer::onEnterTransitionDidFinish()
{
	auto visibleSize = Director::sharedDirector()->getVisibleSize();

	label = LabelTTF::create();
	label->setColor(Color3B::WHITE);
	label->setFontSize(36);
	label->setDimensions(Size(visibleSize.width, 160));
	label->setPosition(Vec2(visibleSize.width / 2, 80));
	this->addChild(label,2);

	labelUpper = LabelTTF::create();
	labelUpper->setColor(Color3B::WHITE);
	labelUpper->setFontSize(16);
	labelUpper->setAnchorPoint(Vec2(0, 1));
	labelUpper->setPosition(Vec2(0, 200));
	this->addChild(labelUpper, 2);

	labelLower = LabelTTF::create();
	labelLower->setColor(Color3B::WHITE);
	labelLower->setFontSize(20);
	labelLower->setPosition(Vec2(visibleSize.width - 160, 80));
	this->addChild(labelLower,2);

	/*auto layerColor = LayerColor::create();
	layerColor->setColor(Color3B::WHITE);
	layerColor->setOpacity(150);
	layerColor->setContentSize(Size(visibleSize.width, visibleSize.height / 4.0));*/
	auto layerText = Sprite::create("text/icon/text_box.png");
	layerText->setOpacity(200);
	layerText->setPosition(Vec2(layerText->getContentSize().width / 2, layerText->getContentSize().height));
	this->addChild(layerText,1);

	readXml("/text/text1.xml");

}

void TextLayer::readXml(std::string filename)
{
	ssize_t filesize;
	std::string path = FileUtils::sharedFileUtils()->fullPathForFilename(filename);
	char *buffer = (char *)FileUtils::sharedFileUtils()->getFileData(path, "rb", &filesize);


	if (buffer == NULL)
	{
		return;
	}

	TiXmlDocument doc;
	doc.Parse(buffer);
	TiXmlNode *root = doc.FirstChild("plist");

	if (root)
	{
		TiXmlElement *element = root->ToElement();
		for (TiXmlNode* entityNode = root->FirstChild(); entityNode; entityNode = entityNode->NextSibling())
		{
			WordNode *node = new WordNode();
			node->init(entityNode);
			textList.push_back(node);
		}
		textCount = textList.size();
	}
}

void TextLayer::logic(float cTime)
{
	auto visibleSize = Director::sharedDirector()->getVisibleSize();

	WordNode* node = (WordNode*)textList[textIndex];

	if (node->getAnchor() == 0)
	{
		if (!isAvatarSetting)
		{
			avatar = Sprite::create(node->getIcon());
			avatar->setPosition(Vec2(avatar->getContentSize().width/2.0, visibleSize.height / 4.0 + avatar->getContentSize().height / 2.0));
			this->addChild(avatar);
			isAvatarSetting = true;
		}
		if (wordCount > node->getContentLength())
		{
			label->setString(node->getContentByLength(wordCount));
			labelUpper->setString(node->getName());
			labelUpper->setAnchorPoint(Vec2(0, 1));
			labelUpper->setPosition(Vec2(0, 200));

			
			if (!isTextOver)
			{
				labelLower->setString("space to continue");
			}
			else
			{
				labelLower->setString("space to end");
			}
			return;
		}
		label->setString(node->getContentByLength(wordCount));
		labelLower->setString("");
		labelUpper->setString(node->getName());
		labelUpper->setAnchorPoint(Vec2(0, 1));
		labelUpper->setPosition(Vec2(0, 200));
		wordCount++;
	}
	else
	{
		if (!isAvatarSetting)
		{
			avatar = Sprite::create(node->getIcon());
			avatar->setPosition(Vec2(visibleSize.width - avatar->getContentSize().width / 2.0, visibleSize.height / 4.0 + avatar->getContentSize().height / 2.0));
			this->addChild(avatar);
			isAvatarSetting = true;
		}
		if (wordCount > node->getContentLength())
		{
			label->setString(node->getContentByLength(wordCount));
			labelUpper->setString(node->getName());
			labelUpper->setAnchorPoint(Vec2(1, 1));
			labelUpper->setPosition(Vec2(visibleSize.width, 200));

			//isAvatarSetting = false;

			if (!isTextOver)
			{
				labelLower->setString("space to continue");
			}
			else
			{
				labelLower->setString("space to end");
			}
			return;
		}
		label->setString(node->getContentByLength(wordCount));
		labelLower->setString("");
		labelUpper->setString(node->getName());
		labelUpper->setAnchorPoint(Vec2(1, 1));
		labelUpper->setPosition(Vec2(visibleSize.width, 200));
		wordCount++;
	}


}