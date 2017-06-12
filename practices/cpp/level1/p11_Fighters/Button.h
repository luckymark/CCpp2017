#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_
#include "Component.h"
#include "YOUneedTHIS.h"
#include "Foreach.h"
#include "SounderPlayer.h"
namespace GUI
{
	class Button :public GUI::Component
	{
	public:
		typedef std::shared_ptr<Button>	Ptr;
		typedef std::function<void()> Callback;


	public:
		Button(const FontHolder& fonts, const TextureHolder& textures);

		void setCallback(Callback callback);
		void setText(const std::string& text);
		void setToggle(bool flag);

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();

		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent(const sf::Event& event);


	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		Callback mCallback;
		const sf::Texture& mNormalTexture;
		const sf::Texture& mSelectedTexture;
		const sf::Texture& mPressedTexture;
		sf::Sprite mSprite;
		sf::Text mText;
		bool mIsToggle;
		;
	};
}
#endif // !BUTTON_H_
