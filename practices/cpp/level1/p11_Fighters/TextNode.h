#ifndef TEXTNODE_H_
#define TEXTNODE_H_

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include <SFML/Graphics.hpp>

class TextNode : public SceneNode
{
	public:
		explicit			TextNode(const FontHolder& fonts, const std::string& text);

		void				setString(const std::string& text);

	private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		sf::Text			mText;
};

#endif // TEXTNODE_H_
