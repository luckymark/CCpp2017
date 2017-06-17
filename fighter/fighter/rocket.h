#pragma once
class Object_manage;
class rocket
{
public:
	rocket();
	friend class Object_manage;
	~rocket();
private:
	string filename;
    Texture image;
	Sprite sprite;
	int height;
};

