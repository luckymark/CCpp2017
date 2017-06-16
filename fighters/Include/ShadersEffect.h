#ifndef SHADERS_H_
#define SHADERS_H_

#include "PostEffect.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <array>

class ShadersEffect : public  PostEffect
{
public:
	ShadersEffect();

	virtual void		apply(const sf::RenderTexture& input, sf::RenderTarget& output);


private:
	typedef std::array<sf::RenderTexture, 2> RenderTextureArray;


private:
	void				prepareTextures(sf::Vector2u size);

	void				filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				blurMultipass(RenderTextureArray& renderTextures);
	void				blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
	void				downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& target);


private:
	ShaderHolder		mShaders;

	sf::RenderTexture	mBrightnessTexture;
	RenderTextureArray	mFirstPassTextures;
	RenderTextureArray	mSecondPassTextures;
};

#endif // !SHADERS_H_

#pragma once
