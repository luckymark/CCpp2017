#include "FO.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
void FO::crash()
{
	;
}

FO::FO()
{
	staticFrame = 0;
	dynamicFrame = 0;
	width = 48;
	height = 72;
	speed = 10.0;
}

FO::FO(int flag)
{
	staticFrame = 0;
	dynamicFrame = 0;

	switch (flag)
	{
	case 1://player
		width = 48;
		height = 72;
		speed = 10.0;
		break;
	case 2://sButterfly
		width = 32;
		height = 32;
		break;
	case 3://sElf
		width = 48;
		height = 32;
		break;
	case 4://mElf
		width = 48;
		height = 48;
		break;
	case 5://mButterfly
		width = 64;
		height = 64;
		break;

}
	}
	

FO::~FO()
{
}
