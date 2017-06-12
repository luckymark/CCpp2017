#include "Label.h"
#include "Utility.h"
GUI::Label::Label(const std::string & text, const FontHolder & fonts):mText(text,fonts.get(Fonts::Main),16)
{
}

bool GUI::Label::isSelectable() const
{
	return false;
}

void GUI::Label::setText(const std::string & text)
{
	mText.setString(text);
}

void GUI::Label::handleEvent(const sf::Event & event)
{
	//do nothing by default
}

void GUI::Label::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mText,states);
}
