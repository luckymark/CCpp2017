#ifndef BLOOMEFFECT_H_
#define BLOOMEFFECT_H_

#include "PostEffect.h"
#include "ResourceIdentifiers.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include <array>

class BloomEffect : public PostEffect
{
	public:
							BloomEffect();
		virtual void		apply(const sf::RenderTexture& input, sf::RenderTarget& output);

	private:
		typedef std::array<sf::RenderTexture, 2> RenderTextureArray;
		void				prepareTextures(sf::Vector2u size);
		void				filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
		void				blurMultipass(RenderTextureArray& renderTextures);
		void				blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
		void				downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
		void				add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& target);

		ShaderHolder		mShaders;
		sf::RenderTexture	mBrightnessTexture;
		RenderTextureArray	mFirstPassTextures;
		RenderTextureArray	mSecondPassTextures;
};

#endif // BLOOMEFFECT_H_
