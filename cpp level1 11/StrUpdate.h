#pragma once
#include "stdafx.h"
#include "game.h"
#include "string"
#include "sstream"

class StrUpdate
{
public:
	static int life;
	static int score;
	static int upper;
	static int range;
	static void update();
	static std::string NumToStr(int i);
	static int level;
};