#pragma once
#include <string>
#include <iostream>
#define quantity 5

using namespace std;

struct Shape
{
	string		name;
	string		characters;

};

class Canvas
{
private:

public:
	int		Count = 0;
	void	Add(struct Shape s[quantity]);
	void	Draw(struct Shape s[quantity]);
};