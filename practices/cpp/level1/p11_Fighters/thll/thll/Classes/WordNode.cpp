#include "WordNode.h"

USING_NS_CC;

void WordNode::init(TiXmlNode *node)
{
	TiXmlElement *element = node->ToElement();

	int intValue;
	if (element->QueryIntAttribute("anchor", &intValue) == TIXML_SUCCESS)
	{
		anchor = intValue;
	}
	else
	{
		anchor = false;
	}

	name = element->Attribute("name");
	icon = element->Attribute("icon");
	content = element->Attribute("content");
	contentLeght = 0;

	int length = content.length();
	int i = 0;
	while (i < length)
	{
		char ch = getContent()[i];
		if (ch > -127 && ch< 0)
		{
			// for chinese 
			i += 3;
		}
		else
		{
			i++;
		}
		contentLeght++;
	}
}

int WordNode::getContentLength()
{
	return contentLeght;
}

std::string WordNode::getContentByLength(int length)
{
	if (length >= contentLeght)
	{
		return getContent();
	}
	int i = 0;
	int index = 0;
	while (index < length)
	{
		char ch = getContent()[i];

		if (ch > -127 && ch < 0)
		{
			i += 3;
		}
		else
		{
			i++;
		}
		index++;
	}

	std::string str = content.substr(0, i);
	return str;
}

bool WordNode::getAnchor() 
{ 
	return anchor; 
};

const char* WordNode::getIcon() 
{ 
	return icon.c_str(); 
};

const char* WordNode::getName() 
{
	return name.c_str(); 
};

const char* WordNode::getContent() {
	return content.c_str(); 
};



