#pragma once
#ifndef POSTEFFECT_H_
#define POSTEFFECT_H_
#include "YOUneedTHIS.h"
class PostEffect
{
public:
	virtual ~PostEffect() {};
	virtual void apply(const sf::RenderTexture& input, sf::RenderTarget& output) = 0;
	static bool isSupported();
protected:
	static void applyShader(const sf::Shader& shader, sf::RenderTarget& output);
};
#endif // !POSTEFFECT_H_
