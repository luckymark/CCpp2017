#ifndef _WORD_NODE_H_
#define _WORD_NODE_H_

#include <string>
#include "cocos2d.h"
#include "tinyxml\tinyxml.h"

class WordNode
{
public:
	void init(TiXmlNode *node);

	bool getAnchor();

	const char* getIcon();

	const char* getName();

	const char* getContent();

	std::string getContentByLength(int length);

	int getContentLength();

private:

	int contentLeght;

	bool anchor;

	std::string icon;

	std::string name;

	std::string content;
};
#endif // !_WORD_NODE_H_
