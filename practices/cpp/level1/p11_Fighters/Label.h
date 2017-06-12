#pragma once
#ifndef LABEL_H_
#define LABEL_H_
#include"Component.h"
#include"YOUneedTHIS.h"
#include"Foreach.h"
namespace GUI
{
	class Label :public GUI::Component
	{
	public:
		typedef std::shared_ptr<Label> Ptr;
	public:
		Label(const std::string& text, const FontHolder& fonts);

		virtual bool isSelectable() const;
		void setText(const std::string& text);

		virtual void handleEvent(const sf::Event& event);


	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		sf::Text mText;
	};
}
#endif // !LABEL_H_
